#include <Wire.h>
#include <MPU6050.h>


MPU6050 mpu;

// Timers
unsigned long timer = 0;
float timeStep = 0.01;

float yaw = 0;


void setup()
{
  Serial.begin(115200);  // Initialize serial communication
  mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
  mpu.calibrateGyro();
  mpu.setThreshold(3);
}

void loop()
{
  timer = millis();
  Vector norm = mpu.readNormalizeGyro();
  yaw = yaw + norm.ZAxis * timeStep;
  int yawInt = abs((int)yaw);
  if (yawInt % 90 > 87 || yawInt % 90 < 3) {
    Serial.write('1'); // Print 0 if the angle is a multiple of 90
  } else {
    Serial.write('0'); // Print 1 if the angle is not a multiple of 90
  }
  Serial.write('\n');
  delay((timeStep * 1000) - (millis() - timer));
}
