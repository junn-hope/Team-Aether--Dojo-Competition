
from machine import Pin
from utime import sleep_ms

led = Pin(0, Pin.OUT)

while True:
    led.value(1)
    sleep_ms(1000)
    led.value(0)
    sleep_ms(1000)