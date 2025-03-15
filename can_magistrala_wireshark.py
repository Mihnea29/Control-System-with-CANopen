import can
import serial

def parse_uart_message(uart_message):

    try:
        parts = uart_message.split()
        
        frame_id = int(parts[1].replace("0x", ""), 16)
        
        dlc = int(parts[3].strip(":"))
        
        data = [int(byte.replace("0x", ""), 16) for byte in parts[5:4 + dlc]]
        
        return {
            'id': frame_id,
            'dlc': dlc,
            'data': data
        }
    except (IndexError, ValueError) as e:
        print(f"Failed to parse UART message: {uart_message}, Error: {e}")
        return None

def read_uart_and_send_to_vcan(uart_port, baudrate=115200):

    try:
 
        ser = serial.Serial(uart_port, baudrate, timeout=1)

        bus = can.interface.Bus(channel='vcan0', interface='socketcan')

        while True:
            if ser.in_waiting > 0:  
                uart_message = ser.readline().decode('utf-8').strip()
                print(f"UART Received: {uart_message}")

                frame = parse_uart_message(uart_message)
                if frame:
                    message = can.Message(
                        arbitration_id=frame['id'],
                        data=frame['data'],
                        is_extended_id=False
                    )
                    bus.send(message)
                    print(f"Sent to CAN: ID={frame['id']:03X}, DLC={frame['dlc']}, Data={frame['data']}")
    except KeyboardInterrupt:
        print("CTRL+C")
    except Exception as e:
        print(f"An error occurred: {e}")
    finally:
        if 'ser' in locals() and ser.is_open:
            ser.close()
        if 'bus' in locals():
            bus.shutdown()

if __name__ == "__main__":
    read_uart_and_send_to_vcan(uart_port='/dev/ttyUSB0', baudrate=115200)
