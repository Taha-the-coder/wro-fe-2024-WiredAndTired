void turn(int dgr){
  myservo.write(84 + dgr);//84
}

int getangle(){
 if(mySerial.available()){
    t = mySerial.read();
    Serial.println(t);
  }
  return t;
}

void a(){
   if(mySerial.available()){
    t = mySerial.read();
    Serial.println(t);
  }
}
