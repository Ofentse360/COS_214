#include "BreadthFirstIterator.h"
#include "FarmComposite.h"
// Constructor: Initializes the queue with the root farm composite
BreadthFirstIterator::BreadthFirstIterator(FarmComposite* root) {
    if (root) {
        farmQueue.push(root);  // Push the root node to the queue
        currentFarmUnit = nullptr;
    }
}

// Returns the first farm unit in the traversal (root)
FarmUnit* BreadthFirstIterator::firstFarm() {
    if (!farmQueue.empty()) {
        currentFarmUnit = farmQueue.front();
        return currentFarmUnit;
    }
    return nullptr;
}

// Moves to the next farm unit in the breadth-first traversal
void BreadthFirstIterator::next() {
    if (farmQueue.empty()) {
        currentFarmUnit = nullptr;
        return;
    }

    // Get the current farm unit and pop it from the queue
    FarmUnit* farmUnit = farmQueue.front();
    farmQueue.pop();

    // Get the children of the current farm unit (if it's a composite unit)
    FarmComposite* composite = dynamic_cast<FarmComposite*>(farmUnit);
    if (composite) {
        // Push all children of this composite farm unit onto the queue
        std::vector<FarmUnit*> children = composite->getChildren();
        for (FarmUnit* child : children) {
            farmQueue.push(child);
        }
    }

    // Update the current farm unit to the new front of the queue
    if (!farmQueue.empty()) {
        currentFarmUnit = farmQueue.front();
    } else {
        currentFarmUnit = nullptr;
    }
}

// Checks if the traversal is complete (i.e., the queue is empty)
bool BreadthFirstIterator::isDone() {
    return farmQueue.empty();
}

// Returns the current farm unit in the traversal
FarmUnit* BreadthFirstIterator::currentFarm() {
    return currentFarmUnit;
}
