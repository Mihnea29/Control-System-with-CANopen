# Sistem de Control Automotive CANopen

Un prototip de sistem de control automotive distribuit care implementează protocolul CANopen pe microcontrolere STM32 pentru gestionarea diverselor subsisteme ale vehiculului (lumini, ștergătoare) și display grafic.

## Prezentare generală

Acest proiect demonstrează o arhitectură electronică automotive modernă utilizând protocolul CANopen pentru comunicația între module. Sistemul simulează funcționalitatea reală a ECU-urilor (Electronic Control Unit) regăsită în vehiculele moderne.

### Caracteristici principale

- **Arhitectură de control distribuită**: Multiple noduri ECU care comunică prin CANopen
- **Monitorizare în timp real**: Analiza live a traficului pe magistrala CAN folosind Wireshark
- **Interfață TouchGFX**: Pentru controlul și starea sistemului
- **Integrare hardware**: Design PCB personalizat pentru magistralea CAN
- **Protocol de nivel automotive**: Implementare completă CANopen cu suport PDO/SDO

## Arhitectura sistemului

### Componente hardware

| Componentă | Rol | Specificații |
|------------|-----|-------------|
| STM32F769I-Discovery | Nod coordonator (BCM) | Cortex-M7, TouchGFX |
| STM32F429-Discovery | Noduri de execuție (ECU) | Cortex-M4, Multiple instanțe |
| STM32F407G-DISC1 | Nod de monitorizare | Cortex-M4, Bridge UART |
| Transceivere CAN MCP2561 | Comunicație la nivel fizic | Semnalizare diferențială |
| PCB | Magistrală CAN | 
| Servomotoare | Actuatori ștergătoare | Control PWM precizie |
| Array-uri LED | Indicatori iluminat | Multiple canale |

### Stack software

- **FreeRTOS**: Sistem de operare în timp real
- **CANopenNode**: Stack CANopen open-source
- **TouchGFX**: Framework GUI profesional
- **STM32CubeIDE**: Mediu de dezvoltare
- **SocketCAN + Wireshark**: Monitorizare magistrală CAN

## Nodurile sistemului

### 1. Nod coordonator (STM32F769I)

**Rol**: Echivalent Body Control Module (BCM)

**Funcții**:
- Producător timestamp pentru sincronizarea sistemului
- Managementul rețelei și monitorizarea nodurilor
- Configurare SDO dinamică a nodurilor remote
- HMI TouchGFX pentru interacțiunea cu utilizatorul
- Transmisia TPDO pentru controlul sistemului

### 2. Modul control iluminat (Nodul 2)

**Rol**: ECU iluminat exterior

**Funcții**:
- Lumini de poziție, semnalizare, fază lungă
- Funcționalitate flash cu management de prioritate
- Alternare bazată pe timer (0.75s pentru semnalizare, 0.1s pentru flash)
- Consumul RPDO pentru controlul stării luminilor

### 3. Modul control ștergătoare (Nodul 3)

**Rol**: ECU sistem ștergătoare parbriz

**Funcții**:
- Mișcare ștergătoare controlată cu servo
- Control viteză variabilă (sistem cu 2 viteze)
- Control precizie poziție (range PWM 1000-2000μs)
- Tranziții graduale pentru prevenirea stresului mecanic

### 4. Terminal afișaj (Nodul 4)

**Rol**: Afișaj informații și monitorizare

**Funcții**:
- Consumer timestamp cu conversie calendar
- Monitorizare heartbeat pentru toate nodurile
- Interfață TouchGFX pentru starea sistemului
- Vizualizare în timp real a stării sistemului

### 5. Nod monitorizare (STM32F407G)

**Rol**: Instrument diagnostic și analiză

**Funcții**:
- Capturarea completă a traficului pe magistrala CAN
- Bridge UART către PC pentru analiza Wireshark
- Monitorizare non-intruzivă (mod doar ascultare)
- Logging date în timp real

## Setup pentru dezvoltare

### Cerințe preliminare

