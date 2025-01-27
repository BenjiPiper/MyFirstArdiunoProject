#include <Servo.h> // library for servo controls 
Servo myServo; // initiate servo class

int ledPin = 7; // var for the led pin
int servoPin = 4; // var for Servo control signal
int servoPosition = 0; // initiate servo position 0 degrees
int pirPin= 8; // var for motion sensor output signal 

unsigned int previousMillis1 = 0; // var to store milliseconds for blink
const int interval1 = 1000; // var to store blink interval rate


void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin, OUTPUT); 
  pinMode(ledPin, OUTPUT);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis(); // get current run time
  // if motion detected which returns HIGH state from output pin then move servo to 90 degree position
  // additionally set led state to HIGH (constantly on)
  if (digitalRead(pirPin) == HIGH ){
    servoPosition = 90;
    digitalWrite(ledPin, digitalRead(pirPin));
  }
  //else when no motion is detected (motion detector returns to low state) move servo to 0 degree postion
  else{
    servoPosition = 0;
    digitalWrite(ledPin, digitalRead(pirPin));
  }
  myServo.write(servoPosition); // write servo postion
  
  // led blinker
  if (currentMillis - previousMillis1 >= interval1){
     digitalWrite(ledPin,  !digitalRead(ledPin));
     previousMillis1 = currentMillis;
  }

}
