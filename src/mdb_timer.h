#ifndef mdb_timer_h
#define mdb_timer_h

#ifndef MILLISECONDS
#define MILLISECONDS LOW
#endif

#ifndef MICROSECONDS
#define MICROSECONDS HIGH
#endif

class mdb_timer {
   public:
      mdb_timer();                                              // Constructor - Defaults resolution to LOW (millisecond) resolution.                      Sets _startTime, _lastTime
      mdb_timer(int resolution);                                // Constructor - Sets resolution to LOW (MILLISECONDS) or HIGH (MICROSECONDS).             Sets _startTime, _lastTime
      unsigned long readTimer();                                // Time since call to constructor, ------------------------------  or mdb_resetTimer.      Sets             _lastTime
      unsigned long elapsedTime();                              // Time since call to constructor, mdb_elapsedTime, mdb_readTimer, or mdb_resetTimer.      Sets             _lastTime
      bool          timeElapsed (unsigned long targetTime);     // True if targetTime has elapsed, false otherwise. _startTime set if targetTime achieved. Sets _startTime, _lastTime
      void          resetTimer();                               // Reset the timer.                                                                        Sets _startTime, _lastTime
   private:
      unsigned long currentTime();                              // Private function to get the current time based on resolution
      bool          _resolution;                                // Resolution of time (HIGH = microseconds, LOW = milliseconds)
      unsigned long _startTime;                                 // The start time of this instance
      unsigned long _currentTime;                               // Current time in micro/milli seconds
      unsigned long _thisTime;                                  // Current time while being determined.
      unsigned long _lastTime;                                  // Last time of call to construction, elapsedTime, readTimer, or resetTimer
      unsigned long _targetTime;                                // The target elapsed time since _startTime
};

#endif