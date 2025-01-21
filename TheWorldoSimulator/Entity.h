#pragma once
#include <string>
#include <vector>
#include "ConsoleManager.h"

class Entity {
protected:
    std::string name;
    int lifeTime;
    float maxSpeed;
    std::string food;
    std::pair<int, int> activityInterval;
    std::string socialOrganization;
    float dimensions[3];
    float obstacleHeight;
    int energeticValue;
    int x, y; // Grid position
    int prevX, prevY; // Previous position for smooth updates

public:
    Entity() : x(0), y(0), prevX(0), prevY(0) {}

    virtual void displayInfo(ConsoleManager& console) const = 0;
    virtual char getSymbol() const = 0;
    void move(const std::vector<std::vector<bool>>& obstacleGrid, int currentTime);
    virtual ~Entity() {}

    int getX() const { return x; }
    int getY() const { return y; }
    int getPrevX() const { return prevX; }
    int getPrevY() const { return prevY; }

    void setPosition(int posX, int posY);

    const std::string& getName() const {
        return name;
    }

    virtual bool canEat(const std::shared_ptr<Entity>& other) const {

        char target = other->getSymbol();
        return food.find(target) != std::string::npos; // Default behavior, overridden by predators
    }

    void eat(std::shared_ptr<Entity>& other) {
        other = nullptr; // Remove the eaten entity
    }
};
