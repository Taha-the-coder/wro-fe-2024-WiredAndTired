void firstround() {
  while (clockwise) {
    motor(120);
    while (sonar(1) > 70) {
      while (getangle() != 0) {
        turn(25);
      }
    }
    while (sonar(1) < 70) {
      turn(0);
      while(counter == 12){
        while(analogRead(A6) > startingpos){}
        motor(0);
      }
    }
  }
  while (counterclockwise) {
    motor(120);
    while (sonar(2) > 70) {
      while (getangle() != 0) {
        turn(-25);
      }
    }
    while (sonar(2) < 70) {
      turn(0);
      while(counter == 12){
        while(analogRead(A6) > startingpos){}
        motor(0);
      }
    }
  }
}
