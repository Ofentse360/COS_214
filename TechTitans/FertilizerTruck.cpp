#include "FertilizerTruck.h"

// Constructor for FertilizerTruck
FertilizerTruck::FertilizerTruck(int capacity, const std::string& location)
    : TruckSystemObserver(capacity, location) {
    std::cout << "Fertilizer truck created with capacity: " << capacity 
              << " and located at: " << location << std::endl;
}

// Start the truck's engine and simulate fertilizer delivery
void FertilizerTruck::startEngine() {
    std::cout << "Fertilizer Truck engine started!" << std::endl;
    std::cout << "Delivering fertilizer..." << std::endl;
    // Additional logic for delivering fertilizer can go here
}

// Override the update method (Observer pattern)
void FertilizerTruck::update(FarmUnit* farmUnit) {
    std::cout << "Fertilizer Truck notified about farm unit: " << farmUnit->getName() << std::endl;
    // Custom logic for reacting to farm updates
}

// Method to deliver fertilizer
void FertilizerTruck::deliverFertilizer() {
    std::cout << "Delivering fertilizer to the farm." << std::endl;
    startEngine();
    // Additional logic for delivering fertilizer can be added here
}