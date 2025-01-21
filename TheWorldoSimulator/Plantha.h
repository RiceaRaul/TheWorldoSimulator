#pragma once
#include "Entity.h"
class Plantha : public Entity {
public:
    Plantha() {
        name = "Plantha";
        lifeTime = 10000;
        maxSpeed = 0; // Moves 3 steps at a time
        food = "";
        activityInterval = { 0 * 60, 0 * 60 }; // 06:00 to 22:00 in minutes
        socialOrganization = "Relative big groups (approx 200 entities)";
        dimensions[0] = 0.3; dimensions[1] = 0.3; dimensions[2] = 0.3;
        obstacleHeight = 0;
        energeticValue = 1;
    }

    void displayInfo(ConsoleManager& console) const override {
        console.updateBoardAt(x, y, getSymbol());
    }

    char getSymbol() const override {
        return 'F';
    }
};


