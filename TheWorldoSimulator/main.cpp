#include <iostream>
#include "EntityFactory.h"
#include "Environment.h"


void displaySplashScreen() {
    system("cls"); // Clear screen (use "clear" on Linux)
    std::cout << "==================================================\n";
    std::cout << "            Welcome to the Worldo Simulator       \n";
    std::cout << "==================================================\n\n";
    std::cout << "We imagine a land from nowhere on a living nonamed flat planet. \n";
    std::cout << "Here the living entities are differentiated by what they eat, \n";
    std::cout << "how they move, and the space they occupy. The entities also have \n";
    std::cout << "specific activity periods and social organizations.\n\n";
    std::cout << "Species on the planet:\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "Rhaptor (A)   - Life Time: 100, Max Speed: 50, Food: B, C, D, E\n";
    std::cout << "Katzel (B)    - Life Time: 700, Max Speed: 40, Food: C, D, E\n";
    std::cout << "Pysika (C)    - Life Time: 800, Max Speed: 40, Food: D, E\n";
    std::cout << "Shoarek (D)   - Life Time: 400, Max Speed: 30, Food: E\n";
    std::cout << "Fournika (E)  - Life Time: 100, Max Speed: 5,  Food: F\n";
    std::cout << "Plantha (F)   - Life Time: 10000, Max Speed: 0, Food: None\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "Other environment elements include:\n";
    std::cout << "- Obstacles (fixed/movable)\n";
    std::cout << "- Food resources (fixed/movable)\n";
    std::cout << "- Land with altitude and movement borders\n";
    std::cout << "- Decorative objects\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "Initial Conditions:\n";
    std::cout << "- Obstacles and food resources placed randomly\n";
    std::cout << "- Entities: 1 Rhaptor, 1-3 Katzel, 1-3 Pysika,\n";
    std::cout << "  1-5 Shoarek, 1-10 Fournika, 1-10 Plantha.\n\n";
    std::cout << "==================================================\n\n";
}

// Function to ask the user if they want to start the simulation
bool askToStartSimulation() {
    char choice;
    do {
        std::cout << "Do you want to start the simulation? (y/n): ";
        std::cin >> choice;
        choice = std::tolower(choice); // Ensure input is case-insensitive
    } while (choice != 'y' && choice != 'n');
    return choice == 'y';
}

int main() {
    // Display the splash screen
    displaySplashScreen();

    // Ask the user if they want to start
    if (!askToStartSimulation()) {
        std::cout << "\nExiting the simulation. Goodbye!\n";
        return 0;
    }

    // Seed random number generator
    std::srand(static_cast<unsigned>(std::time(0)));

    // Get singleton environment instance
    Environment& env = Environment::getInstance();

    // Add random entities to the environment
    env.randomEntityes();

    // Initialize entity positions
    env.initializeEntities();

    // Simulate a day
    env.simulateDay();

    return 0;
}