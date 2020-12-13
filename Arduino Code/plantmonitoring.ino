#include <DHT.h>
#include <ArduinoJson.h>
#define DHTTYPE DHT22

// Make json variables
const size_t capacity = JSON_OBJECT_SIZE(3);
DynamicJsonDocument doc(capacity);
// Pins
// LED Pins
int led_red = 7;
int led_ylw = 6;
int led_grn = 5;
// Sensor Pins
int dhtPin = 8;
int soil_sensor = A0;
// Variables
float humidity, temperature;
int soilMoisture;
int threshold_lwr = 300;
int threshold_upr = 450;
// Declare DHT pin and type
DHT dht(dhtPin, DHTTYPE);
// LED Indicator
int ledLevel(int soilMoistureValue)
{
    if (soilMoistureValue < threshold_lwr)
    {
        return 1;
    }
    else if (soilMoistureValue >= threshold_lwr && soilMoistureValue <= threshold_upr)
    {
        return 2;
    }
    else if (soilMoistureValue > threshold_upr)
    {
        return 3;
    }
}
//
void setup()
{
    Serial.begin(9600);
    dht.begin();
    delay(2000);
}

void loop()
{
    // Get Value From Sensor
    // DHT11 / DHT22
    humidity = dht.readHumidity();
    temperature = dht.readTemperature();
    // Soil Moisture Sensor
    soilMoisture = analogRead(soil_sensor);
    // Set Json
    doc["humidity"] = humidity;
    doc["temperature"] = temperature;
    doc["soilMoisture"] = soilMoisture;
    // Send JSON data to RPI using serial communication
    serializeJson(doc, Serial);
    Serial.println();
    //
    switch (ledLevel(soilMoisture))
    {
    case 1:
        digitalWrite(led_grn, HIGH);
        digitalWrite(led_ylw, LOW);
        digitalWrite(led_red, LOW);
        break;
    case 2:
        digitalWrite(led_grn, LOW);
        digitalWrite(led_ylw, HIGH);
        digitalWrite(led_red, LOW);
        break;
    case 3:
        digitalWrite(led_grn, LOW);
        digitalWrite(led_ylw, LOW);
        digitalWrite(led_red, HIGH);
        break;
    default:
        break;
    }
    // Delay
    delay(3000);
}
