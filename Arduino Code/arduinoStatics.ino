#include <ArduinoJson.h>
// Make json variables
const size_t capacity = JSON_OBJECT_SIZE(3);
DynamicJsonDocument doc(capacity);
// Variables
float humidity, temperature;
int soilMoisture;
//
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Get Value From Sensor
  // DHT11 / DHT22
  humidity = 25.0;
  temperature = 22.5;
  // Soil Moisture Sensor
  soilMoisture = 400;
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
