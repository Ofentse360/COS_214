#ifndef SOILSTATES_H
#define SOILSTATES_H

#include <string>

class SoilStates {
public:
    SoilStates();                     // Constructor declaration
    virtual ~SoilStates() {}           // Virtual destructor

    // Pure virtual functions
    virtual void harvestCrops() = 0;
    virtual std::string rain() = 0;
    virtual std::string getName() = 0;
    virtual void cropYieldState() = 0;
};

#endif
