#pragma once
#include <string>

class SimulationTime {
private:
    int currentTime; // In minutes
    static const int START_TIME = 300; // 05:00 in minutes
    static const int END_TIME = 1440; // 00:00 in minutes

public:
    SimulationTime() : currentTime(START_TIME) {}

    void advanceTime(int minutes);

    std::string getTimeString() const;

    int getTime() const;

    bool isDayOver() const;
};
