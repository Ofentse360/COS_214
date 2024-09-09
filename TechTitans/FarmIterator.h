#ifndef FARMITERATOR_H
#define FARMITERATOR_H

#include "FarmUnit.h"  // Include the necessary class FarmUnit

class FarmIterator {
public:
    // Pure virtual functions (must be implemented by derived classes)
    virtual FarmUnit* firstFarm() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual FarmUnit* currentFarm() = 0;

    // Default constructor
    FarmIterator() = default;
    
    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~FarmIterator() = default;
};

#endif
