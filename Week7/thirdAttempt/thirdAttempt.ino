#include <Keypad.h>

char Data[Password_Lenght]; // 6 is the number of chars it can hold + the null char = 7
char Master[Password_Lenght] = "123456"; 
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

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
}

void loop(){
  char key = keypad.getKey();

  if (key != NO_KEY){
    Serial.println(key);

    if (key == 'A' && 'B'){
      Serial.println("hello");
    }
  }
}
