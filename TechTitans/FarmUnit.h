#ifndef FARMUNIT_H
#define FARMUNIT_H

#include <iostream>
#include <vector>    // For std::vector
#include <string>    // For std::string
#include "TruckSystemObserver.h"
#include "SoilStates.h"
class TruckSystemObserver;

class FarmUnit {
private:
    std::vector<TruckSystemObserver*> truckObservers;  // List of truck observers
    std::string name;  // Name of the farm unit (crop field, barn, etc.)
    std::vector<FarmUnit*> children;  // List of child farm units for composite structure

public:
    // Constructor
    FarmUnit(const std::string& name) : name(name) {}
    ~FarmUnit(){};
    // Pure virtual methods (must be implemented by derived classes)
    virtual int getTotalCapacity() const = 0;      // Add const
    virtual std::string getCropType() const = 0;   // Add const
    virtual SoilStates* getSoilStateName() const = 0; // Add const

    // Virtual harvest method that can be overridden
    virtual void harvest() {
        std::cout << "Harvesting crops in base FarmUnit." << std::endl;
    }

    // Observer pattern methods
    void attach(TruckSystemObserver* observer);
    void detach(TruckSystemObserver* observer);
    void notifyObservers();

    // Truck management methods
    void buyTruck(TruckSystemObserver* truckObserver);
    void sellTruck(TruckSystemObserver* truckObserver);
    void callTruck(const std::string& operation);

    // Composite pattern methods (for managing child farm units)
    void addChild(FarmUnit* child);
    std::vector<FarmUnit*> getChildren() const;

    // Get the name of the farm unit
    std::string getName() const;
};

#endif
