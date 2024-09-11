int buttonpressed(){
  return (digitalRead(4) == 0) ? 1 : 0;
}
