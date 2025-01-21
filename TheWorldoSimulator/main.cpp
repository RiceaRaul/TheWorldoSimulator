#include <iostream>
#include "EntityFactory.h"
#include "Environment.h"


void addRandomEntities(Environment& env, const std::string& entityType, int minCount, int maxCount) {
    int count = minCount + std::rand() % (maxCount - minCount + 1);
    for (int i = 0; i < count; ++i) {
        env.addEntity(EntityFactory::createEntity(entityType));
    }
}

int main() {
    // Add initial entities using the factory
    std::srand(static_cast<unsigned>(std::time(0))); // Seed random number generator


    // Get singleton environment instance
    Environment& env = Environment::getInstance();

    // Add entities with specified ranges
    addRandomEntities(env, "Rhaptor", 1, 1);  // Always 1 Rhaptor
    addRandomEntities(env, "Katzel", 1, 3);   // 1-3 Katzel
    addRandomEntities(env, "Pysika", 1, 3);   // 1-3 Pysika
    addRandomEntities(env, "Shoarek", 1, 5);  // 1-5 Shoarek
    addRandomEntities(env, "Fournika", 1, 10);// 1-10 Fournika
    addRandomEntities(env, "Plantha", 1, 10); // 1-10 Plantha
    // Initialize entity positions
    env.initializeEntities();

    // Simulate a day
    env.simulateDay();

    return 0;
}
