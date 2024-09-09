#ifndef TRUCKSYSTEMOBSERVER_H
#define TRUCKSYSTEMOBSERVER_H

#include <string>
#include "FarmUnit.h" // Forward declaration for FarmUnit
class FarmUnit;

class TruckSystemObserver {
protected:
    int currentLoad;    // The truck's current load
    int capacity;       // The maximum capacity of the truck
    std::string location;  // Current location of the truck

public:
    // Constructor
    TruckSystemObserver(int capacity, const std::string& location);

    // Starts the truck's engine (virtual to allow overriding)
    virtual void startEngine();

    // Pure virtual method for updating the truck (must be implemented by derived classes)
    virtual void update(FarmUnit* farmUnit) = 0;
    virtual void deliverFertilizer(){};
    // Destructor (virtual for proper cleanup in derived classes)
    virtual ~TruckSystemObserver() {}

    // Optional getter methods for accessing private attributes
    int getCurrentLoad() const;
    int getCapacity() const;
    std::string getLocation() const;

    // Optional setter methods for modifying private attributes
    void setCurrentLoad(int load);
    void setLocation(const std::string& newLocation);
};

#endif
