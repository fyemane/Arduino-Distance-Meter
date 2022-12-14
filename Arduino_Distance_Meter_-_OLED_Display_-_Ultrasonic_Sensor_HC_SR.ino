//Viral Science www.youtube.com/c/viralscience  www.viralsciencecreativity.com
//Distance Meter OLED Display
//https://www.youtube.com/watch?v=aRGprBppVHY&list=PLUWZpHJMEu-Dv5Va5AmPeZH-E8-v9038u&index=91
//https://www.viralsciencecreativity.com/post/arduino-distance-meter-oled-display-ultrasonic-sensor-hc-sr04

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define trigPin 9
#define echoPin 8

#define OLED_RESET 4
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
  display.clearDisplay();

}

void loop() {
  float duration;
  float distance_cm;
  float distance_in;

  digitalWrite(trigPin, LOW); //PULSE ___|---|___
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance_cm = (duration / 2) / 29.1;
  distance_in = (duration / 2) / 73.914;

  display.setCursor(25, 0); //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Distance Meter");

  display.setCursor(10, 20); //oled display
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println(distance_cm);
  display.setCursor(90, 20);
  display.setTextSize(2);
  display.println("cm");

  display.setCursor(10, 45); //oled display
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println(distance_in);
  display.setCursor(90, 45);
  display.setTextSize(2);
  display.println("in");
  display.display();

  delay(500);
  display.clearDisplay();

  Serial.println(distance_cm);
  Serial.println(distance_in);
}
