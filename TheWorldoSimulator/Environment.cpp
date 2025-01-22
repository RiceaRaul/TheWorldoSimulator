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
        std::cout << "Day " << simTime.getCurrentDay() << " Time: " << simTime.getTimeString() << "\n\n";

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
        std::cout << "E - Fournika - " << fournikaCount << "\n";
        std::cout << "F - Plantha  - " << planthaCount << "\n\n";

        char gridObsacle = 178;
        // Clear the grid
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (obstacleGrid[i][j]) {
                    grid[i][j] = gridObsacle;
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

    system("cls");
    std::cout << "The day has ended.\n\n";
    std::cout << "Remaining entities:\n";
    for (const auto& entity : entities) {
        std::cout << "- " << entity->getName() << " at (" << entity->getX() << ", " << entity->getY() << ")\n";
    }
    std::cout << "\nTotal remaining entities: " << entities.size() << "\n";

    // Ask user for next action
    char choice;
    do {
        std::cout << "\nWhat would you like to do?\n";
        std::cout << "1. Start a new day with the current entities.\n";
        std::cout << "2. Start a new day with new entities.\n";
        std::cout << "3. Exit simulation.\n";
        std::cout << "Enter your choice (1/2/3): ";
        std::cin >> choice;
    } while (choice != '1' && choice != '2' && choice != '3');

    switch (choice) {
    case '1':
		simTime.resetTime(); // Reset days for a new day
        simulateDay();
        break;
    case '2': {
        entities.clear(); // Clear current entities
        Environment& env = Environment::getInstance();
        env.randomEntityes();
        initializeEntities(); // Initialize new entities
        simTime = SimulationTime(); // Reset time for a new day
        simulateDay();
        break;
    }
    case '3':
        std::cout << "Exiting simulation. Goodbye!\n";
        return;
    }

    console.setOriginalFont();
}