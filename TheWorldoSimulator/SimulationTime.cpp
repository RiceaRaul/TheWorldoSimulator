#include "SimulationTime.h"

//void SimulationTime::advanceTime(int minutes) {
//    currentTime = (currentTime + minutes) % END_TIME;
//    if (currentTime < START_TIME) {
//        currentTime = START_TIME; // Reset to start time after midnight
//    }
//}

void SimulationTime::advanceTime(int minutes) {
    currentTime += minutes;
    if (currentTime >= END_TIME) {
		currentDay++; // Increment the day
        dayOver = true; // Mark the day as over
        currentTime = END_TIME; // Optional: Clamp to END_TIME
    }
}

std::string SimulationTime::getTimeString() const {
    int hours = currentTime / 60;
    int minutes = currentTime % 60;
    char buffer[6];
    snprintf(buffer, sizeof(buffer), "%02d:%02d", hours, minutes);
    return std::string(buffer);
}

int SimulationTime::getTime() const {
    return currentTime;
}

bool SimulationTime::isDayOver() const {
	return dayOver;
}