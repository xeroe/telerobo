#include "main.h"
#include "motorControl.h"
#include "ota.h"
#include "hoverserial.h"
#include <ArduinoOTA.h>

void setup(void)
{

  setupWebserver();
  setupGui();
  // setupMotor();
  setupOTA();
  serialSetup();
}

void loop(void)
{
  webserverLoop();
  guiLoop();
  serialLoop();
}
