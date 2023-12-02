#include "motorControl.h"
#include <arduino.h>
int speedPin = 23;
int steerPin = 22;
void setupMotor()
{
    pinMode(speedPin, OUTPUT);
    pinMode(steerPin, OUTPUT);
    analogWrite(speedPin, 128);
    analogWrite(steerPin, 128);
}

void forward()
{
    analogWrite(speedPin, 255);
}

void reverse()
{
    analogWrite(speedPin, 0);
}

void left()
{
    analogWrite(steerPin, 0);
}

void right()
{
    analogWrite(steerPin, 255);
}

void stop()
{
    analogWrite(speedPin, 128);
}

void leftrightRelease()
{
    analogWrite(steerPin, 128);
}

void resetMotor()
{
    analogWrite(speedPin, 128);
    analogWrite(steerPin, 128);
}