#pragma once
#include "Environment.h"
#include "EntityFactory.h"

const int GRID_SIZE = 30;
const int OBSTACLE_COUNT = 30; // Number of obstacles

// Utility for random movement
inline  int getRandomDirection() {
    return (rand() % 3) - 1; // -1, 0, or 1
}


