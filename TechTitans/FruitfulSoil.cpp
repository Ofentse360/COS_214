#include "FruitfulSoil.h"
#include <iostream>

// Constructor for FruitfulSoil
FruitfulSoil::FruitfulSoil() :SoilStates() {
    std::cout << "Soil is now fruitful, producing maximum crops." << std::endl;
}

// Define how crops are harvested when the soil is fruitful (higher yield)
void FruitfulSoil::harvestCrops() {
    std::cout << "Crops are harvested with a high yield because the soil is fruitful!" << std::endl;
    // Logic for producing more crops under fruitful soil conditions
}

// Simulate rain on FruitfulSoil
std::string FruitfulSoil::rain() {
    std::cout << "Rain has fallen. The soil remains fruitful." << std::endl;
    // Logic for maintaining or slightly enhancing the fruitful state
    return "Rain has fallen on fruitful soil.";
}

// Return the name of this soil state
std::string FruitfulSoil::getName() {
    return "FruitfulSoil";
}

// Define the crop yield state (maximum productivity for FruitfulSoil)
void FruitfulSoil::cropYieldState() {
    std::cout << "The soil is fruitful. Expect a maximum crop yield!" << std::endl;
    // Logic for setting maximum crop yield
}