1. **STM32CubeIDE** - Mediul principal de dezvoltare
2. **Ubuntu 22.04** (sau orice distribuție Linux cu SocketCAN)
3. **Wireshark** - Pentru analiza magistralei CAN
4. **Wine** - Pentru rularea CANopenEditor pe Linux
5. **Python 3** cu bibliotecile necesare

### Pași de instalare

#### 1. Clonarea repository-ului

```bash
git clone https://github.com/yourusername/canopen-automotive-system.git
cd canopen-automotive-system
```

#### 2. Descărcarea bibliotecilor CANopenNode

```bash
git clone https://github.com/CANopenNode/CANopenNode.git
git clone https://github.com/CANopenNode/CanOpenSTM32.git
```

#### 3. Instalarea dependențelor de sistem

```bash
sudo apt update
sudo apt install python3 wireshark wine
```

#### 4. Instalarea dependențelor Python

```bash
pip3 install pyserial python-can
```

#### 5. Setup interfață CAN virtuală

```bash
sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link set up vcan0
```

#### 6. Descărcarea CANopenEditor

```bash
wget https://github.com/CANopenNode/CANopenEditor/releases/download/v4.2.3/CANopenEditor-build-v4.2.3-0-gc1071a1.zip
unzip CANopenEditor-build-v4.2.3-0-gc1071a1.zip
```

## Utilizare

### Compilare și programare

1. Deschideți STM32CubeIDE și importați folderele proiectului
2. Configurați căile include pentru a indica către directoarele CANopenNode
3. Compilați fiecare proiect de nod separat
4. Programați pe plăcile STM32 respective folosind ST-Link

### Rularea sistemului de monitorizare

#### 1. Pornirea bridge-ului UART-to-CAN

```bash
python3 scripts/can_magistrala_wireshark.py
```

#### 2. Lansarea Wireshark

```bash
wireshark
```

#### 3. Configurarea Wireshark

- Selectați interfața `vcan0`
- Aplicați dissector-ul CANopen:
  - Click dreapta pe coloana Protocol
  - Selectați "Decode As..." → "CANopen"

### Operarea sistemului

1. **Pornirea tuturor nodurilor** în secvență
2. **Nodul coordonator** va începe transmisia timestamp
3. **Folosirea interfeței TouchGFX** pentru controlul sistemelor de iluminat și ștergătoare
4. **Monitorizarea traficului în timp real** în Wireshark
5. **Observarea răspunsurilor actuatorilor** pe modelul fizic

## Configurația magistralei CAN

| Parametru | Valoare |
|-----------|---------|
| **Baud Rate** | 100 kbps |
| **Format cadru** | Standard (11-bit) și Extended (29-bit) |
| **Terminare** | Rezistoare de 120Ω la capetele magistralei |
| **Topologie** | Magistrală liniară cu semnalizare diferențială (CANH/CANL) |

## Monitorizare și depanare

### Analiza în timp real

- **Integrare Wireshark**: Analiză completă la nivel de pachet
- **Dissector CANopen**: Decodificare automată PDO/SDO/NMT
- **Corelația timestamp**: Logging sincronizat pe toate nodurile

### Depanare hardware

- **Interfață SWD**: Debugging în timp real pe toate nodurile STM32
- **Analizor logic**: Capabilități de analiză semnale digitale
- **Indicatori LED de stare**: Monitorizare vizuală starea sistemului

## Structura proiectului

```
├── CANOpen_Node1/                  # Implementare coordonator 
├── CanOpen-STM32F429-SLAVE1/       # ECU lumini exterior 
├── CanOpen-STM32F429-SLAVE2/       # ECU ștergătoare  
├── CanOpen-STM32F429-SLAVE3/       # Display cu informații despre nod
├── STM32F407_Bridge/               # Nod monitorizare
└── README.md
```
## Implementarea curentă

- **Control iluminat automotive**: Poziție, semnalizare, fază lungă, flash
- **Management sistem ștergătoare**: Control servo cu viteză variabilă
- **Monitorizare în timp real**: Diagnostice complete sistem
- **Interfață om-mașină**: Panou de control bazat pe TouchGFX
