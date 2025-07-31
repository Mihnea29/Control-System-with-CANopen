# Automotive Control System with CANopen

<img width="926" height="526" alt="image" src="https://github.com/user-attachments/assets/b1c47cdc-992f-4ff7-9157-de5abc93271a" />

A distributed automotive control system prototype that implements the CANopen protocol on STM32 microcontrollers for managing various vehicle subsystems (lights, wipers) and graphic display.

## Overview

This project demonstrates a modern automotive electronic architecture using the CANopen protocol for inter-module communication. The system simulates real ECU (Electronic Control Unit) functionality found in modern vehicles.

<img width="2119" height="1420" alt="Picture1" src="https://github.com/user-attachments/assets/a1c95d20-64fc-4e4b-83f3-66b3956721d2" />

### Key Features

- **Distributed control architecture**: Multiple ECU nodes communicating via CANopen
- **Real-time monitoring**: Live CAN bus traffic analysis using Wireshark
- **TouchGFX interface**: For system control and status
- **Hardware integration**: Custom PCB design for CAN bus
- **Automotive-grade protocol**: Complete CANopen implementation with PDO/SDO support

## System Architecture

### Hardware Components

| Component | Role | Specifications |
|-----------|------|---------------|
| STM32F769I-Discovery | Coordinator node (BCM) | Cortex-M7, TouchGFX |
| STM32F429-Discovery | Execution nodes (ECU) | Cortex-M4, Multiple instances |
| STM32F407G-DISC1 | Monitoring node | Cortex-M4, UART Bridge |
| CAN Transceivers MCP2561 | Physical layer communication | Differential signaling |
| PCB | CAN Bus | 
| Servomotors | Wiper actuators | Precision PWM control |
| LED Arrays | Lighting indicators | Multiple channels |

### Software Stack

- **FreeRTOS**: Real-time operating system
- **CANopenNode**: Open-source CANopen stack
- **TouchGFX**: Professional GUI framework
- **STM32CubeIDE**: Development environment
- **SocketCAN + Wireshark**: CAN bus monitoring

## System Nodes

### 1. Coordinator Node (STM32F769I)

**Role**: Body Control Module (BCM) equivalent

**Functions**:
- Timestamp producer for system synchronization
- Network management and node monitoring
- Dynamic SDO configuration of remote nodes
- TouchGFX HMI for user interaction
- TPDO transmission for system control
 
<img width="960" height="644" alt="image" src="https://github.com/user-attachments/assets/a935c19f-6a2a-4ec3-a867-ad1142eab127" />

### 2. Lighting Control Module (Node 2)

**Role**: Exterior lighting ECU

**Functions**:
- Position lights, turn signals, high beam
- Flash functionality with priority management
- Timer-based alternation (0.75s for turn signals, 0.1s for flash)
- RPDO consumption for light state control

### 3. Wiper Control Module (Node 3)

**Role**: Windshield wiper system ECU

**Functions**:
- Servo-controlled wiper movement
- Variable speed control (2-speed system)
- Precision position control (PWM range 1000-2000μs)
- Gradual transitions to prevent mechanical stress

### 4. Display Terminal (Node 4)

**Role**: Information display and monitoring

**Functions**:
- Timestamp consumer with calendar conversion
- Heartbeat monitoring for all nodes
- TouchGFX interface for system status
- Real-time system state visualization

<img width="590" height="736" alt="image" src="https://github.com/user-attachments/assets/c323ec31-1f0e-43c5-ac61-72184fbddcfd" />

### 5. Monitoring Node (STM32F407G)

**Role**: Diagnostic instrument and analysis

**Functions**:
- Complete CAN bus traffic capture
- UART bridge to PC for Wireshark analysis
- Non-intrusive monitoring (listen-only mode)
- Real-time data logging

<img width="798" height="986" alt="image" src="https://github.com/user-attachments/assets/d67cbff9-448d-4f7c-9650-0db1e4bda081" />

## Development Setup

### Prerequisites

1. **STM32CubeIDE** - Primary development environment
2. **Ubuntu 22.04** (or any Linux distribution with SocketCAN)
3. **Wireshark** - For CAN bus analysis
4. **Wine** - For running CANopenEditor on Linux
5. **Python 3** with required libraries

### Installation Steps

#### 1. Clone the repository

```bash
git clone https://github.com/yourusername/canopen-automotive-system.git
cd canopen-automotive-system
```

#### 2. Download CANopenNode libraries

```bash
git clone https://github.com/CANopenNode/CANopenNode.git
git clone https://github.com/CANopenNode/CanOpenSTM32.git
```

#### 3. Install system dependencies

```bash
sudo apt update
sudo apt install python3 wireshark wine
```

#### 4. Install Python dependencies

```bash
pip3 install pyserial python-can
```

#### 5. Setup virtual CAN interface

```bash
sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link set up vcan0
```

#### 6. Download CANopenEditor

```bash
wget https://github.com/CANopenNode/CANopenEditor/releases/download/v4.2.3/CANopenEditor-build-v4.2.3-0-gc1071a1.zip
unzip CANopenEditor-build-v4.2.3-0-gc1071a1.zip
```

## Usage

### Compilation and Programming

1. Open STM32CubeIDE and import the project folders
2. Configure include paths to point to CANopenNode directories
3. Compile each node project separately
4. Program onto respective STM32 boards using ST-Link

### Running the Monitoring System

#### 1. Start the UART-to-CAN bridge

```bash
python3 scripts/can_bus_wireshark.py
```

#### 2. Launch Wireshark

```bash
wireshark
```

#### 3. Configure Wireshark

- Select the `vcan0` interface
- Apply CANopen dissector:
  - Right-click on Protocol column
  - Select "Decode As..." → "CANopen"

### System Operation

1. **Start all nodes** in sequence
2. **Coordinator node** will begin timestamp transmission
3. **Use TouchGFX interface** to control lighting and wiper systems
4. **Monitor real-time traffic** in Wireshark
5. **Observe actuator responses** on the physical model

## CAN Bus Configuration

| Parameter | Value |
|-----------|-------|
| **Baud Rate** | 100 kbps |
| **Frame Format** | Standard (11-bit) and Extended (29-bit) |
| **Termination** | 120Ω resistors at bus ends |
| **Topology** | Linear bus with differential signaling (CANH/CANL) |

## Monitoring and Debugging

### Real-time Analysis

- **Wireshark Integration**: Complete packet-level analysis
- **CANopen Dissector**: Automatic PDO/SDO/NMT decoding
- **Timestamp Correlation**: Synchronized logging across all nodes

### Hardware Debugging

- **SWD Interface**: Real-time debugging on all STM32 nodes
- **Logic Analyzer**: Digital signal analysis capabilities
- **Status LED Indicators**: Visual system state monitoring

## Project Structure

```
├── CANOpen_Node1/                  # Coordinator implementation 
├── CanOpen-STM32F429-SLAVE1/       # Exterior lighting ECU 
├── CanOpen-STM32F429-SLAVE2/       # Wiper ECU  
├── CanOpen-STM32F429-SLAVE3/       # Node information display
├── STM32F407_Bridge/               # Monitoring node
└── README.md
```

## Current Implementation

- **Automotive lighting control**: Position, turn signals, high beam, flash
- **Wiper system management**: Variable speed servo control
- **Real-time monitoring**: Complete system diagnostics
- **Human-machine interface**: TouchGFX-based control panel

## Lighting Demo

https://github.com/user-attachments/assets/905b185d-f67a-4171-b013-ccdfb30d7154

## Time Demo

https://github.com/user-attachments/assets/d5313a8e-7275-47bd-83d5-c225f1a954e4

