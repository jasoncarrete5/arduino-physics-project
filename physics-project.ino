/*
 * Setup: 1 signal lead into GND, other lead into pin 3
 * Motor: 1 lead into GND, other lead into pin 4
 * yellow GND clockwise
 */

const int motorPin = 4;
const int signalPin = 3;
boolean motorReady = true;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  pinMode(motorPin, OUTPUT);
  pinMode(signalPin, INPUT_PULLUP);
  Serial.println("Ready");
}

void loop() {
  if(digitalRead(signalPin) == LOW) {
    //trigger motor
    if(motorReady) {
      digitalWrite(motorPin, HIGH);
      delay(1000);
      digitalWrite(motorPin, LOW);
      motorReady = false;
      Serial.println("Done");
    }
  }
}
