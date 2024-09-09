#ifndef FARMDECORATOR_H
#define FARMDECORATOR_H

#include "FarmUnit.h"

class FarmDecorator : public FarmUnit {
protected:
    FarmUnit* farmUnit;  // Pointer to the farm unit being decorated

public:
    // Constructor that takes a FarmUnit to decorate
    FarmDecorator(FarmUnit* farmUnit,std::string name);

    // Override FarmUnit methods to add extra behavior or forward calls to the farmUnit
    int getTotalCapacity() const override;
    std::string getCropType() const override;
    SoilStates* getSoilStateName() const override;
};

#endif
