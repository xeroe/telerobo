// servo 16 & 17
/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/
#include <Arduino.h>
#include <Servo.h>

Servo myservo; // create Servo object to control a servo
// twelve Servo objects can be created on most boards

int pos = 0; // variable to store the servo position
int lastmillis = 0;
void ServoSetup()
{
    myservo.attach(16); // attaches the servo on pin 9 to the Servo object
}

void Servoloop()
{
    if (millis() < lastmillis + 15)
        return;

    lastmillis = millis();

    for (pos = 0; pos <= 180; pos += 1)
    { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos); // tell servo to go to position in variable 'pos'
                            // waits 15 ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1)
    {                       // goes from 180 degrees to 0 degrees
        myservo.write(pos); // tell servo to go to position in variable 'pos'
                            // waits 15 ms for the servo to reach the position
    }
}
