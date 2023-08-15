from motor_servo import TwoServos

if __name__ == "__main__":
    try:
        servo1_pin = 15
        servo2_pin = 16
        servos = TwoServos(servo1_pin, servo2_pin)
        #Accessing properties
        print(f"Servo 1 object: {servos.left_sm}")
        print(f"Servo 2 object: {servos.right_sm}")
        #Using methods
        
    except KeyboardInterrupt:
        servos.stop()
        