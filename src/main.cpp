#include "main.h"
#include "motorControl.h"
#include "ota.h"
#include <ArduinoOTA.h>
void setup(void)
{

  setupWebserver();
  setupGui();
  setupMotor();
  setupOTA();
}

void loop(void)
{
  webserverLoop();
  guiLoop();
  ArduinoOTA.handle();
}
