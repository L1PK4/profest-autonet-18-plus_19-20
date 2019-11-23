import xbox
import serial

ser = serial.Serial('/dev/ttyUSB0',115200)
joy = xbox.Joystick()
while True:
    (x,y) = joy.leftStick()
    command = chr(int(abs(y * 255))) + chr(int(abs(x * 255))) + chr(((y > 0)*2 + (x > 0))) + '\n'
    ser.write(command)
