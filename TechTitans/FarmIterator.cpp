#include "FarmIterator.h"
#include <vector>

class CompositeIterator : public FarmIterator {
private:
    std::vector<FarmUnit*> farmUnits; // List of farm units to iterate over
    size_t currentIndex;              // Current position in the iteration

public:
    // Constructor that initializes the iterator with a list of farm units
    CompositeIterator(const std::vector<FarmUnit*>& farmUnits) 
        : farmUnits(farmUnits), currentIndex(0) {}

    // Returns the first farm unit
    FarmUnit* firstFarm() override {
        if (!farmUnits.empty()) {
            currentIndex = 0;
            return farmUnits[currentIndex];
        }
        return nullptr;  // If no farm units are present
    }

    // Moves to the next farm unit
    void next() override {
        if (currentIndex < farmUnits.size()) {
            currentIndex++;
        }
    }

    // Checks if the iteration is done
    bool isDone() override {
        return currentIndex >= farmUnits.size();
    }

    // Returns the current farm unit
    FarmUnit* currentFarm() override {
        if (currentIndex < farmUnits.size()) {
            return farmUnits[currentIndex];
        }
        return nullptr;
    }
};
