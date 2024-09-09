#include "DeliveryTruck.h"
#include <iostream>

// Constructor for DeliveryTruck
DeliveryTruck::DeliveryTruck(int capacity,const std::string& location) 
: TruckSystemObserver(capacity,location){
    std::cout << "Delivery Truck created." << std::endl;
}

// Start the truck's engine (implementation)
void DeliveryTruck::startEngine() {
    std::cout << "Delivery Truck engine started!" << std::endl;
}

// Update method (observer pattern) - notifies the truck when storage is full
void DeliveryTruck::update(FarmUnit* farmUnit) {
    // Logic for when the DeliveryTruck is notified
    std::cout << "Delivery Truck notified about a change in the farm unit: " 
              << farmUnit->getName() << std::endl;

    // You could add more complex logic here, such as:
    // If the storage is nearing capacity, the truck should collect crops
    if (farmUnit->getTotalCapacity() < 10) { // Arbitrary threshold
        std::cout << "Storage is near capacity. Preparing to collect crops!" << std::endl;
        startEngine();
        // Perform other actions such as collecting crops
    }
}


void DeliveryTruck::notifyStorageFull() {
        std::cout << "Storage is full. Collecting crops." << std::endl;
        startEngine();
        // Additional logic to handle crop collection can go here
    }