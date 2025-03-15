CAN_Transmitter:
Face comunicarea intre doua placute, avand doua moduri de configurare: 
-TRANSMIT - un mesaj este pregatit si trimis pe magistrala CAN
-RECEIVE - mesajul trimis este receptionat si trimis pe UART

can_magsitrala_wireshark.py:
Face conexiunea dintre UART si canalul virtual vcan0.
Dupa ce conexiunea este realizata, datele receptionate pot fi vizualizate atat pe terminal cat si pe aplicatia wireshark.
