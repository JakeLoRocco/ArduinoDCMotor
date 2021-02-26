/*
    DCMotor.h - Library for controlling a bidirectional DC Motor
    based on a L293D motor controller and the circuit in the following
    diagram: https://www.ti.com/lit/ds/symlink/l293d.pdf?ts=1614037260430&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FL293D .

    Created by Jake LoRocco. February 2021.
*/

#ifndef DCMOTOR_H
#define DCMOTOR_H

#include "Arduino.h"

class DCMotor {
  public:
    int enPin;
    int rPin;
    int lPin;

    bool pinsInitialized;

    DCMotor() {};
    DCMotor( int enablePin, int rightPin, int leftPin );

    void pinInit();
    void turnFastStop( int dir, int sec );
    void turnFreeStop( int dir, int sec, int del );

    void rightFast(int sec);
    void leftFast(int sec);

    void rightFree( int sec, int del );
    void leftFree( int sec, int del ); 
    
};

#endif