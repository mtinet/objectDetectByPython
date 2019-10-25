import serial
arduino = serial.Serial('/dev/cu.usbmodem141301', 9600)

while(True):
    a=arduino.readline()
    print(a)
    a = a.decode()
    print(a)
    print('')
