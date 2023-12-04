#include "motorControl.h"
#include <arduino.h>
int LeftMotorPin = 23;
int rightMotorPin = 22;
void setupMotor()
{
    pinMode(LeftMotorPin, OUTPUT);
    pinMode(rightMotorPin, OUTPUT);
    analogWrite(LeftMotorPin, 128);
    analogWrite(rightMotorPin, 128);
}

void forward()
{
    analogWrite(LeftMotorPin, 255);
    analogWrite(rightMotorPin, 255);
}

void reverse()
{
    int brightness = 0; // how bright the LED is
    int fadeAmount = 5; // how many points to fade the LED by
    // analogWrite(LeftMotorPin, 128);
    // analogWrite(rightMotorPin, 128);
    while (1)
    {

        analogWrite(LeftMotorPin, brightness);
        analogWrite(rightMotorPin, brightness);
        // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

        // reverse the direction of the fading at the ends of the fade:
        if (brightness <= 0 || brightness >= 255)
        {
            fadeAmount = -fadeAmount;
        }
        delay(30);
    }
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
    analogWrite(LeftMotorPin, 0);
    analogWrite(rightMotorPin, 0);
}

void resetMotor()
{
    analogWrite(LeftMotorPin, 0);
    analogWrite(rightMotorPin, 0);
}