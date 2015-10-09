int speakerPin = 8;

void setup(){
  pinMode(speakerPin, OUTPUT);
}

void loop(){
  //use for loop to make the speaker beep
  for (int i=0; i<1000;i++){
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(200);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(200);
  }
  delay(1000);
  //delay for 1 sec
}

