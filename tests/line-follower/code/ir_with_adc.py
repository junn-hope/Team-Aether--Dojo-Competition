from machine import Pin, ADC
from utime import sleep_ms

# set input pin
right_ir = ADC(26)
left_ir = ADC(27)
conversion_factor = 3.3 / 65535

while True:
    left_ir_val =  left_ir.read_u16()
    right_ir_val = right_ir.read_u16()
    
    print("L: %s \t\t R: %s" %(left_ir_val, right_ir_val))
    sleep_ms(200)