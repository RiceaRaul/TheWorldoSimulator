#pragma once
#include <vector>
#include "SimulationTime.h"
#include "ConsoleManager.h"
#include "Entity.h"
#include "Common.h"
#include <thread>
#include <chrono>
#include <algorithm>

class Environment {
private:
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::vector<bool>> obstacleGrid;
    SimulationTime simTime;
    ConsoleManager console;

    void initializeObstacles();

    Environment() {
        srand(time(0));
        console.saveOriginalFont();
        console.setBoardFont(16);
        initializeObstacles();
    } // Private constructor for Singleton

public:
    static Environment& getInstance() {
        static Environment instance;
        return instance;
    }

    void addEntity(const std::shared_ptr<Entity>& entity);

    void initializeEntities();


    void simulateDay();


    // Delete copy constructor and assignment operator
    Environment(const Environment&) = delete;
    Environment& operator=(const Environment&) = delete;
};

