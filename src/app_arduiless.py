""" 
!! ARDUILESS VERSION
!! CAN BE RUN WITHOUT ARDUINO CONNECTED
"""
# Imports
from flask import Flask, render_template, jsonify
from flask import request
import json

# GLOBALS

host = '0.0.0.0'  # == localhost
webPort = 8080
username = "Setia"
app = Flask(__name__)

# Routes


@app.route("/")
def index():
    return render_template('index.html', username=username)


@app.route("/update", methods=['GET'])
def updateData():
    result = [
        12.5,
        22.5,
        100
    ]
    return jsonify(result)


# Main
if __name__ == '__main__':
    app.run(host, webPort)
