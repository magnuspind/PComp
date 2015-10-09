//Button Press Detection - single message
// from http://www.instructables.com/id/Beginner-Arduino/step15/Button-As-Toggle-Switch/

//pin connections
int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int buttonPin = 2;

boolean currentState = LOW;       //stroage for current button state
boolean lastState = LOW;          //storage for last button state
int currentColor = redPin;           //storage for current color

void setup(){
  pinMode(buttonPin, INPUT);//this time we will set the pin as INPUT
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  digitalWrite(currentColor, HIGH);   //initialize with currentColor on (full brightness)
}

void loop(){
  currentState = digitalRead(buttonPin);
  if (currentState == HIGH && lastState == LOW){  //if button has just been pressed
    delay(1);                                     //Button debouncing

    int nextColor = getNextColor(currentColor);
    fader(currentColor, nextColor);
    currentColor = nextColor;
  }
}

int getNextColor(int color){
  if (color == redPin) {
    return greenPin;
  }
  if (color == greenPin) {
    return bluePin;
  }
  if (color == bluePin) {
    return redPin;
  }
}

void fader(int color1, int color2){
    for (int brightness=0;brightness<255;brightness++){
        analogWrite(color1, 255-brightness);
        analogWrite(color2, brightness);
        delay(6);
    }
}
