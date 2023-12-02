#include "main.h"
#include "motorControl.h"
#include <ArduinoOTA.h>
void setup(void)
{

  setupWebserver();
  setupGui();
  setupMotor();
}

void loop(void)
{
  webserverLoop();
  guiLoop();
  ArduinoOTA.handle();
}
