#include "gui.h"
#include "motorControl.h"
#include "ultrasonic.h"
int statusLabelId;
int graphId;
int millisLabelId;
int testSwitchId;

void padExample(Control *sender, int value)
{
    switch (value)
    {
    case P_LEFT_DOWN:
        Serial.print("left down");
        left();
        break;

    case P_LEFT_UP:
        leftrightRelease();
        Serial.print("left up");

        break;

    case P_RIGHT_DOWN:
        right();
        Serial.print("right down");
        break;

    case P_RIGHT_UP:
        leftrightRelease();
        Serial.print("right up");
        break;

    case P_FOR_DOWN:
        forward();
        Serial.print("for down");
        break;

    case P_FOR_UP:
        stop();
        Serial.print("for up");
        break;

    case P_BACK_DOWN:
        reverse();
        Serial.print("back down");
        break;

    case P_BACK_UP:
        stop();
        Serial.print("back up");
        break;

    case P_CENTER_DOWN:
        resetMotor();
        Serial.print("center down");
        break;

    case P_CENTER_UP:
        resetMotor();
        Serial.print("center up");
        break;
    }

    Serial.print(" ");
    Serial.println(sender->id);
}

void setupGui()
{
    ESPUI.setVerbosity(Verbosity::VerboseJSON);
    Serial.begin(115200);

    ESPUI.pad("Pad without center", &padExample, ControlColor::Carrot);

    /*
     * .begin loads and serves all files from PROGMEM directly.
     * If you want to serve the files from LITTLEFS use ESPUI.beginLITTLEFS
     * (.prepareFileSystem has to be run in an empty sketch before)
     */

    // Enable this option if you want sliders to be continuous (update during move) and not discrete (update on stop)
    // ESPUI.sliderContinuous = true;

    /*
     * Optionally you can use HTTP BasicAuth. Keep in mind that this is NOT a
     * SECURE way of limiting access.
     * Anyone who is able to sniff traffic will be able to intercept your password
     * since it is transmitted in cleartext. Just add a string as username and
     * password, for example begin("ESPUI Control", "username", "password")
     */
    // ESPUI.sliderContinuous = true;

    graphId = ESPUI.graph("Graph Test", ControlColor::Wetasphalt);

    ESPUI.begin("TeleRobo Control");
    Serial.println(WiFi.getMode() == WIFI_AP ? WiFi.softAPIP() : WiFi.localIP());
}

void guiLoop()
{
    static long oldTime = 0;
    static bool testSwitchState = false;
    delay(30);
    return;

    if (millis() - oldTime > 100)
    {

        int distance = readUltrasonic();
        ESPUI.addGraphPoint(graphId, distance);

        oldTime = millis();
    }
}