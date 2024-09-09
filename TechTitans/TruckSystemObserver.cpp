#include "TruckSystemObserver.h"
#include <iostream>

// Constructor for TruckSystemObserver
TruckSystemObserver::TruckSystemObserver(int capacity, const std::string& location)
    : capacity(capacity), currentLoad(0), location(location) {
    std::cout << "Truck created with capacity: " << capacity << " at location: " << location << std::endl;
}

// Start the truck's engine
void TruckSystemObserver::startEngine() {
    std::cout << "Truck engine started at location: " << location << std::endl;
}

// Getter for currentLoad
int TruckSystemObserver::getCurrentLoad() const {
    return currentLoad;
}

// Getter for capacity
int TruckSystemObserver::getCapacity() const {
    return capacity;
}

// Getter for location
std::string TruckSystemObserver::getLocation() const {
    return location;
}

// Setter for currentLoad
void TruckSystemObserver::setCurrentLoad(int load) {
    if (load <= capacity) {
        currentLoad = load;
    } else {
        std::cout << "Load exceeds truck's capacity!" << std::endl;
    }
}

// Setter for location
void TruckSystemObserver::setLocation(const std::string& newLocation) {
    location = newLocation;
}
