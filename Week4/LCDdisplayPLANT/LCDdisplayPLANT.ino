/*
  LiquidCrystal Library

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int mySwitch = 7;
int sensorpin = A0;
int sensorValue = 0;

void setup() {
  // declare pin 2 to be an input
  pinMode(mySwitch, INPUT);
  // pin A0 as debugging
  pinMode(sensorpin, INPUT);
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("");
}

void loop() {

  // read the value from the sensor:
  sensorValue = analogRead(sensorpin);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  
  //if sensorpin is above 300, write message on LCD
  if (analogRead(sensorpin) < 300){
    lcd.print("Hello");
  } else {
    //if sensorpin is under 300, write other message LCD
    lcd.print("PLANT PLANT");
  }

  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.println();
}
