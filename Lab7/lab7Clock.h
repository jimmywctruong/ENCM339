#ifndef lab7Clock
#define lab7Clock

class Clock {

public:
  Clock(): hour(0), minute(0), second(0) {}
  Clock(int sec);
  Clock(int hr, int min, int sec);

  int get_second() const {return second;}
  int get_minute() const {return minute;}
  int get_hour() const {return hour;}

  void set_second(int sec);
  // PROMISES: if sec < 0 || sec > 59, does nothing
  // else, sets the internal second to sec.
  void set_minute(int min);
  // PROMISES: if min < 0 || min > 59, does nothing
  // else, sets the internal minute to min.
  void set_hour(int hr);
  // PROMISES: if hr < 0 || hr > 23, does nothing
  // else, sets the internal hour to hr.

  void increment(){sec_to_hms(hms_to_sec() + 1);}
  // PROMISES: Increments the internal clock by 1 second
  void decrement(){sec_to_hms(hms_to_sec() - 1);}
  // PROMISES: Decrements the internal clock by 1 second.

  void add_seconds(int sec);
  // REQUIRES: sec >= 0
  // PROMISES: Updates the clock by adding sec to the clock and
  // applying rollover rules

private:
  int hour, minute, second;
  int hms_to_sec() const {return hour*3600 + minute*60 + second;}
  // PROMISES: Returns the current internal clock time in seconds
  void sec_to_hms(int inputSec);
  // PROMISES: Converts the inputSec to hours, minutes, and seconds
  // and replaces the current time with the converted time
};

#endif