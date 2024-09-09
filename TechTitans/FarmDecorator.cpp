#include "FarmDecorator.h"


// Constructor for FarmDecorator
FarmDecorator::FarmDecorator(FarmUnit* farm,const std::string name) : FarmUnit(name) {
    farmUnit = farm;
}

// Override the getTotalCapacity method
int FarmDecorator::getTotalCapacity() const{
    // Forward the call to the decorated farm unit
    return farmUnit->getTotalCapacity();
}

// Override the getCropType method
std::string FarmDecorator::getCropType() const{
    // Forward the call to the decorated farm unit
    return farmUnit->getCropType();
}

// Override the getSoilStateName method
SoilStates* FarmDecorator::getSoilStateName() const{
    // Forward the call to the decorated farm unit
    return farmUnit->getSoilStateName();
}
