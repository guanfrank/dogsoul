import machine
import time

# Define motor pins
left_motor_pin1 = machine.Pin(10, machine.Pin.OUT)
left_motor_pin2 = machine.Pin(11, machine.Pin.OUT)
right_motor_pin1 = machine.Pin(20, machine.Pin.OUT)
right_motor_pin2 = machine.Pin(21, machine.Pin.OUT)

# Function to move the robot forward
def move_forward():
    left_motor_pin1.on()
    left_motor_pin2.off()
    right_motor_pin1.on()
    right_motor_pin2.off()

# Function to move the robot backward
def move_backward():
    left_motor_pin1.off()
    left_motor_pin2.on()
    right_motor_pin1.off()
    right_motor_pin2.on()

# Function to turn the robot left
def turn_left():
    left_motor_pin1.off()
    left_motor_pin2.on()
    right_motor_pin1.on()
    right_motor_pin2.off()
    
# Function to turn the robot right
def turn_right():
    left_motor_pin1.on()
    left_motor_pin2.off()
    right_motor_pin1.off()
    right_motor_pin2.on()
    
def stop():
    left_motor_pin1.off()
    left_motor_pin2.off()
    right_motor_pin1.off()
    right_motor_pin2.off()

# Set up UART1 with the appropriate baud rate and pins.
uart1 = machine.UART(1, baudrate=9600, tx=machine.Pin(4), rx=machine.Pin(5))
def read_char_from_uart(uart):
    while not uart.any():
        pass

    return uart.read(1)

def write_char_to_uart(uart, char):
    uart.write(char)
#    uart.flush()
# Main program
while True:   
    try:
        # Read a character from UART1
        received_char = read_char_from_uart(uart1)
        print("Received character:", received_char.decode('utf-8'))
        if recieved_char == 'F':
            # forward move
            move_forward()
            time.sleep(2)
        elif recieved_char == 'B':
            move_backward()
            time.sleep(2)
            # backward move
        else:
            stop()
            # no move
        # Modify the received character (e.g., increment it)
        #modified_char = chr(ord(received_char) + 1)
        
        #print("Xmiting character:", modified_char)

        # Write the modified character back to UART1
        #write_char_to_uart(uart1, modified_char.encode('utf-8'))

        # Wait a bit to avoid flooding the UART
        time.sleep_ms(100)

    except Exception as e:
        print("Error:", e)

    
    
    

    

    
#    turn_left()
#    time.sleep(1)
    
#    turn_right()
#    time.sleep(1)
