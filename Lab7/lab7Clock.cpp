#include <cassert>
#include "lab7Clock.h"

// PUBLIC FUNCTIONS:
Clock::Clock(int sec)
{
  if (sec < 0)
  {
    hour = 0;
    minute = 0;
    second = 0;
    return;
  }
  sec_to_hms(sec);
}

Clock::Clock(int hr, int min, int sec)
{
  if( ((hr<0)||(min<0)||(sec<0)) || ((hr>23)||(min>59)||(sec>59)))
  {
    hour = 0;
    minute = 0;
    second = 0;
  }
  else
  {
    hour = hr;
    minute = min;
    second = sec;
  }
}

void Clock::set_second(int sec)
{
  if(sec < 0 || sec > 59)
    return;
  second = sec;
}
void Clock::set_minute(int min)
{
  if(min < 0 || min > 59)
    return;
  minute = min;
}
void Clock::set_hour(int hr)
{
  if(hr < 0 || hr > 23)
    return;
  hour = hr;
}

void Clock::add_seconds(int sec)
{
  assert(sec >= 0);
  sec_to_hms(hms_to_sec() + sec);
}

// PRIVATE FUNCTIONS

void Clock::sec_to_hms(int inputSec)
{
  while(inputSec < 0) // make inputSec positive
    inputSec += 86400;

  while(inputSec >= 86400)
    inputSec %= 86400;

  hour = inputSec/3600;
  minute = (inputSec % 3600) / 60;
  second = (inputSec % 3600) % 60;
}