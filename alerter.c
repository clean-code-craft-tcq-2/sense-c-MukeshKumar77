#include "stats.h"
#include "alerter.h"

int emailAlertCallCount;
int ledAlertCallCount;

//counter to check if both emailAlerter, ledAlerter were called
int emailAlertFunctionCall;
int ledAlerterFunctionCall;

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
  if(computedStats.max > maxThreshold)
  {
      //call email and led Alerter
      (*alerters[0])();
      (*alerters[1])();
       
      emailAlertFunctionCall++;
      ledAlerterFunctionCall++;
  }
}

void emailAlerter()
{
    emailAlertCallCount++;
}

void ledAlerter()
{
    ledAlertCallCount++;
}
