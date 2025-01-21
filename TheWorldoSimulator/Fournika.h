#pragma once
#include "Entity.h"

class Fournika : public Entity {
public:
    Fournika() {
        name = "Fournika";
        lifeTime = 100;
        maxSpeed = 0.5; // Moves 3 steps at a time
        food = "F";
        activityInterval = { 6 * 60, 18 * 60 }; // 06:00 to 22:00 in minutes
        socialOrganization = "Really big groups  (1000-2000 entities) A leader";
        dimensions[0] = 0.001; dimensions[1] = 0.001; dimensions[2] = 0.001;
        obstacleHeight = 999;
        energeticValue = 1;
    }

    void displayInfo(ConsoleManager& console) const override {
        console.updateBoardAt(x, y, getSymbol());
    }

    char getSymbol() const override {
        return 'E';
    }
};

