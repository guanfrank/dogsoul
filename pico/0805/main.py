import machine
import time

# Set up UART1 with the appropriate baud rate and pins.
uart1 = machine.UART(1, baudrate=9600, tx=machine.Pin(4), rx=machine.Pin(5))

def read_char_from_uart(uart):
    while not uart.any():
        pass
    return uart.read(1)

def write_char_to_uart(uart, char):
    uart.write(char)
#    uart.flush()
move_const = 1200
middle = 2500

pwm_l = machine.PWM(machine.Pin(14))
pwm_r = machine.PWM(machine.Pin(16))
pwm_r.freq(50)
while True:
    try:
        # Read a character from UART1
        received_char = read_char_from_uart(uart1).decode("utf-8")
        print("Received character:", received_char)
        if received_char == 'F' or received_char == 's':
            # forward
            pwm_l.duty_u16(middle - move_const)
            pwm_r.duty_u16(middle + move_const)
        elif received_char == 'B' or received_char == 'w':
            print("Eee")
            pwm_r.duty_u16(middle - move_const)
            pwm_l.duty_u16(middle + move_const)
            # backward move
        elif received_char == "A":
            pwm_r.duty_u16(middle)
            # no move
        # Modify the received character (e.g., increment it)
        #modified_char = chr(ord(received_char) + 1)
        
        #print("Xmiting character:", modified_char)

        # Write the modified character back to UART1
        #write_char_to_uart(uart1, modified_char.encode('utf-8'))

        # Wait a bit to avoid flooding the UART
        # time.sleep_ms(100)

    except Exception as e:
        print("Error:", e)


