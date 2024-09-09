#include "CropField.h"
#include "DrySoil.h"
#include <algorithm> // For std::find

// Constructor to initialize the crop field
CropField::CropField(std::string cropType, int maxStorage, std::string farmName)
        : FarmUnit(farmName), cropType(cropType), maxStorage(maxStorage), currentStorageSize(0), currentSoilState(nullptr) {}


// Get the total storage capacity of the crop field
int CropField::getTotalCapacity() const {
    return maxStorage;
}

// Get the crop type (e.g., wheat, corn)
std::string CropField::getCropType() const {
    return cropType;
}

// Get the current soil state
SoilStates* CropField::getSoilStateName() const {
    return currentSoilState;
}

// Set a new soil state and notify observers
void CropField::setSoilState(SoilStates* newState) {
    currentSoilState = newState;
    notifySoilState(); // Notify observers (trucks) about the state change
}

// Attach an observer (truck) to the crop field
void CropField::attach(TruckSystemObserver* observer) {
    observers.push_back(observer);
}

// Detach an observer (truck) from the crop field

void CropField::detach(TruckSystemObserver* observer) {
    // Find the observer in the observers vector
    auto it = std::find(observers.begin(), observers.end(), observer);

    // If observer is found, erase it from the vector
    if (it != observers.end()) {
        observers.erase(it);
    }
}

// Notify all observers (trucks) about the current soil state
// Notify all observers (trucks) about the current farm unit state (not just soil state)
void CropField::notifySoilState() {
    for (TruckSystemObserver* observer : observers) {
        observer->update(this); // Pass 'this', which is a FarmUnit* (CropField*), to the observer
    }
}


void CropField::checkStorageCapacity() {
    if (currentStorageSize >= maxStorage * 0.9) { // If storage is 90% full
        for (TruckSystemObserver* truck : trucks) {
            // Attempt to cast the observer to a DeliveryTruck
            DeliveryTruck* deliveryTruck = dynamic_cast<DeliveryTruck*>(truck);
            if (deliveryTruck) {
                // Call notifyStorageFull only if it's a DeliveryTruck
                deliveryTruck->notifyStorageFull();
            }
        }
    }
}


// Trigger specific events based on the current soil state or storage capacity
// Trigger specific events based on the current soil state or storage capacity
void CropField::triggerEventsBasedOnState() {
    if (currentSoilState->getName() == "DrySoil") {
        for (TruckSystemObserver* truck : trucks) {
            truck->deliverFertilizer(); // Trigger fertilizer delivery if soil is dry
        }
    }
}
// Destructor for CropField
// CropField::~CropField() {
//     // Clean up dynamically allocated memory (if any)
//     if (currentSoilState) {
//         delete currentSoilState; // Delete the dynamically allocated SoilStates object
//         currentSoilState = nullptr; // Set the pointer to nullptr for safety
//     }

//     // Clear the observers vector (no need to delete individual pointers since CropField does not own them)
//     observers.clear();

//     // Clear the trucks vector (no need to delete individual pointers since CropField does not own them)
//     trucks.clear();
// }