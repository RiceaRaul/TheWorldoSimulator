#pragma once
#include "Entity.h"


class Katzel : public Entity {
public:
    Katzel() {
        name = "Katzel";
        lifeTime = 700;
        maxSpeed = 4; // Moves 3 steps at a time
        food = "C,D,E";
        activityInterval = { 6 * 60, 22 * 60 }; // 06:00 to 22:00 in minutes
        socialOrganization = "Relative small groups (max 10 entities)";
        dimensions[0] = 0.3; dimensions[1] = 0.7; dimensions[2] = 0.4;
        obstacleHeight = 0.35;
        energeticValue = 10;
    }

    void displayInfo(ConsoleManager& console) const override {
        console.updateBoardAt(x, y, getSymbol());
    }

    char getSymbol() const override {
        return 'B';
    }
};
