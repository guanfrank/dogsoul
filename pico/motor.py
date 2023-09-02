import machine
import time

# Define motor pins
MOTOR_PINS = {
    'left_motor_pin1': machine.Pin(10, machine.Pin.OUT),
    'left_motor_pin2': machine.Pin(11, machine.Pin.OUT),
    'right_motor_pin1': machine.Pin(20, machine.Pin.OUT),
    'right_motor_pin2': machine.Pin(21, machine.Pin.OUT),
}

# Function to control motors based on a command
def control_motors(command):
    if command == 'F':
        print("Moving forward")
        MOTOR_PINS['left_motor_pin1'].on()
        MOTOR_PINS['left_motor_pin2'].off()
        MOTOR_PINS['right_motor_pin1'].on()
        MOTOR_PINS['right_motor_pin2'].off()
    elif command == 'B':
        print("Moving backward")
        MOTOR_PINS['left_motor_pin1'].off()
        MOTOR_PINS['left_motor_pin2'].on()
        MOTOR_PINS['right_motor_pin1'].off()
        MOTOR_PINS['right_motor_pin2'].on()
    else:
        print("Stopping")
        for pin in MOTOR_PINS.values():
            pin.off()

# Set up UART1 with the appropriate baud rate and pins.
uart = machine.UART(1, baudrate=9600, tx=machine.Pin(4), rx=machine.Pin(5))

# Main program
try:
    while True:
        char = uart.read(1)
        if char is not None:
            received_command = char.decode('utf-8')
            print("Received command:", received_command)
            control_motors(received_command)
            time.sleep(2)
except Exception as e:
    print("Error:", e)
except KeyboardInterrupt:
    print("Exiting program.")
    for pin in MOTOR_PINS.values():
        pin.off()
