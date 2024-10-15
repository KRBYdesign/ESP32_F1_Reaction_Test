#include <Arduino.h>

// led pinout
const int blueLed = 2;
const int redLed1 = 4;
const int redLed2 = 16;
const int redLed3 = 17;
const int yellowLed = 5;
const int greenLed = 18;

// put function declarations here:
void enableLed(int ledPinCode);
void disableLed(int ledPinCode);
void startCountdown();
void lightsOut();

void setup()
{
  // todo: loop through the array of pins
  pinMode(blueLed, OUTPUT);
  pinMode(redLed1, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(redLed3, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  Serial.begin(115200);
  // seed the randomness
  randomSeed(analogRead(A0)); // if nothing connected to pin 0 then random analog noise should take care of this
}

void loop()
{
  // turn on blue led to show the app is running
  enableLed(blueLed);
  startCountdown();
  delay(5000);
  disableLed(blueLed);
  delay(2000);

  // turn this into an f1 reaction checker
}

void enableLed(int ledPinCode) {
  digitalWrite(ledPinCode, HIGH);
}

void disableLed(int ledPinCode) {
  digitalWrite(ledPinCode, LOW);
}

void startCountdown() {
  // turn on all leds
  enableLed(redLed1);
  enableLed(redLed2);
  enableLed(redLed3);
  enableLed(yellowLed);
  enableLed(greenLed);

  delay(2000); // wait with them on for 2 seconds.

  // turn off the leds
  disableLed(redLed1);
  disableLed(redLed2);
  disableLed(redLed3);
  disableLed(yellowLed);
  disableLed(greenLed);

  // enable the leds one by one
  enableLed(redLed1);
  delay(1000); // delay for 1 sec
  enableLed(redLed2);
  delay(1000); // delay for 1 sec
  enableLed(redLed3);
  delay(1000); // delay for 1 sec
  enableLed(yellowLed);
  delay(1000); // delay for 1 sec
  enableLed(greenLed);

  lightsOut();
  Serial.print("And away we go!\n");
};

void lightsOut() {
  const int minDelay = 200;
  const int maxDelay = 3000;

  delay(minDelay); // wait the min time regulated by the FIA in section 44.10

  int randomDelay = random(maxDelay);
  delay(randomDelay);
  // away we go

  disableLed(redLed1);
  disableLed(redLed2);
  disableLed(redLed3);
  disableLed(yellowLed);
  disableLed(greenLed);

  Serial.printf("\n\nDelay of %d\n", randomDelay);
}