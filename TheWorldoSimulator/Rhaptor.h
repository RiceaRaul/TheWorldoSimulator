#pragma once
#include "Entity.h"

class Rhaptor : public Entity {
public:
    Rhaptor() {
        name = "Rhaptor";
        lifeTime = 100;
        maxSpeed = 5; // Moves 5 steps at a time
        food = "B,C,D,E";
        activityInterval = { 10 * 60, 18 * 60 }; // 10:00 to 18:00 in minutes
        socialOrganization = "Independent";
        dimensions[0] = 2; dimensions[1] = 5; dimensions[2] = 2;
        obstacleHeight = 2.5;
        energeticValue = 0;
    }

    void displayInfo(ConsoleManager& console) const override {
        console.updateBoardAt(x, y, getSymbol());
    }

	char getSymbol() const override {
		return 'A';
	}
};

