#include "FarmComposite.h"
#include <algorithm>
// using namespace std;

// Constructor for FarmComposite
FarmComposite::FarmComposite(const std::string& type) : FarmUnit(type){}

// Add a farm unit to the composite
void FarmComposite::addFarmUnit(FarmUnit* unit) {
    farmUnits.push_back(unit);
}



// Remove a farm unit from the composite
void FarmComposite::removeFarmUnit(FarmUnit* unit) {
    auto it = std::find(farmUnits.begin(), farmUnits.end(), unit);
    if (it != farmUnits.end()) {
        farmUnits.erase(it);
    }
}


// Return all child farm units
std::vector<FarmUnit*> FarmComposite::getChildren() {
    return farmUnits;
}

// Calculate the total capacity by summing the capacities of all farm units
int FarmComposite::getTotalCapacity() const{
    int totalCapacity = 0;
    for (FarmUnit* unit : farmUnits) {
        totalCapacity += unit->getTotalCapacity();
    }
    return totalCapacity;
}

// Get the crop type (this could be specific to the farm units, adjust accordingly)
std::string FarmComposite::getCropType() const{
    if (!farmUnits.empty()) {
        return farmUnits[0]->getCropType(); // Just return the crop type of the first farm unit
    }
    return "No Crop";
}

// Get the soil state name (this could be specific to the farm units, adjust accordingly)
SoilStates* FarmComposite::getSoilStateName() const{
    if (farmUnits.empty()) {
        return nullptr; // No farm units available
    }

    // Iterate through all farm units and check their soil states
    for (FarmUnit* unit : farmUnits) {
        SoilStates* soilState = unit->getSoilStateName();
        // Logic to check or aggregate soil state (this is just an example)
        if (soilState->getName() == "DrySoil") {
            return soilState; // Return if any unit has DrySoil (customize this logic)
        }
    }

    // Default to the first unit's soil state if no special condition is met
    return farmUnits[0]->getSoilStateName();
}


// Create an iterator (assumes different iterator types like breadth-first, depth-first exist)
FarmIterator* FarmComposite::createIterator(const std::string& type) {
    if (type == "breadth-first") {
        return new BreadthFirstIterator(this);
    } else if (type == "depth-first") {
        return new DepthFirstIterator(this);
    }
    return nullptr;
}
