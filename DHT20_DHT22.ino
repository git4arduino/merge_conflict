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
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>  // DHT22

// DHT22
#define DHTPIN 5
#define DHTTYPE DHT22
DHT dht22 = DHT(DHTPIN, DHTTYPE);

// OLED 0,96
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

unsigned long previousMillis = millis();

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(100);
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

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);

    display.setTextSize(2);
    int16_t x1, y1;
    uint16_t w, h;
    display.getTextBounds("DHT22", 0, 0, &x1, &y1, &w, &h);
    int startX = (SCREEN_WIDTH - w) / 2;

    display.setCursor(startX, 2);
    display.print("DHT22");

    display.setTextSize(1);
    display.setCursor(startX, 35);
    display.print(dht22_temperature);
    display.print((char)247);
    display.print("C ");

    display.setCursor(startX, 45);
    display.print(dht22_humidity);
    display.print("%");

    display.display();
  }
}
