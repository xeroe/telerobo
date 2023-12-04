#include "motorControl.h"
#include <arduino.h>
int LeftMotorPin = 23;
int rightMotorPin = 22;
void setupMotor()
{
    pinMode(LeftMotorPin, OUTPUT);
    pinMode(rightMotorPin, OUTPUT);
    analogWrite(LeftMotorPin, 0);
    analogWrite(rightMotorPin, 0);
}

void forward()
{
    analogWrite(LeftMotorPin, 255);
    analogWrite(rightMotorPin, 255);
}

void reverse()
{
    analogWrite(LeftMotorPin, 0);
    analogWrite(rightMotorPin, 0);
}

void left()
{
    analogWrite(LeftMotorPin, 255);
}

void right()
{
    analogWrite(rightMotorPin, 255);
}

void stop()
{
    analogWrite(LeftMotorPin, 0);
    analogWrite(rightMotorPin, 0);
}

void leftrightRelease()
{
    analogWrite(rightMotorPin, 0);
    analogWrite(rightMotorPin, 0);
}

void resetMotor()
{
    analogWrite(LeftMotorPin, 0);
    analogWrite(rightMotorPin, 0);
}