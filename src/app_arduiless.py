# Imports
from flask import *
import json

# GLOBALS

host = '0.0.0.0'  # == localhost
webPort = 8080
app = Flask(__name__)

# Routes


@app.route("/")
def index():
    return render_template('index.html')


@app.route("/update", methods=['GET'])
def updateData():
    result = [
        300,
        27,
        150
    ]
    return jsonify(result)


# Main
if __name__ == '__main__':
    app.run(host, webPort)
