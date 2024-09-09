#include "DepthFirstIterator.h"
#include "FarmComposite.h"
// Constructor to initialize the stack with the root farm unit
DepthFirstIterator::DepthFirstIterator(FarmComposite* root) {
    if (root) {
        farmStack.push(root);  // Push the root node to the stack
        currentFarmUnit = nullptr;
    }
}
// Return the first farm unit (root) in the depth-first traversal
FarmUnit* DepthFirstIterator::firstFarm() {
    if (!farmStack.empty()) {
        currentFarmUnit = farmStack.top(); // Top of the stack is the first farm unit
        return currentFarmUnit;
    }
    return nullptr; // If stack is empty, return nullptr
}

// Move to the next farm unit in the traversal
void DepthFirstIterator::next() {
    if (!farmStack.empty()) {
        currentFarmUnit = farmStack.top(); // Get the current farm unit
        farmStack.pop();                   // Remove the current farm unit from the stack

        // Push all the children of the current farm unit onto the stack
        // Assuming getChildren() returns a vector of FarmUnit*
        std::vector<FarmUnit*> children = currentFarmUnit->getChildren();
        for (auto it = children.rbegin(); it != children.rend(); ++it) {
            farmStack.push(*it); // Push each child onto the stack (reverse order for DFS)
        }
    }
}

// Check if the traversal is done (stack is empty)
bool DepthFirstIterator::isDone() {
    return farmStack.empty();
}

// Return the current farm unit being processed
FarmUnit* DepthFirstIterator::currentFarm() {
    return currentFarmUnit;
}
