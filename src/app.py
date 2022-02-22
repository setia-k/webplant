""" 
!! THIS ONE REQUIRES ARDUINO CONNECTED
!! USE ARDUILESS VERSION INSTEAD
"""
# Imports
from flask import Flask, render_template, jsonify
import json
import queue
import serial
import threading
import platform
import time
# GLOBALS
arduinoPortLinux = '/dev/ttyACM0'
arduinoPortWindows = 'COM3'
host = '127.0.0.1'
webPort = 8080
username = "Setia"
app = Flask(__name__)
q = queue.Queue()
# Data Containers
humidity = []
temperature = []
soilMoisture = []
# Routes


@app.route("/")
def index():
    return render_template('index.html', username=username, host=host)


@app.route("/update", methods=['GET'])
def updateData():
    while not q.empty():
        humidity.append(q.get())
        temperature.append(q.get())
        soilMoisture.append(q.get())
    if not q.empty():
        result = [0, 0, 0]
    else:
        result = [
            humidity[len(humidity)-1],
            temperature[len(temperature)-1],
            soilMoisture[len(soilMoisture)-1],
        ]
    return jsonify(result)


def getDataParsed():
    """
    Return parsed json of data from sensors in dictionary form
    """
    serialConsole.flush()
    rawData = serialConsole.readline().decode("utf-8").rstrip()
    parsedJson = json.loads(rawData)
    return parsedJson


def dataCollector():
    data = getDataParsed()
    # put data in queue
    q.put(float(data["humidity"]))
    q.put(float(data["temperature"]))
    q.put(int(data["soilMoisture"]))


# Main
if __name__ == '__main__':
    if platform.system() == 'Linux':
        usedArduinoPort = arduinoPortLinux
    elif platform.system() == 'Windows':
        usedArduinoPort = arduinoPortWindows
    serialConsole = serial.Serial(usedArduinoPort, 9600, timeout=5)
    collector = threading.Thread(target=dataCollector)
    collector.start()
    print("Preparing to run on " + platform.system() + " please wait!")
    time.sleep(3)
    print("App started!")
    app.run(host, webPort)
