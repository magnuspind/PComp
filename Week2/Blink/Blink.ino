/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


int LED = 3;
int mySwitch = 2;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(mySwitch, OUTPUT);
  // declare pin 2 to be an input
  pinMode(3, INPUT);
}


void loop() {
  if (digitalRead(mySwitch) == 1){
    //if pin 2 is HIGH, set pin 3 HIGH):
    digitalWrite(LED, HIGH);
    delay(30);
    digitalWrite(LED, LOW);
    delay(30);
  } else {
    //if pin 2 is LOW, set pin 3 LOW:
    digitalWrite(LED, LOW);
    delay(0);
  }
  /*digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);              // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(50);              // wait for a second*/
}
