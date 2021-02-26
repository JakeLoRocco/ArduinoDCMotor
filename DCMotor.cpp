/*
    DCMotor.cpp - Library for controlling a bidirectional DC Motor
    based on a L293D motor controller and the circuit in the following
    diagram: https://www.ti.com/lit/ds/symlink/l293d.pdf?ts=1614037260430&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FL293D .

    Created by Jake LoRocco. February 2021.
*/

#include "Arduino.h"
#include "DCMotor.h"

DCMotor::DCMotor( int enablePin, int rightPin, int leftPin) {
  this->enPin = enablePin;
  this->rPin = rightPin;
  this->lPin = leftPin;

  pinInit();
}

void DCMotor::pinInit() {
  pinMode(enPin, OUTPUT);
  pinMode(rPin, OUTPUT);
  pinMode(lPin, OUTPUT);

  this->pinsInitialized = true;
}

void DCMotor::turnFastStop( int dir, int sec ) {
  //0 - right turn;
  //1 - left turn;
  int highPin;
  int lowPin;
  
  if( dir == 0 ) {
    highPin = this->rPin;
    lowPin = this->lPin;
  } else {
    highPin = this->lPin;
    lowPin = this->rPin;
  }

  pinMode(this->enPin, HIGH);
  pinMode(highPin, HIGH);
  pinMode(lowPin, LOW);

  delay(sec * 1000);

  pinMode(highPin, LOW);
}

void DCMotor::turnFreeStop( int dir, int sec, int del ) {
  //0 - right turn;
  //1 - left turn;
  int highPin;
  int lowPin;
  
  if( dir == 0 ) {
    highPin = this->rPin;
    lowPin = this->lPin;
  } else {
    highPin = this->lPin;
    lowPin = this->rPin;
  }

  pinMode(this->enPin, HIGH);
  pinMode(highPin, HIGH);
  pinMode(lowPin, LOW);

  delay(sec * 1000);

  pinMode(this->enPin, LOW);
  pinMode(highPin, LOW);

  delay(del * 1000);

  pinMode(this->enPin, HIGH);
}

void DCMotor::rightFast( int sec ) {
  turnFastStop( 0, sec );
}

void DCMotor::leftFast( int sec ) {
  turnFastStop( 1, sec );
}

void DCMotor::rightFree( int sec, int del ) {
  turnFreeStop( 0, sec, del );
}

void DCMotor::leftFree( int sec, int del ) {
  turnFreeStop( 1, sec, del );
}