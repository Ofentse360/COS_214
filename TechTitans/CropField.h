#ifndef CROPFIELD_H
#define CROPFIELD_H

#include <iostream>
#include <vector> // Use vector for lists of observers
#include "FarmUnit.h"
#include "SoilStates.h"
#include "TruckSystemObserver.h"
#include "DeliveryTruck.h"

class CropField : public FarmUnit {
private:
    SoilStates* currentSoilState;
    std::string cropType;
    int maxStorage;
    int currentStorageSize;
    std::vector<TruckSystemObserver*> observers; // List of observers (trucks)
    std::vector<TruckSystemObserver*> trucks;    // List of trucks

public:
    // Constructor to initialize the crop field
    CropField(std::string cropType, int maxStorage, std::string farmName);
    ~CropField(){
        
    };

    // Getters (overrides from FarmUnit)
    int getTotalCapacity() const override;         // Override pure virtual method
    std::string getCropType() const override;      // Override pure virtual method
    SoilStates* getSoilStateName() const override; // Override pure virtual method

    // Observer-related methods
    void attach(TruckSystemObserver* observer) ;  // Attach observer ()
    void detach(TruckSystemObserver* observer) ;  // Detach observer ()
    void notifySoilState() ;                      // Notify observers when soil state changes (override)

    // Storage-related methods
    void checkStorageCapacity();    // Check if storage capacity is near the limit
    void triggerEventsBasedOnState(); // Trigger events based on soil or storage state

    // Other methods
    void setSoilState(SoilStates* newState); // Set new soil state
};

#endif
