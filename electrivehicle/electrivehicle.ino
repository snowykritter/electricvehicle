#include <Servo.h>

const int escPin = 9;
const int setButtonPin = 2;
const int startButtonPin = 4;
const int potentiometerPin = A0;
const int ledPin = 13;

Servo esc;
int p; // potentiometer reading
int speed;

int setState = 0;
int startState = 0; 

void setup(){
  esc.attach(escPin, 1000, 2000);
  pinMode(ledPin, OUTPUT);
  pinMode(setButtonPin, INPUT);
  pinMode(startButtonPin, INPUT);
}

void loop(){
  setState = digitalRead(setButtonPin);
  startState = digitalRead(startButtonPin);

  if(setState == HIGH){
    p = analogRead(potentiometerPin);
    digitalWrite(ledPin, LOW);
  }else{
    digitalWrite(ledPin, HIGH);
  }

  if(startState == HIGH){
    speed = map(p, 0, 1023, 0, 180); 
    esc.write(speed);
  }
}