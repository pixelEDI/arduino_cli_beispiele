//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// Arduino CLI Project Files | 05.2025

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Adafruit_BME280 bme;

void setup() {
  Serial.begin(115200);
  
  if (!bme.begin(0x76)) {
    Serial.println("Sensor nicht gefunden!");
    while (1);
  }

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED nicht gefunden!"));
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  float temp = bme.readTemperature();
  float hum = bme.readHumidity();
  float pres = bme.readPressure() / 100.0F;

  Serial.print("Temperatur: ");
  Serial.print(temp);
  Serial.println(" °C");

  Serial.print("Luftfeuchtigkeit: ");
  Serial.print(hum);
  Serial.println(" %");

  Serial.print("Luftdruck: ");
  Serial.print(pres);
  Serial.println(" hPa");

  zeigeWerteAufOLED(temp, hum, pres);

  delay(2000);
}

void zeigeWerteAufOLED(float temperatur, float luftfeuchtigkeit, float luftdruck) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Temp: ");
  display.print(temperatur);
  display.println(" C");

  display.print("Feuchte: ");
  display.print(luftfeuchtigkeit);
  display.println(" %");

  display.print("Druck: ");
  display.print(luftdruck);
  display.println(" hPa");

  display.display();
}

