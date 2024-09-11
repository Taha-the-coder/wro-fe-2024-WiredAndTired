#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);  // RX, TX pins

char receivedYawString[10];  // Buffer to hold the received string
int receivedYaw;
int index = 0;

void setup() {
  Serial.begin(9600);     // Serial monitor
  mySerial.begin(9600);   // Initialize software serial on pins 9 and 10
}

void loop() {
  if (mySerial.available()) {
    char c = mySerial.read();  // Read a character from the software serial buffer

    if (c == '\n') {
      receivedYawString[index] = '\0';  // Null-terminate the string
      receivedYaw = atoi(receivedYawString);  // Convert the received string to an integer

      // Print the received yaw value
      Serial.print("Received Yaw: ");
      Serial.println(receivedYaw);
      if(receivedYaw > 0){
       
      }

      // Reset index for the next message
      index = 0;
    } else {
      if (index < sizeof(receivedYawString) - 1) {
        receivedYawString[index++] = c;  // Add the character to the buffer
      }
    }
  }
}
