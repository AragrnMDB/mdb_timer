# mdb_timer

This is an Arduino library that implements timers so you can eliminate the delay() function.  

To use the functions in the library include the file mdb_timer.h.  

## Constructors

There are two constructors that you can use to instantiate your timer.
- mdb_timer(int resolution); Use this to specify the resolution of the timer (LOW/MILLISECONDS or HIGH/MICROSECONDS).  
- mdb_timer(); Use this to default to LOW/MILLISECONDS resolution.  

## Functions

There are four public functions available for your timer.
- unsigned long readTimer(); This function returns the time elapsed since the timer was constructed or call to resetTimer() in the resolution of the timer.  
- unsigned long elapsedTime(); This function returns the time elapsed since the timer was constructed or call to readTimer(), elapsedTime(), timeElapsed(), or resetTimer().  
- bool timeElapsed(unsigned long targetTime); This function returns true if the specified time has elapsed since the timer was construceed or call to resetTimer(). If true, the timer is reset.
- void resetTimer(); This function resets the timer (to zero).  

## Sample code (blinks the on-board led once per second)

```` c++
    // Include for mdb_timer
    #include <mdb_timer.h>

    int led                 = 13;
    int ledState            = LOW;
    unsigned long blinkTime = 500;

    // Create the timer instance
    mdb_timer mdbTimer; // Call the default mdb_timer constructor with no parameters and therefore no ()

    void setup() {
      pinMode(led,    OUTPUT);
      digitalWrite(led, ledState);
    }

    void loop() {
      if (ledState == LOW) {
        if (mdbTimer.timeElapsed(blinkTime)) {
          ledState = HIGH;
        }
      } else {
        if (mdbTimer.timeElapsed(blinkTime)) {
          ledState = LOW;
        }
      }
      digitalWrite(led, ledState);
    }
````

## Remote repository

The remote repository for this project is hosted on GitHub at the following address: https://github.com/AragrnMDB/mdb_timer  
