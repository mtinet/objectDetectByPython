# 아두이노에서 파이썬으로 문자열을 보내면 파이썬이 받은 상태와 디코드 한 상태를 보여줌  

import serial
arduino = serial.Serial('/dev/cu.usbmodem141301', 9600)

while(True):
    a=arduino.readline()
    print(a)
    a = a.decode()
    print(a)
    print('')
