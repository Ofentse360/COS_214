#include "DrySoil.h"
#include <iostream>

// Constructor for DrySoil
// Constructor must call base constructor explicitly
DrySoil::DrySoil() : SoilStates() {
    std::cout << "DrySoil state initialized." << std::endl;
}

// Define how crops are harvested when the soil is dry (minimal yield)
void DrySoil::harvestCrops() {
    std::cout << "Harvesting crops with minimal yield due to DrySoil." << std::endl;
    // Logic for harvesting crops under dry soil conditions
}

// Simulate rain on DrySoil and potentially transition to another state
std::string DrySoil::rain() {
    std::cout << "Rain has fallen. Soil may become more fertile." << std::endl;
    // Logic for transitioning to a new state, potentially changing to FruitfulSoil
    return "Rain has been applied to DrySoil.";
}

// Return the name of this soil state
std::string DrySoil::getName() {
    return "DrySoil";
}

// Define the crop yield state (minimal productivity for DrySoil)
void DrySoil::cropYieldState() {
    std::cout << "The crop yield is minimal due to DrySoil." << std::endl;
    // Logic for adjusting crop yield when soil is dry
}
