import serial
import matplotlib.pyplot as plt
from drawnow import *
import atexit

values = []

plt.ion()
cnt = 0

serialArduino = serial.Serial('COM5', 9600)


def plotvalues():
    plt.title('Serial value from Arduino')
    plt.grid(True)
    plt.ylabel('Values')
    plt.plot(values, 'rx-', label='values')
    plt.legend(loc='upper right')


def doatexit():
    serialArduino.close()
    print("Close serial")
    print("serialArduino.isOpen() = " + str(serialArduino.isOpen()))


atexit.register(doatexit)

print("serialArduino.isOpen() = " + str(serialArduino.isOpen()))

for i in range(0, 26):
    values.append(0)

while True:
    while serialArduino.inWaiting() == 0:
        pass
    print("readline()")
    valueRead = serialArduino.readline(500)

    try:
        valueInInt = int(valueRead)
        print(valueInInt)
        if valueInInt <= 1024:
            if valueInInt >= 0:
                values.append(valueInInt)
                values.pop(0)
                drawnow(plotvalues)
            else:
                print("Invalid! negative number")
        else:
            print("Invalid! too large")
    except ValueError:
        print("Invalid! cannot cast")
