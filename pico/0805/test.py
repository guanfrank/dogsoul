from machine import PWM, Pin
thingo = PWM(Pin(16))
thingo.freq(50)
thingo.duty_u16(2500)
