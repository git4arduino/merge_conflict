/*
        _          _ ______ _____ _____
       (_)        | |  ____|  __ \_   _|
  _ __  ___  _____| | |__  | |  | || |
 | '_ \| \ \/ / _ \ |  __| | |  | || |
 | |_) | |>  <  __/ | |____| |__| || |_
 | .__/|_/_/\_\___|_|______|_____/_____|
 | |
 |_|

  www.pixeledi.eu | https://linktr.ee/pixeledi
  DHT20 und DHT22 | V1.0 | 10.2023

  Check this awesome converter:
  https://javl.github.io/image2cpp/

*/

#include <Adafruit_Sensor.h>
#include <DHT.h>  // DHT22

// DHT22
#define DHTPIN 5
#define DHTTYPE DHT22
DHT dht22 = DHT(DHTPIN, DHTTYPE);

unsigned long previousMillis = millis();

void setup() {
  Serial.begin(115200);

  dht22.begin();

  Serial.println("Setup finished");
}

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (1000 * 2)) {
    Serial.println("neue Werte");

    previousMillis = currentMillis;

    float dht22_temperature = dht22.readTemperature();
    float dht22_humidity = dht22.readHumidity();

    Serial.println(dht22_temperature);
    Serial.println(dht22_humidity);
  }
}
