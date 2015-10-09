// based on the Fading example

int redPin = 11;    
int greenPin = 10;
int bluePin = 9;

int buttonPin = 2;
int buttonState = 0;



void setup() {
  // nothing happens in setup
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read button
  buttonState = digitalRead(buttonPin);
  //perform fading when HIGH
if (buttonState = HIGH){
    // fade in from min to max in increments of 5 points:
  for (int fadeValueLow = 0 ; fadeValueLow <= 255; fadeValueLow += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(redPin, fadeValueLow);
    analogWrite(greenPin, fadeValueLow);
    analogWrite(bluePin, fadeValueLow);
  }
} else {
    int fadeValueHigh = 0;{
    analogWrite(redPin, fadeValueHigh);
    analogWrite(greenPin, fadeValueHigh);
    analogWrite(bluePin, fadeValueHigh);
    }
  }
}
