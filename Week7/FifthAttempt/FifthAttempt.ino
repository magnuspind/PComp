// Based on http://playground.arduino.cc/Main/KeypadPassword
// KeyPad password on the arduino website

#include <Keypad.h>

#define Password_Length 4 // three characters + NULL character

char Input[Password_Length]; // 3 is the number of characters it can hold + the null char = 4
char Password[Password_Length] = "ABC";
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;


const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'M','I','E', 'A'},
  {'N','J','F', 'B'},
  {'O','K','G', 'C'},
  {'P','L','H', 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

int redPin = 13;
int greenPin = 12;
int bluePin = 11;

int speakerPin = 1;

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  pinMode(speakerPin, OUTPUT);
}

void loop(){
  
  customKey = customKeypad.getKey();

  if (customKey){
    Input[data_count] = customKey; // store characters into data array
    data_count++; // plus data array by 1 to store new character, and keep track of the number of characters entered
  }
  if(data_count == Password_Length-1){ // if the array index is equal to the number of expected chars, compare data to master
  
    if(!strcmp(Input, Password)){
      Serial.println("Good");
      for (int i=0; i<1000;i++){
      digitalWrite(speakerPin, HIGH);
      delayMicroseconds(200);
      }
      setColor(0, 255, 0);  // green
      delay(1000); // delay 1 sec
      setColor(0,0,0); // turn off
      clearData(); // run clear function, so it can be updated
    }
    else {
      Serial.println("bad");
      setColor(255, 0, 0);  // red
      delay(1000); // delay 1 sec
      setColor(0,0,0); // turn off
      clearData(); // run clear function so it can be updated
    }
  }
}

void clearData(){
  while(data_count !=0){   // This can be used for any array size, 
    Input[data_count--] = 0; //clear array for new data
  }
  return;
}

void setColor(int red, int green, int blue){
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
