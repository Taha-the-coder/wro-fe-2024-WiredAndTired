#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include "HUSKYLENS.h"
#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);  // RX, TX pins

void printResult(HUSKYLENSResult result);
//others
char t;

//button
int getval;

//sonar setup
const int trigPins[] = {16, 12};
const int echoPins[] = {15, 11};
int numsonar = 2 ;


//display setup
#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

//husky
HUSKYLENS huskylens;
void printResult(HUSKYLENSResult result);
int id , husky;
int red = 1;
int green = 2;
int noblocks = 0;
int color = 2;
int xpos = 1;

// servo
Servo myservo;
int angle = 0;
int newangle;

//motordriver
int spdf;

//carmode
bool clockwise, counterclockwise;

//counter
int counter = 0;

int startingpos;
int eye;
char ang;
//setup
void setup() {
  //attach components
  Serial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  Wire.begin();
  huskylens.begin(Wire);
  myservo.attach(5);

  //pinmode
  for (int i = 0; i < numsonar + 1; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
  }
  pinMode(4, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(A3, INPUT);
  mySerial.begin(115200);


  //menu();
  turn(0);




}

//mainloop
void loop() {
  motor(0);
  husky = huskyread(color);
  Serial.println(husky);

  while (husky != -1) {
    husky = huskyread(color);  // Update husky
    Serial.println(husky);

    // Inner loop for husky == 1 case
    while (husky == 1) {
      motor(0);
      delay(1000);
      turn(25);
      delay(500);
      motor(120);
      delay(1000);
      motor(0);
      delay(1000);
      turn(-25);
      delay(500);
      motor(120);
      delay(1000);

      husky = huskyread(color);  // Update husky after each set of commands
      Serial.println(husky);

      // If husky changes, break out of the inner loop
      if (husky != 1) {
        break;
      }
    }
  }
}
