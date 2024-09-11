void motor(int spd) {
  int spdf = abs(spd); // Calculate absolute speed

  if (spd > 0) { // Forward motion
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    analogWrite(6, spdf);
  } else if (spd < 0) { // Backward motion
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    analogWrite(6, spdf);
  } else { // Stop the motor
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    analogWrite(6, 0);
  }
}
