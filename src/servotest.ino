void servotest(){
  int newangle = angle;
  if(buttonpressed()){
    delay(1500);
    newangle = buttonpressed() ? angle + 5 : angle - 5;
  }
  angle = newangle;
  disp(1, 64, 0, newangle);
  turn(newangle);
}
