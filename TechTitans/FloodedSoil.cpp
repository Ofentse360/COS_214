#include "FloodedSoil.h"
#include <iostream>

// Constructor for FloodedSoil
FloodedSoil::FloodedSoil() : SoilStates(){
    // Any initialization needed for the FloodedSoil state can go here
    std::cout << "Soil is currently flooded." << std::endl;
}

// Define how crops are harvested when the soil is flooded (no harvest allowed)
void FloodedSoil::harvestCrops() {
    std::cout << "Crops cannot be harvested because the soil is flooded." << std::endl;
    // Logic for preventing crop harvest under flooded soil conditions
}

// Simulate rain on FloodedSoil and potentially worsen the flooding
std::string FloodedSoil::rain() {
    std::cout << "Rain has fallen, worsening the flooding!" << std::endl;
    // Logic for making the soil even worse
    return "Rain has worsened the flooded soil.";
}

// Return the name of this soil state
std::string FloodedSoil::getName() {
    return "FloodedSoil";
}

// Define the crop yield state (zero productivity for FloodedSoil)
void FloodedSoil::cropYieldState() {
    std::cout << "No crops are growing due to the flooded soil." << std::endl;
    // Logic for setting crop yield when soil is flooded
}

// Drainage system to alleviate the flooding and potentially transition to another state
void FloodedSoil::drainageSystem() {
    std::cout << "Applying the drainage system to reduce the flooding." << std::endl;
    // Logic for transitioning to a different state (e.g., DrySoil or FruitfulSoil)
    // For example, you could transition to a dry soil state:
    // this->setSoilState(new DrySoil());
}
