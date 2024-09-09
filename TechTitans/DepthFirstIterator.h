#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H

#include <iostream>
#include <stack> // Stack for depth-first traversal
#include "FarmIterator.h"

// Forward declaration of FarmComposite to break the circular dependency
class FarmComposite;

class DepthFirstIterator : public FarmIterator {
private:
    std::stack<FarmUnit*> farmStack;  // Stack to manage depth-first traversal
    FarmUnit* currentFarmUnit;

public:
    // Constructor to initialize the iterator with the root farm unit
    DepthFirstIterator(FarmComposite* root);

    // Methods required by the iterator interface
    FarmUnit* firstFarm() override;
    void next() override;
    bool isDone() override;
    FarmUnit* currentFarm() override;
};

#endif
