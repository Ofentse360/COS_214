#ifndef FERTILIZERTRUCK_H
#define FERTILIZERTRUCK_H

#include "TruckSystemObserver.h"
#include "FarmUnit.h"
#include <iostream>

class FertilizerTruck : public TruckSystemObserver {
public:
    // Constructor
    FertilizerTruck(int capacity = 1000, const std::string& location = "Warehouse");

    // Starts the truck's engine and performs fertilizer delivery operations
    void startEngine() override;
    void deliverFertilizer();

    // Update method (observer pattern) to notify the truck of changes
    void update(FarmUnit* farmUnit) override;
};

#endif
