#include <iostream>
#include <vector>
#include <unordered_set>

// Structure to represent a plant
struct Plant {
    std::string name;
    int growthPattern; // Growth pattern value (e.g., height, spread)
    int sunlightExposure; // Sunlight exposure value (e.g., full sun, partial shade)
    std::unordered_set<std::string> companionPlants; // Set of companion plants
};

// Function to calculate the optimal layout using dynamic programming
std::vector<std::string> optimizeGardenLayout(const std::vector<Plant>& plants, int gardenSize) {
    int numPlants = plants.size();

    // Create a 2D table to store the optimal arrangement values
    std::vector<std::vector<int> > dp(numPlants + 1, std::vector<int>(gardenSize + 1, 0));

    // Iterate over each plant
    for (int i = 1; i <= numPlants; ++i) {
        // Iterate over each possible garden size
        for (int j = 1; j <= gardenSize; ++j) {
            // Check if the current plant can fit in the garden size
            if (plants[i - 1].growthPattern <= j) {
                // Calculate the maximum value of including or excluding the current plant
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - plants[i - 1].growthPattern] + plants[i - 1].sunlightExposure);

                // Check companion plants
                for (int k = i - 2; k >= 0; --k) {
                    if (plants[k].companionPlants.count(plants[i - 1].name)) {
                        int remainingGardenSize = j - plants[i - 1].growthPattern;
                        if (remainingGardenSize >= 0) {
                            int valueWithCompanion = dp[k][remainingGardenSize] + plants[i - 1].sunlightExposure;
                            dp[i][j] = std::max(dp[i][j], valueWithCompanion);
                        }
                    }
                }
            }
            else {
                // If the current plant cannot fit, consider the previous best arrangement
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Backtrack to find the optimal layout
    std::vector<std::string> optimalLayout;
    int i = numPlants;
    int j = gardenSize;

    while (i > 0 && j > 0) {
        // If the current plant is included in the optimal arrangement
        if (dp[i][j] != dp[i - 1][j]) {
            optimalLayout.push_back(plants[i - 1].name);
            j -= plants[i - 1].growthPattern;
        }

        i--;
    }

    return optimalLayout;
}

// Function to prompt the user for plant information
Plant getPlantInfo() {
    Plant plant;
    std::cout << "Enter the plant name: ";
    std::cin >> plant.name;
    std::cout << "Enter the growth pattern value (e.g., height, spread): ";
    std::cin >> plant.growthPattern;
    std::cout << "Enter the sunlight exposure value (e.g., full sun, partial shade): ";
    std::cin >> plant.sunlightExposure;

    std::cout << "Enter the number of companion plants: ";
    int numCompanions;
    std::cin >> numCompanions;
    std::cout << "Enter the names of companion plants (separated by spaces): ";
    for (int i = 0; i < numCompanions; ++i) {
        std::string companion;
        std::cin >> companion;
        plant.companionPlants.insert(companion);
    }

    return plant;
}

// Function to calculate the total sunlight exposure
int calculateTotalSunlightExposure(const std::vector<Plant>& plants, const std::vector<std::string>& optimalLayout) {
    int totalSunlightExposure = 0;
    for (const std::string& plant : optimalLayout) {
        for (const Plant& p : plants) {
            if (p.name == plant) {
                totalSunlightExposure += p.sunlightExposure;
                break;
            }
        }
    }
    return totalSunlightExposure;
}

// Function to display plant details
void displayPlantDetails(const std::vector<Plant>& plants, const std::string& plantName) {
    for (const Plant& plant : plants) {
        if (plant.name == plantName) {
            std::cout << "Plant Name: " << plant.name << std::endl;
            std::cout << "Growth Pattern Value: " << plant.growthPattern << std::endl;
            std::cout << "Sunlight Exposure Value: " << plant.sunlightExposure << std::endl;
            std::cout << "Companion Plants: ";
            for (const std::string& companion : plant.companionPlants) {
                std::cout << companion << " ";
            }
            std::cout << std::endl;
            return;
        }
    }
    std::cout << "Plant not found!" << std::endl;
}

int main() {
    // Prompt the user for garden size
    int gardenSize;
    std::cout << "Enter the garden size: ";
    std::cin >> gardenSize;

    // Prompt the user for plant information
    std::vector<Plant> plants;
    int numPlants;
    std::cout << "Enter the number of plants: ";
    std::cin >> numPlants;
    for (int i = 0; i < numPlants; ++i) {
        std::cout << "\nEnter details for Plant " << i + 1 << ":\n";
        Plant plant = getPlantInfo();
        plants.push_back(plant);
    }

    // Calculate the optimal garden layout
    std::vector<std::string> optimalLayout = optimizeGardenLayout(plants, gardenSize);

    // Display the optimal layout
    std::cout << "\nOptimal Garden Layout:\n";
    if (optimalLayout.empty()) {
        std::cout << "No plants can fit in the given garden size.\n";
    }
    else {
        for (const std::string& plant : optimalLayout) {
            std::cout << plant << std::endl;
        }

        // Calculate and display the total sunlight exposure
        int totalSunlightExposure = calculateTotalSunlightExposure(plants, optimalLayout);
        std::cout << "Total Sunlight Exposure: " << totalSunlightExposure << std::endl;

        // Prompt the user to display plant details
        std::cout << "\nEnter the name of a plant to display its details (or 'q' to quit): ";
        std::string input;
        while (std::cin >> input && input != "q") {
            displayPlantDetails(plants, input);
            std::cout << "\nEnter the name of another plant (or 'q' to quit): ";
        }
    }

    return 0;
}
