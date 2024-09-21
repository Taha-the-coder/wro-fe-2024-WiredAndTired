void firstround(){
  eye = sonar(2);
if(eye < 60){
  motor(120);
turn(0);
ang = getangle();
}
if(eye > 60){
  delay(20);
  eye = sonar(2);
  if(eye > 60){
    motor(150);
    turn(-25);
  while(ang != '0'){
    ang = getangle();
  }
  ang = getangle();
  while(ang != '1'){
    ang = getangle();
    turn(-25);
  }
  }
}
}
