// servo 16 & 17
/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/
#include <Arduino.h>
#include <ESP32Servo.h>

Servo myservo; // create Servo object to control a servo
// twelve Servo objects can be created on most boards

int pos = 0; // variable to store the servo position
int lastmillis = 0;
void ServoSetup()
{
    // Allow allocation of all timers
    ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);
    myservo.setPeriodHertz(50);     // standard 50 hz servo
    myservo.attach(16, 1000, 2000); // attaches the servo on pin 18 to the servo object
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
