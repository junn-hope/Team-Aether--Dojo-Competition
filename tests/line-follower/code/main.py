from machine import Pin
from utime import sleep_ms

# set photo-transistor pin
photo_1 = Pin(1, Pin.OUT)

while True:
    photo_1.value(1)
    sleep_ms(200)
    photo_1.value(0)
    sleep_ms(200)
    
    