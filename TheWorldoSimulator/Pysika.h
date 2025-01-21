#pragma once

#include "Entity.h"

class Pysika : public Entity {
public:
    Pysika() {
        name = "Pysika";
        lifeTime = 700;
        maxSpeed = 4; // Moves 3 steps at a time
        food = "D,E";
        activityInterval = { 6 * 60, 22 * 60 }; // 06:00 to 22:00 in minutes
        socialOrganization = "Small groups (max 3 entities)";
        dimensions[0] = 0.1; dimensions[1] = 0.4; dimensions[2] = 0.3;
        obstacleHeight = 0.2;
        energeticValue = 8;
    }

    void displayInfo(ConsoleManager& console) const override {
        console.updateBoardAt(x, y, getSymbol());
    }

    char getSymbol() const override {
        return 'C';
    }
};

