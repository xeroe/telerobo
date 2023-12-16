#include "main.h"
#include "motorControl.h"
#include "ota.h"
#include "hoverserial.h"

#include <ArduinoOTA.h>

void setup(void)
{
  serialSetup();
  setupWebserver();
  setupGui();
  setupMotor();
  setupOTA();
}

void loop(void)
{
  ArduinoOTA.handle();
  webserverLoop();
  guiLoop();
  updateSerial();
}
