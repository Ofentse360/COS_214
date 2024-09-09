#include "FarmUnit.h"
#include <algorithm>  // For std::find

// Attach a truck observer
void FarmUnit::attach(TruckSystemObserver* observer) {
    truckObservers.push_back(observer);
}

// Detach a truck observer
void FarmUnit::detach(TruckSystemObserver* observer) {
    auto it = std::find(truckObservers.begin(), truckObservers.end(), observer);
    if (it != truckObservers.end()) {
        truckObservers.erase(it);
    }
}

// Notify all truck observers of a change
void FarmUnit::notifyObservers() {
    for (TruckSystemObserver* observer : truckObservers) {
        observer->update(this);  // Notify each truck of the change in this farm unit
    }
}

// Buy a truck and attach it to the observer list
void FarmUnit::buyTruck(TruckSystemObserver* truckObserver) {
    attach(truckObserver);
    std::cout << "Bought a truck and attached it to the farm unit." << std::endl;
}

// Sell a truck and detach it from the observer list
void FarmUnit::sellTruck(TruckSystemObserver* truckObserver) {
    detach(truckObserver);
    std::cout << "Sold a truck and detached it from the farm unit." << std::endl;
}

// Call a truck for a specific operation
void FarmUnit::callTruck(const std::string& operation) {
    std::cout << "Calling trucks for operation: " << operation << std::endl;
    notifyObservers();  // Notify trucks about the operation
}

// Add a child farm unit
void FarmUnit::addChild(FarmUnit* child) {
    children.push_back(child);
}

// Get the list of child farm units
std::vector<FarmUnit*> FarmUnit::getChildren() const {
    return children;
}

// Get the name of the farm unit
std::string FarmUnit::getName() const {
    return name;
}
