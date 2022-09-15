from machine import Pin
from utime import sleep_ms

# infrared pins configuration
left_pin = Pin(1, Pin.IN)
right_pin = Pin(2, Pin.IN)

# motor pinout configuration
in1 = Pin(0, Pin.OUT)
in2 = Pin(1, Pin.OUT)
in3 = Pin(2, Pin.OUT)
in4 = Pin(3, Pin.OUT)

while True:
    # read left sensor
    left_ir = left_pin.value()
    
    # read right sensor
    right_ir = left_pin.value()
    
    sleep_ms(50)
    
    # check for line direction
    if((right_ir == 0) and (left_ir == 1)):
        # steer to the right
        print('turn right')
        in1.high()
        in2.low()
        in3.low()
        in4.low()
        sleep_ms(100)
        
    else if((right_ir == 1) and (left_ir == 0)):
        # steer to the left
        print('turn left')
        in1.low()
        in2.low()
        in3.high()
        in4.low()
        sleep_ms(100)
        
    else if((right_ir == 1) and (left_ir == 1)):
        # move forward
        print('move forward')
        in1.high()
        in2.low()
        in3.high()
        in4.low()
        sleep_ms(100)
        
    #else if(((right_ir == 0) and (left_ir == 0)) and (front_ir == 0)):
        # the bot is at a crossroad, continue moving forward
        #print('forward')
        #sleep_ms(100)
        
    else:
        # default move forward
        print('off')
        in1.low()
        in2.low()
        in3.low()
        in4.low()