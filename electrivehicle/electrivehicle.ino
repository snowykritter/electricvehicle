#include <Servo.h>

const int escPin = 9;
const int buttonPin = 2;

Servo esc;

const double wheelDiameter = 2.875; // inches
const double circumference = wheelDiameter * 3.1415;
const int rpm = 5*1300; // voltage * kV rating

double distance = 7.00; // meters

double velocity = rpm * inchToMeters(circumference) / 60; // meters per second
long time = (int) ((distance / velocity) * 1000); // milliseconds

int buttonState = 0;

void setup(){
  esc.attach(escPin, 1000, 2000);
  // pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop(){
  buttonState = digitalRead(startButtonPin);

  // starts the vehicle
  if(buttonState == HIGH){
    time = distance/velocity
    esc.write(0);
    delay(time) // in milliseconds
    esc.write(90);
  }else{
    return;
  }
}

float inchToMeters(float inch){
  float meters = inch * 0.0254;
  return meters;
}