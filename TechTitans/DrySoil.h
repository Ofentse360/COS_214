#ifndef DRYSOIL_H
#define DRYSOIL_H

#include "SoilStates.h"
#include <string> // For std::string

class DrySoil : public SoilStates {
public:
    DrySoil();
    ~DrySoil(){};

    // Implementations for the abstract methods in SoilStates
    void harvestCrops() override;
    std::string rain() override;
    std::string getName() override;
    void cropYieldState() override;
};

#endif
