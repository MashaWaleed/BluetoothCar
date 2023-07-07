#include "Arduino.h"
#include <SoftwareSerial.h>

int motor_left[] = {6,7};
int motor_right[] = {8,9};

const byte rxPin = 10;
const byte txPin = 11;
SoftwareSerial BTSerial(rxPin, txPin); // RX TX

void setup() {
//   define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(motor_left[0], OUTPUT);
  pinMode(motor_left[1], OUTPUT);
  pinMode(motor_right[0], OUTPUT);
  pinMode(motor_right[1], OUTPUT);
  motorStop();
  BTSerial.begin(38400);
  Serial.begin(9600);
}

void loop() {
  
  while (BTSerial.available() > 0) {
    char data = (char) BTSerial.read();
    if(data == 'F'){
      forward();
    }
    else if(data == 'R'){
      right();
    }
    else if(data == 'L'){
      left();
    }
    else if(data == 'B'){
      backward();
    }
    else if(data == 'S'){
      motorStop();
    }
  }

  
}


void motorStop(){
  digitalWrite(motor_left[0], LOW);
  digitalWrite(motor_left[1], LOW);
  
  digitalWrite(motor_right[0], LOW);
  digitalWrite(motor_right[1], LOW);
  
  delay(25);
}
void right(){
  digitalWrite(motor_left[0], HIGH);
  digitalWrite(motor_left[1], LOW);
  
  digitalWrite(motor_right[0], HIGH);
  digitalWrite(motor_right[1], LOW);
  
  delay(25);
}
void left(){
  digitalWrite(motor_left[0], LOW);
  digitalWrite(motor_left[1], HIGH);
  
  digitalWrite(motor_right[0], LOW);
  digitalWrite(motor_right[1], HIGH);
  
  delay(25);
}
void forward(){
  digitalWrite(motor_left[0], HIGH);
  digitalWrite(motor_left[1], LOW);
  
  digitalWrite(motor_right[0], LOW);
  digitalWrite(motor_right[1], HIGH);
  
  delay(25);
}
void backward(){
  digitalWrite(motor_left[0], LOW);
  digitalWrite(motor_left[1], HIGH);
  
  digitalWrite(motor_right[0], HIGH);
  digitalWrite(motor_right[1], LOW);
  
  delay(25);
}
