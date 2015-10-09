/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int buttonPin = 2;
int buttonState = 0;



void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop(){
  //read button
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH){
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(redPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
  } else {
    digitalWrite(redPin, LOW);
  }

  
//
//  // fade out from max to min in increments of 5 points:
//  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
//    // sets the value (range from 0 to 255):
//    analogWrite(redPin, fadeValue);
//    // wait for 30 milliseconds to see the dimming effect
//    delay(30);
//  }
}

