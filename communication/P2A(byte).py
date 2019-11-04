import serial
from time import sleep

#arduino = serial.Serial('/dev/cu.usbmodem141201', 9600)
arduino = serial.Serial('COM15', 9600)
c = 0

while(1):
    c += 1
    arduino.write([c])
    print(c)
    sleep(0.01)
    if(c == 255) :
        c = 0
