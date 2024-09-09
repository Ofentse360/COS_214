#ifndef DELIVERYTRUCK_H
#define DELIVERYTRUCK_H

#include <iostream>
#include "TruckSystemObserver.h" // Correct spelling
#include "FarmUnit.h"            // Include FarmUnit header

class DeliveryTruck : public TruckSystemObserver {
public:
    // Constructor
    DeliveryTruck(int capacity,const std::string& location);

    // Starts the engine of the delivery truck
    void startEngine();
     void notifyStorageFull();
    // Update method (observer pattern) to notify the truck of changes
    void update(FarmUnit* farmUnit) override;
};

#endif
