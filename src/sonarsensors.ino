int sonar(int n) {
  int distance;
  digitalWrite(trigPins[n - 1], LOW);
  delayMicroseconds(2);
  digitalWrite(trigPins[n - 1], HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPins[n - 1], LOW);
  long duration = pulseIn(echoPins[n - 1], HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  return distance;
}
