import serial

arduino = serial.Serial('/dev/cu.usbmodem141201', 9600)

while(1):
    c = input()
    print(type(c))          # 유니코드로 입력 받는다.
    c= (c+'\n').encode('utf-8')    # 유니코드 문자열을 바이트 문자열로 바꾼다.
    arduino.write(c)
    print(type(c))        # 시리얼 쓰기는 바이트만 가능하다.
    # sum = arduino.readline()
    # sum = sum.decode()
    # print(sum)
