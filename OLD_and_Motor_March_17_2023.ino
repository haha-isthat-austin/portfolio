/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

int IN1 = 10;
int IN2 = 11;
int FDBACK = 4;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0, 12);
  // Display static text
  display.println("Hello, world!");
  display.display(); 

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(FDBACK, INPUT);
}

void loop() {
  digitalRead(FDBACK);
  
  display.clearDisplay();
  display.setTextSize(3);
  display.setCursor(0, 12);  
  display.setTextColor(WHITE);
  display.println("SHRINK");
  
  display.display();
  digitalWrite(IN1, LOW);
  delay(2000);
  digitalWrite(IN2, HIGH); // RETRACTS
  delay(2000);

  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0, 12);
  display.println("EXTEND");
  
  display.display();
  digitalWrite(IN1, HIGH);
  delay(1000);
  digitalWrite(IN2, LOW);
  delay(2000);
}
