#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H

#include <iostream>
#include <queue>  // For the breadth-first traversal queue
#include "FarmIterator.h"

// Forward declaration to avoid circular dependencies
class FarmComposite;

class BreadthFirstIterator : public FarmIterator {
private:
    std::queue<FarmUnit*> farmQueue;  // Queue to manage breadth-first traversal
    FarmUnit* currentFarmUnit;

public:
    // Constructor to initialize the iterator with the root farm unit
    BreadthFirstIterator(FarmComposite* root);

    // Methods required by the iterator interface
    FarmUnit* firstFarm() override;
    void next() override;
    bool isDone() override;
    FarmUnit* currentFarm() override;
};

#endif
