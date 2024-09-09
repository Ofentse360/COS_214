#ifndef EXTRABARNDECORATOR_H
#define EXTRABARNDECORATOR_H

#include "FarmDecorator.h" // Include the FarmDecorator base class
#include "FarmUnit.h"      // Include FarmUnit for reference
#include <iostream>

class ExtraBarnDecorator : public FarmDecorator {
private:
    int extraCapacity; // Additional capacity provided by the extra barn

public:
    // Constructor to initialize the extra capacity and decorate the given farm unit
    ExtraBarnDecorator(FarmUnit* decoratedFarmUnit, int extraCapacity,std::string name);
    ~ExtraBarnDecorator(){};
    // Override the getLeftoverCapacity method to include the extra capacity
      int getTotalCapacity()const override;
    //std::string getCropType() override;
};

#endif
