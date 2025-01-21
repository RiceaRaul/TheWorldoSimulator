#include "Environment.h"

void Environment::initializeObstacles() {
    obstacleGrid = std::vector<std::vector<bool>>(GRID_SIZE, std::vector<bool>(GRID_SIZE, false));
    for (int i = 0; i < OBSTACLE_COUNT; ++i) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        obstacleGrid[x][y] = true;
    }
}

void Environment::addEntity(const std::shared_ptr<Entity>& entity) {
    entities.push_back(entity);
}

void Environment::initializeEntities() {
    for (auto& entity : entities) {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (obstacleGrid[x][y]);
        entity->setPosition(x, y);
    }
}

void Environment::simulateDay() {
    const int TIME_STEP = 5; // 1 minute per simulation step

    std::vector<std::string> grid(GRID_SIZE, std::string(GRID_SIZE, '.'));

    while (!simTime.isDayOver()) {
        simTime.advanceTime(TIME_STEP); // Advance by 1 minute

        system("cls"); // Clear screen

        // Display time
        std::cout << "Time: " << simTime.getTimeString() << "\n\n";

        // Display legend
        int rhaptorCount = std::count_if(entities.begin(), entities.end(), [](const std::shared_ptr<Entity>& e) { return e->getName() == "Rhaptor"; });
        int katzelCount = std::count_if(entities.begin(), entities.end(), [](const std::shared_ptr<Entity>& e) { return e->getName() == "Katzel"; });
        int pysikaCount = std::count_if(entities.begin(), entities.end(), [](const std::shared_ptr<Entity>& e) { return e->getName() == "Pysika"; });
        int shoarekCount = std::count_if(entities.begin(), entities.end(), [](const std::shared_ptr<Entity>& e) { return e->getName() == "Shoarek"; });
        int fournikaCount = std::count_if(entities.begin(), entities.end(), [](const std::shared_ptr<Entity>& e) { return e->getName() == "Fournika"; });
        int planthaCount = std::count_if(entities.begin(), entities.end(), [](const std::shared_ptr<Entity>& e) { return e->getName() == "Plantha"; });
        std::cout << "Legend:\n";
        std::cout << "A - Rhaptor - " << rhaptorCount << "\n";
        std::cout << "B - Katzel - " << katzelCount << "\n";
        std::cout << "C - Pysika - " << pysikaCount << "\n";
        std::cout << "D - Shoarek - " << shoarekCount << "\n";
        std::cout << "E - Fournika - " << fournikaCount << "\n\n";
        std::cout << "F - Plantha  - " << planthaCount << "\n\n";

        // Clear the grid
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (obstacleGrid[i][j]) {
                    grid[i][j] = '#';
                }
                else {
                    grid[i][j] = '.';
                }
            }
        }

        // Update entity positions
        for (auto& entity : entities) {
            grid[entity->getPrevX()][entity->getPrevY()] = '.';
            entity->move(obstacleGrid, simTime.getTime());
            grid[entity->getX()][entity->getY()] = entity->getSymbol();
        }

        // Print the grid
        for (const auto& row : grid) {
            std::cout << row << "\n";
        }

        // Handle interactions
        for (size_t i = 0; i < entities.size(); ++i) {
            if (!entities[i]) continue;
            for (size_t j = 0; j < entities.size(); ++j) {
                if (i != j && entities[j] && entities[i]->canEat(entities[j])) {
                    int dist = std::abs(entities[i]->getX() - entities[j]->getX()) +
                        std::abs(entities[i]->getY() - entities[j]->getY());
                    if (dist <= 1) {
                        entities[i]->eat(entities[j]);
                    }
                }
            }
        }

        entities.erase(
            std::remove(entities.begin(), entities.end(), nullptr),
            entities.end()
        );

        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Smooth updates
    }

    console.setOriginalFont();
}