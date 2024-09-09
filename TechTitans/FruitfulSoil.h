#ifndef FRUITFULSOIL_H
#define FRUITFULSOIL_H

#include "SoilStates.h" // Include the base class SoilStates
#include <string>       // For std::string

class FruitfulSoil : public SoilStates {
public:
    // Constructor
    FruitfulSoil();

    // Implementations for the abstract methods in SoilStates
    void harvestCrops() override;
    std::string rain() override;
    std::string getName() override;
    void cropYieldState() override;
};

#endif
