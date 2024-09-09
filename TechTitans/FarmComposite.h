#ifndef FARMCOMPOSITE_H
#define FARMCOMPOSITE_H

#include <iostream>
#include <vector>  // For storing multiple farm units
#include <string>  // For string data types
#include "FarmUnit.h"
#include "FarmIterator.h"  // Assuming you have an Iterator class
#include "BreadthFirstIterator.h"
#include "DepthFirstIterator.h"

class FarmComposite : public FarmUnit {
private:
    std::vector<FarmUnit*> farmUnits;  // Collection of child farm units

public:
    // Constructor
    FarmComposite(const std::string& type);
    

    // Add and remove farm units
    void addFarmUnit(FarmUnit* unit);
    void removeFarmUnit(FarmUnit* unit);

    // Return the list of child farm units
    std::vector<FarmUnit*> getChildren();

    // FarmUnit interface implementations
    int getTotalCapacity() const override;
    std::string getCropType() const override;
    SoilStates* getSoilStateName() const override;

    // Create an iterator based on the type (e.g., breadth-first, depth-first)
     FarmIterator* createIterator(const std::string& type);
};

#endif
