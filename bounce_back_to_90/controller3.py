import serial
import time
import sys
import tty
import termios

ser = serial.Serial('/dev/ttyACM0', 115200) # replace '/dev/ttyACM0' with the name of your serial port

def getch():
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    try:
        tty.setraw(sys.stdin.fileno())
        ch = sys.stdin.read(1)
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
    return ch

try:
    count = 0
    while True:
        char = getch()
        if char == 'a':
            ser.write(b'a')
            print(179)
        elif char == 'd':
            ser.write(b'd')
            print(1)
        elif char == 'q':
            break
finally:
    ser.close()

