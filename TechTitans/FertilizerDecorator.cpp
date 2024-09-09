#include "FertilizerDecorator.h"
#include <iostream>

// Constructor for FertilizerDecorator
FertilizerDecorator::FertilizerDecorator(FarmUnit* farmUnit,std::string name) : FarmDecorator(farmUnit,name) {}

// Increase production by applying fertilizer
void FertilizerDecorator::increaseProduction() {
    std::cout << "Fertilizer applied! Production increased." << std::endl;
    // Implement specific logic to modify the farmUnit's state
}

// Override the harvest method to account for increased production
void FertilizerDecorator::harvest() {
    std::cout << "Harvesting with enhanced production due to fertilizer!" << std::endl;
    farmUnit->harvest();  // Call the base unit's harvest method (from the decorated object)
    // Add additional logic to account for the increased production
}
