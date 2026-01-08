#include "Arduino.h"
#include "mdb_timer.h"

//mdb_timer::mdb_timer() {                                        // Constructor (defaults to LOW = milliseconds resolution)
//	_resolution = LOW;                                          // Store the resolution
//	_startTime = millis();                                      // Set the start time as now (milliseconds)
//	_lastTime = _startTime;                                     // Save the start time as the last time
//}

//mdb_timer::mdb_timer(int resolution) {                          // Constructor (HIGH = microseconds, LOW = milliseconds)
//	_resolution = resolution;                                   // Store the resolution
//	_startTime = currentTime();                                 // Get and Set the start time
//	_lastTime = _startTime;                                     // Save the start time as the last time
//}

//mdb_timer::mdb_timer() : mdb_timer(MILLISECONDS) {}
void mdb_timer::begin() {
	_startTime = currentTime();                                 // Get and Set the start time
	_lastTime = _startTime;                                     // Save the start time as the last time
}


unsigned long mdb_timer::readTimer() {                          // Public function to read the elapsed time since constructor or reset
	_currentTime = currentTime();                               // Set the current time
 	_lastTime = _currentTime;                                   // Update last time to current time
	return (_currentTime - _startTime);                         // Return the elapsed time between the current time and the start time
}

unsigned long mdb_timer::elapsedTime() {                        // Public function to read the elapsed time from the last read, elapsedTime, timeElapsed or reset
	_currentTime = currentTime();                               // Set the current time
 	_lastTime = _currentTime;                                   // Update last time to current time
	return (_currentTime - _lastTime);                          // Return the elapsed time between current time and last time
}

bool mdb_timer::timeElapsed (unsigned long targetTime) {        // Public function to check if a certain amount of time has elapsed. If it has, the timer is reset
	_targetTime = targetTime;                                   // Save the target time
	_currentTime = currentTime();                               // Set the current time
 	_lastTime = _currentTime;                                   // Update last time to current time
	if (_currentTime - _startTime >= _targetTime) {             // If the target time has elapsed
		_startTime = _currentTime;                              // Reset the timer
		return (true);                                          // Return true
	} else {                                                    // If it hasn't
		return (false);                                         // return false
	}                                                           // End of If the target time has elapsed
}

void mdb_timer::resetTimer() {                                  // Public function to reset the timer
	_startTime = currentTime();                                 // Set the start time
	_lastTime = _startTime;                                     // Update the last time to start time
}

unsigned long mdb_timer::currentTime() {                        // Private function to get the current time based on the resolution
	if (_resolution == HIGH) _thisTime = micros();              // If resolution is HIGH, Set the current time as now (microseconds)
 	else _thisTime = millis();                                  // Else, Set the current time as now (milliseconds)
	return (_thisTime);                                         // Return the time
}
