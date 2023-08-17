
from machine import Pin, UART, PWM
import utime


A1A = PWM(machine.Pin(10))
A1B = PWM(Pin(11))
B1A = PWM(Pin(20))
B1B = PWM(Pin(21))
def pulse(p1, p2, pp1, pp2,sp1, sp2,  time):
    p1.duty(sp1)
    p2.duty(sp2)
    pp1.duty(sp2)
    pp2.duty(sp1)
    utime.sleep_us(time)
    p1.duty(0)
    p2.duty(0)
    pp1.duty(0)
    pp2.duty(0)
# Set up UART1 with the appropriate baud rate and pins.
uart1 = UART(1, baudrate=9600, tx=Pin(4), rx=Pin(5))

def read_char_from_uart(uart):
    t = 0
    while not uart.any():
        
        t += 1
        pass
    return uart.read(1)

def write_char_to_uart(uart, char):
    uart.write(char)
    uart.flush()
while True:
    try:
        # Read a character from UART1
        received_char = read_char_from_uart(uart1)
        uart1.flush()
        print("Received character:", received_char.decode('utf-8'))
        
        # if received_char == 'F':
            # pulse(A1A, A1B, B1A, B1B, 0, 100, 100)
        # elif received_char == 'B':
            # pulse(A1A, A1B, B1A, B1B, 100, 0, 100)
        # Wait a bit to avoid flooding the UART
        # utime.sleep_ms(100)

    except Exception as e:
        print("Error:", e)
