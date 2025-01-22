#pragma once
#include <vector>
#include "SimulationTime.h"
#include "ConsoleManager.h"
#include "Entity.h"
#include "Common.h"
#include <thread>
#include <chrono>
#include <algorithm>
#include "EntityFactory.h"

class Environment {
private:
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::vector<bool>> obstacleGrid;
    SimulationTime simTime;
    ConsoleManager console;

    void initializeObstacles();

    void addRandomEntities(const std::string& entityType, int minCount, int maxCount) {
        int count = minCount + std::rand() % (maxCount - minCount + 1);
        for (int i = 0; i < count; ++i) {
            addEntity(EntityFactory::createEntity(entityType));
        }
    }

    Environment() {
        srand(time(0));
        console.saveOriginalFont();
        console.setBoardFont(16);
        initializeObstacles();
		simTime = SimulationTime();
    } // Private constructor for Singleton

public:
    static Environment& getInstance() {
        static Environment instance;
        return instance;
    }

    void addEntity(const std::shared_ptr<Entity>& entity);

    void initializeEntities();


    void simulateDay();
    
   
    void randomEntityes() {
        addRandomEntities("Rhaptor", 1, 1);  // Always 1 Rhaptor
        addRandomEntities("Katzel", 1, 3);   // 1-3 Katzel
        addRandomEntities("Pysika", 1, 3);   // 1-3 Pysika
        addRandomEntities("Shoarek", 1, 5);  // 1-5 Shoarek
        addRandomEntities("Fournika", 1, 10);// 1-10 Fournika
        addRandomEntities("Plantha", 1, 10); // 1-10 Plantha
    }



    // Delete copy constructor and assignment operator
    Environment(const Environment&) = delete;
    Environment& operator=(const Environment&) = delete;
};

