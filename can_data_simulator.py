import can       
import random
import time

def generate_can_frame():
    id = random.randint(0, 2047)  # identificator de 11 biti
    dlc = random.randint(0, 8)    # Data Length Code
    data = [random.randint(0, 255) for _ in range(dlc)] #Data de pe magistrala
    timestamp = time.time()
    ctime = time.ctime(timestamp) #afiseaza data si ora 
    return {
        'ctime': ctime,
        'id': id,
        'dlc': dlc,
        'data': data
    }

#printeaza in terminal datele generate random mai sus, in intervalul precizat
def simulate_can_bus(interval=5):
    while True:
        frame = generate_can_frame()
        print(f"Frame: Time={frame['ctime']}, "
              f"ID={frame['id']:03X}, "
              f"DLC={frame['dlc']}, "
              f"Data={' '.join([f'{x:02X}' for x in frame['data']])}")
        yield frame
        time.sleep(interval)

def simulate_can_bus_to_vcan(duration=100):
    try:
        bus = can.interface.Bus(channel='vcan0', interface='socketcan')
        
        start_time = time.time()
        data_source = simulate_can_bus(interval=5)
        
        while time.time() - start_time < duration:
            frame = next(data_source)
            message = can.Message(arbitration_id=frame['id'], data=frame['data'], is_extended_id=False)
            bus.send(message)
            time.sleep(0.1)

    except KeyboardInterrupt:
        print("CTRL+C")
    finally:
        #Inchid busul dupa fiecare afisare de date, ca sa evit probleme 
        bus.shutdown()

if __name__ == "__main__":
    simulate_can_bus_to_vcan(duration=100)
