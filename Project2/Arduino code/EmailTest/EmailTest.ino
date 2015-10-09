#include <Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h" // Contains Temboo account information   

// The number of times to trigger the action if the condition is met
// We limit this so you won't use all of your Temboo calls while testing
int maxCalls = 10;

// The number of times this Choreo has been run so far in this sketch
int calls = 0;

int inputPin = 7;


void setup() {
  Serial.begin(9600);
  
  // For debugging, wait until the serial console is connected
  delay(4000);
  while(!Serial);
  Bridge.begin();
  
  // Initialize pins
  pinMode(inputPin, INPUT);

  Serial.println("Setup complete.\n");
}

void loop() {
  int sensorValue = digitalRead(inputPin);
  Serial.println("Sensor: " + String(sensorValue));

  if (sensorValue == HIGH) {
    if (calls < maxCalls) {
      Serial.println("\nTriggered! Calling SendEmail Choreo...");
      runSendEmail(sensorValue);
      calls++;
    } else {
      Serial.println("\nTriggered! Skipping to save Temboo calls. Adjust maxCalls as required.");
    }
  }
  delay(250);
}

void runSendEmail(int sensorValue) {
  TembooChoreo SendEmailChoreo;

  // Invoke the Temboo client
  SendEmailChoreo.begin();

  // Set Temboo account credentials
  SendEmailChoreo.setAccountName(TEMBOO_ACCOUNT);
  SendEmailChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
  SendEmailChoreo.setAppKey(TEMBOO_APP_KEY);

  // Set Choreo inputs
  SendEmailChoreo.addInput("MessageBody", "Test");
  SendEmailChoreo.addInput("Subject", "You are forgiven");
  SendEmailChoreo.addInput("Password", "xwjwezbpyovwojsg");
  SendEmailChoreo.addInput("Username", "aloeveraforgivesyou@gmail.com");
  SendEmailChoreo.addInput("FromAddress", "\"Aloe Vera\"");
  SendEmailChoreo.addInput("ToAddress", "magnuspind@gmail.com");

  // Identify the Choreo to run
  SendEmailChoreo.setChoreo("/Library/Google/Gmail/SendEmail");

  // Run the Choreo
  unsigned int returnCode = SendEmailChoreo.run();

  // Read and print the error message
  while (SendEmailChoreo.available()) {
    char c = SendEmailChoreo.read();
    Serial.print(c);
  }
  Serial.println();
  SendEmailChoreo.close();
}
