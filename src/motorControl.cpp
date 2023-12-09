#include "motorControl.h"
#include "hoverserial.h"
#include <arduino.h>
int LeftMotorPin = 23;
int rightMotorPin = 22;
int valueLeft, valueRight = 0;
void setupMotor()
{
    /*pinMode(LeftMotorPin, OUTPUT);
    pinMode(rightMotorPin, OUTPUT);
    analogWrite(LeftMotorPin, 0);
    analogWrite(rightMotorPin, 0);*/
}

void forward()
{
    setValues(1000, 1000);
}

void reverse()
{
    setValues(-1000, -1000);
}

void left()
{
    setValues(1000, -1000);
}

void right()
{
    setValues(-1000, 1000);
}

void stop()
{
    setValues(0, 0);
}

void leftrightRelease()
{
    stop();
}

void resetMotor()
{
    stop();
}

void setValues(int left, int right)
{
    valueLeft = left;
    valueRight = right;
}

void updateSerial()
{
    Send(valueLeft, valueRight);
}