from machine import PWM, Pin
from time import sleep

class TwoServos:
    def __init__(self, servo1_pin, servo2_pin):
        print("setting up the servos")
        self.left_sm = PWM(Pin(servo1_pin))
        self.right_sm = PWM(Pin(servo2_pin))
        self.left_sm.freq(50)
        self.right_sm.freq(50)

    def stop(self):
        self.left_sm.duty_u16(2400)
        self.right_sm.duty_u16(2400)

    def forward(self):
        self.left_sm.duty_u16(2000)
        self.right_sm.duty_u16(3000)

    def reverse(self):
        self.left_sm.duty_u16(3000)
        self.right_sm.duty_u16(2000)
        
    def move(self):
        self.left_sm.duty_u16(Ldir)
        self.right_sm.duty_u16(Rdir)

"""
left_sm_range = range(2000,3000)
left_sm = PWM(Pin(15))
left_sm.freq(50)

def forward():
    left_sm.duty_u16(3000)
    
def slow():
    left_sm.duty_u16(1400)

def stop():
    left_sm.duty_u16(2500)
   
def what():
    pass

#one_sweep()
forward()
sleep(1)
slow()
sleep(1)
"""
thing = TwoServos(14,15)
thing.forward()