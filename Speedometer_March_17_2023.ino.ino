#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

/*
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
*/

SoftwareSerial ss(2,3); // (RX, TX)

TinyGPSPlus gps;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //Serial.println(gps.speed.mph());
  while (ss.available() > 0) { 
    Serial.println(gps.encode(ss.read()));
    }
  }

  /*
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize the OLED display with I2C address 0x3C
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("GPS Data");
  display.display();
  */

  /* if (gps.location.isValid() == 1) {
      display.clearDisplay();
      display.setCursor(0,10);
      display.setTextSize(3);      
      display.print("Loc: ");
      display.println(gps.location.lat());
      display.display();
      delay(100);
    */
