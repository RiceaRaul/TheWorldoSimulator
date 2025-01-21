#include "Entity.h"
#include "Common.h"

void Entity::setPosition(int posX, int posY) {
    prevX = x;
    prevY = y;
    x = posX;
    y = posY;
}

void Entity::move(const std::vector<std::vector<bool>>& obstacleGrid, int currentTime) {
    if (currentTime >= activityInterval.first && currentTime <= activityInterval.second) {
        for (int i = 0; i < maxSpeed; ++i) {
            int newX = (std::max)(0, (std::min)(GRID_SIZE - 1, x + getRandomDirection()));
            int newY = (std::max)(0, (std::min)(GRID_SIZE - 1, y + getRandomDirection()));
            if (!obstacleGrid[newX][newY]) {
                prevX = x;
                prevY = y;
                x = newX;
                y = newY;
            }
        }
    }
}

