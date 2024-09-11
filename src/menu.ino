void menu(){
  disp(1, 0 , 0, "Press for settings" );
  while (!buttonpressed()) {}
  delay(500);
  disp(1, 0 , 0, "press = clkwise                           hold = counterclkwise" );
  while (!buttonpressed()) {}
  delay(1000);
  if(buttonpressed()){
    disp(1, 0, 0, "   counterclockwise");
    counterclockwise = true;
    clockwise = false;
  }
  if(!buttonpressed()){
    disp(1, 0, 0, "     clockwise");
    clockwise = true;
    counterclockwise = false;
  }
  delay(500);
  disp(1, 0, 0, "keep bot at 90 dgr");
  while (!buttonpressed()) {}

  disp(1, 0, 0, "    Start");
  while (!buttonpressed()) {}
}
