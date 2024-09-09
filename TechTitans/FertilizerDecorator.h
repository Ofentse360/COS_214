#ifndef FERTILIZERDECORATOR_H
#define FERTILIZERDECORATOR_H

#include "FarmDecorator.h" // Include the base FarmDecorator class
#include "FarmUnit.h"      // Include FarmUnit for reference

class FertilizerDecorator : public FarmDecorator {
public:
    // Constructor to initialize the decorator with a FarmUnit to decorate
    FertilizerDecorator(FarmUnit* farmUnit,std::string name);
    ~FertilizerDecorator(){};
    // Increase production by applying fertilizer
    void increaseProduction();

    // Override the harvest method to enhance the harvest with the fertilizer
    void harvest() override;
};

#endif
