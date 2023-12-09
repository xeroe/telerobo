#include "motorControl.h"
#include "hoverserial.h"
#include <arduino.h>
int LeftMotorPin = 23;
int rightMotorPin = 22;
void setupMotor()
{
    /*pinMode(LeftMotorPin, OUTPUT);
    pinMode(rightMotorPin, OUTPUT);
    analogWrite(LeftMotorPin, 0);
    analogWrite(rightMotorPin, 0);*/
}

void forward()
{
    Send(1000, 1000);
}

void reverse()
{
    Send(-1000, -1000);
}

void left()
{
    Send(1000, -1000);
}

void right()
{
    Send(-1000, 1000);
}

void stop()
{
    Send(0, 0);
}

void leftrightRelease()
{
    stop();
}

void resetMotor()
{
    stop();
}