#include <AFMotor.h>  // include AFMotor library
AF_DCMotor motorLeft(4);  // left motor connected to M4
AF_DCMotor motorRight(3); // right motor connected to M3
#define trig 20 // trig pin connected to pin 20
#define echo 21 // echo pin connected to pin 21
float timePassed, distance; // timePassed & distance variables
void setup() {  // setup routine
  // put your setup code here, to run once:
  motorLeft.setSpeed(250);  // set left motor speed
  motorLeft.run(RELEASE); // release left motor
  motorRight.setSpeed(250); // set right motor speed
  motorRight.run(RELEASE);  // release right motor
  pinMode(trig, OUTPUT);  // set trig pin as output
  pinMode(echo, INPUT); // set echo pin as input
}
void loop() { // loop routine
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW); // reset trig pin
  delayMicroseconds(2); // delay 2 microseconds
  digitalWrite(trig, HIGH); // set trig pin
  delayMicroseconds(10);  // delay 10 microseconds
  digitalWrite(trig, LOW);  // reset trig pin
  timePassed = pulseIn(echo, HIGH); // calculate round trip time
  distance = timePassed * 0.0343 / 2; // calculate distance
  if ( distance > 50 )  // no barrier
  {
    motorLeft.run(FORWARD); // go forward
    motorRight.run(FORWARD);  // go forward
    delay(100); // delay 100 milliseconds
  }
  else  // barrier
  {
    motorLeft.run(RELEASE); // release left motor
    motorRight.run(RELEASE);  // release right motor
    delay(100); // delay 100 milliseconds
    motorLeft.run(FORWARD); // turn right
    motorRight.run(BACKWARD); // turn right
    delay(500); // delay 500 milliseconds
    motorLeft.run(RELEASE); // release left motor
    motorRight.run(RELEASE);  // release right motor
    delay(100); // delay 100 milliseconds
  }
}
