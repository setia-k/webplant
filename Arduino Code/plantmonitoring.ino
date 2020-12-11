#include <DHT.h>
#include <ArduinoJson.h>
#define DHTTYPE DHT22

// Make json variables
const size_t capacity = JSON_OBJECT_SIZE(3);
DynamicJsonDocument doc(capacity);
// Variables
int soil_sensor = A0;
int dhtPin = 8;
float humidity, temperature;
int soilMoisture;
// Declare DHT pin and type
DHT dht(dhtPin, DHTTYPE);
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
    // Print Json
    serializeJson(doc, Serial);
    Serial.println();

    // Delay
    delay(3000);
}
