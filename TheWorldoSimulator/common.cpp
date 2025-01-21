// Grid dimensions
#pragma once
#include <stdlib.h>

const int GRID_SIZE = 20;
const int OBSTACLE_COUNT = 30; // Number of obstacles

// Utility for random movement
int getRandomDirection() {
    return (rand() % 3) - 1; // -1, 0, or 1
}