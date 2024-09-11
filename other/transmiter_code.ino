#include <Wire.h>
#include <MPU6050.h>

char yawString[10];  // Buffer to hold the formatted yaw value

MPU6050 mpu;

// Timers
unsigned long timer = 0;
float timeStep = 0.01;

float yaw = 0;
unsigned long lastTransmitTime = 0;  // Time of the last transmission
unsigned long transmitInterval = 100;  // Interval in milliseconds between transmissions

void setup()
{
  Serial.begin(9600);  // Initialize serial communication
  mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
  mpu.calibrateGyro();
  mpu.setThreshold(3);
}

void loop()
{
  timer = millis();
  Vector norm = mpu.readNormalizeGyro();
  yaw = yaw + norm.ZAxis * timeStep;

  // Check if it's time to transmit data
  if (millis() - lastTransmitTime >= transmitInterval) {
    // Convert yaw to integer
    int yawInt = (int)yaw;

    // Convert the integer yaw to string
    sprintf(yawString, "%d", yawInt);

    // Send the yaw value as a string over serial
    Serial.write(yawString, strlen(yawString));  // Send the string
    Serial.write('\n');  // Send a newline character for line separation (optional)

    // Update the time of the last transmission
    lastTransmitTime = millis();
  }

  // Ensure consistent timing for the sensor reading
  delay((timeStep * 1000) - (millis() - timer));
}
