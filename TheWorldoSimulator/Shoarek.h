#pragma once
#include "Entity.h"

class Shoarek : public Entity {
public:
    Shoarek() {
        name = "Shoarek";
        lifeTime = 400;
        maxSpeed = 3; // Moves 3 steps at a time
        food = "F,P";
        activityInterval = { 16 * 60, 4 * 60 }; // 06:00 to 22:00 in minutes
        socialOrganization = "Relative big groups (approx 100 entities)";
        dimensions[0] = 0.05; dimensions[1] = 0.05; dimensions[2] = 0.07;
        obstacleHeight = 0.07;
        energeticValue = 4;
    }

    void displayInfo(ConsoleManager& console) const override {
        console.updateBoardAt(x, y, getSymbol());
    }

	char getSymbol() const override {
		return 'D';
	}
};

