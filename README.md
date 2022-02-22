# Web plant
## Requirements

- Python 3 with pip and venv installed
- Arduino Library
  - ArduinoJson
  - DHT sensor library by Adafruit

## Installation

1. Download
2. Mount project folder in `CMD / Bash`
3. Create venv `python -m venv venvlib`
4. Activate venv
5. `pip install -r requirements.txt`

## Activating venv

See <https://docs.python.org/3/tutorial/venv.html> further refrences.

- Windows

  1. `cd {project folder}/venvlib/Scripts/`
  2. `activate`

- Linux / Mac

  1. `cd {project folder}/venvlib//bin/`
  2. `source activate`

- Deactivating venv

  1. Type `deactivate` in shell

## Running the project

After all requirements are installed, run app byr running `app.py` located inside src folder.
`app.py` will run on defined `localhost:port`

## Projects Structures

- {venv library}/
- Arduino Code/ --> Code used by arduino
- schematics/ --> Image of the project sketches
- src/
  - /templates/ --> HTML file location
  - /static/ --> css & js file location
  - /app.py --> The main python file
  - /app_arduiless.py --> main python file used to run without arduino

## Project Refrences and Tutorials

- <https://create.arduino.cc/projecthub/mafzal/temperature-monitoring-with-dht22-arduino-15b013>
- <https://create.arduino.cc/projecthub/murthysiddhant/plant-monitor-sensor-to-front-end-c1f715>
- <https://docs.python.org/3/tutorial/venv.html>
- <https://maker.pro/arduino/projects/arduino-soil-moisture-sensor>
- <https://www.youtube.com/playlist?list=PLC86yC9XtBxqpbY-3SYs9IahAC9bBE4PY>
- <https://www.youtube.com/watch?time_continue=393&v=tXpFERibRaU&feature=emb_title>
