#include "ExtraBarnDecorator.h"


// Constructor to initialize the decorated farm unit and the extra capacity
ExtraBarnDecorator::ExtraBarnDecorator(FarmUnit* decoratedFarmUnit, int extraCapacity,std::string name)
    : FarmDecorator(decoratedFarmUnit,name), extraCapacity(extraCapacity) {
    std::cout << "Extra barn added with capacity: " << extraCapacity << std::endl;
}

// Override the getLeftoverCapacity method to include the extra barn's capacity
int ExtraBarnDecorator::getTotalCapacity() const{
    // Get the leftover capacity from the base farm unit and add the extra capacity
    return extraCapacity;
}
