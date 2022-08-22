from machine import Pin, ADC
from utime import sleep_ms

# set input pin
left_ir = ADC(28)
right_ir = ADC(27)
conversion_factor = 3.3 / 65535

while True:
    left_ir_val =  round((left_ir.read_u16() * conversion_factor),2)
    right_ir_val = round((right_ir.read_u16() * conversion_factor),2)
    
    print("%s \t\t %s" %(left_ir_val, right_ir_val))
    sleep_ms(200)