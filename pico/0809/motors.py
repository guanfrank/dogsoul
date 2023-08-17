from machine import Pin
import time
#DC MOTORS
class L9110Motor:
    def __init__(self,pin1,pin2):
        self.pin1 = Pin(pin1, Pin.OUT)
        self.pin2 = Pin(pin2, Pin.OUT)
        
    def forward(self): #clockwise works
        self.pin1.value(1)
        self.pin2.value(0)
    
    def some(self):
        self.pin1.value(1)
        self.pin2.value(1)
        
    def reverse(self): #not working
        self.pin1.value(0)
        self.pin2.value(1)
        
    def stop(self): #does stop    
        self.pin1.value(0)
        self.pin2.value(0)
        
class L9110Controller:
    def __init__(self, a_ia, a_ib, b_ia, b_ib):
        self.motorA = L9110Motor(a_ia, a_ib)
        self.motorB = L9110Motor(b_ia, b_ib)
        
controller = L9110Controller(11,10,21,20)
controller.motorB.forward()
#time.sleep(3)
#controller.motorB.stop()
#controller.motorB.reverse()
#time.sleep(3)
#controller.motorB.some()


#controller.motorA.stop()


        
