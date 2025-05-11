import can
import socket
import serial

def parse_uart_message(uart_message):
    try:
        parts = uart_message.split()
        frame_id = int(parts[1].replace("0x", ""), 16)
        dlc = int(parts[3].strip(":"))
        data = [int(byte.replace("0x", ""), 16) for byte in parts[5:5 + dlc]]
        return {
            'id': frame_id,
            'dlc': dlc,
            'data': data
        }
    except (IndexError, ValueError) as e:
        print(f"Nu s-a putut analiza mesajul UART: {uart_message}, Eroare: {e}")
        return None

def read_uart_and_send_to_vcan(uart_port, baudrate=115200):
    ser = None
    bus = None
    try:
        ser = serial.Serial(uart_port, baudrate, timeout=None)
        bus = can.interface.Bus(channel='vcan0', interface='socketcan', receive_own_messages=False)
        raw = bus.socket
        raw.setsockopt(socket.SOL_CAN_RAW, socket.CAN_RAW_LOOPBACK, 0)
        while True:
            uart_message = ser.readline().decode('utf-8', errors='ignore').strip()
            print(f"UART Primit: {uart_message}")
            frame = parse_uart_message(uart_message)
            if frame:
                message = can.Message(
                    arbitration_id=frame['id'],
                    data=frame['data'],
                    is_extended_id=False
                )
                bus.send(message)
                print(f"Trimis la vcan0: ID={frame['id']:03X}, DLC={frame['dlc']}, Data={frame['data']}")
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
    read_uart_and_send_to_vcan(uart_port='/dev/ttyUSB3', baudrate=115200)

