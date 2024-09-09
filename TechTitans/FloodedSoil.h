#ifndef FLOODEDSOIL_H
#define FLOODEDSOIL_H

#include "SoilStates.h" // Include the base class SoilStates
#include <string>       // For std::string

class FloodedSoil : public SoilStates {
public:
    // Constructor
    FloodedSoil();
    ~FloodedSoil(){};

    // Implementations for the abstract methods in SoilStates
    void harvestCrops() override;
    std::string rain() override;
    std::string getName() override;
    void cropYieldState() override;

    // New method to apply a drainage system and change the state
    void drainageSystem();
};

#endif
