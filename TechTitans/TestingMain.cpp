#include "CropField.h"
#include "FertilizerTruck.h"
#include "DeliveryTruck.h"
#include "FertilizerDecorator.h"
#include "ExtraBarnDecorator.h"
#include "DrySoil.h"
#include "FruitfulSoil.h"
#include "FarmComposite.h"
#include "FloodedSoil.h"


void testingIterators()
{
    // Create a farm composite and crop fields
    FarmComposite* mainFarm = new FarmComposite("Main Farm");
    CropField* wheatField = new CropField("Wheat", 1000, "Wheat Field");
    CropField* cornField = new CropField("Corn", 800, "Corn Field");

    mainFarm->addFarmUnit(wheatField);
    mainFarm->addFarmUnit(cornField);

    // Breadth-First Traversal
    std::cout << "Breadth-First Traversal:" << std::endl;
    BreadthFirstIterator* bfsIterator = new BreadthFirstIterator(mainFarm);
    for (FarmUnit* unit = bfsIterator->firstFarm(); !bfsIterator->isDone(); bfsIterator->next()) {
        std::cout << "- " << unit->getName() << std::endl;
    }
    delete bfsIterator;

    // Depth-First Traversal
    std::cout << "\nDepth-First Traversal:" << std::endl;
    DepthFirstIterator* dfsIterator = new DepthFirstIterator(mainFarm);
    for (FarmUnit* unit = dfsIterator->firstFarm(); !dfsIterator->isDone(); dfsIterator->next()) {
        std::cout << "- " << unit->getName() << std::endl;
    }
    delete dfsIterator;

    // Clean up memory
    delete wheatField;
    delete cornField;
    delete mainFarm;

    
}


void testFarmComposite() {
    // Create FarmComposite
    FarmComposite* mainFarm = new FarmComposite("Main Farm");

    // Create crop fields (farm units)
    CropField* wheatField = new CropField("Wheat", 1000, "Wheat Field");
    CropField* cornField = new CropField("Corn", 800, "Corn Field");

    // Set soil states for each field
    SoilStates* drySoil = new DrySoil();
    SoilStates* fruitfulSoil = new FruitfulSoil();
    wheatField->setSoilState(drySoil);
    cornField->setSoilState(fruitfulSoil);

    // Add crop fields to the farm composite
    mainFarm->addFarmUnit(wheatField);
    mainFarm->addFarmUnit(cornField);

    // Test the getters for total capacity, crop type, and soil state
    std::cout << "Total capacity of main farm: " << mainFarm->getTotalCapacity() << std::endl;
    std::cout << "Wheat Field Soil State: " << wheatField->getSoilStateName()->getName() << std::endl;
    std::cout << "Corn Field Soil State: " << cornField->getSoilStateName()->getName() << std::endl;

    // Test removing a farm unit
    mainFarm->removeFarmUnit(cornField);
    std::cout << "Removed Corn Field from the main farm." << std::endl;
    std::cout << "New total capacity of main farm: " << mainFarm->getTotalCapacity() << std::endl;

    // Re-add the corn field
    mainFarm->addFarmUnit(cornField);

    // Test Breadth-First Traversal
    std::cout << "\nBreadth-First Traversal:" << std::endl;
    BreadthFirstIterator* bfsIterator = new BreadthFirstIterator(mainFarm);
    for (FarmUnit* unit = bfsIterator->firstFarm(); !bfsIterator->isDone(); bfsIterator->next()) {
        std::cout << "- " << unit->getName() << std::endl;
    }
    delete bfsIterator;

    // Test Depth-First Traversal
    std::cout << "\nDepth-First Traversal:" << std::endl;
    DepthFirstIterator* dfsIterator = new DepthFirstIterator(mainFarm);
    for (FarmUnit* unit = dfsIterator->firstFarm(); !dfsIterator->isDone(); dfsIterator->next()) {
        std::cout << "- " << unit->getName() << std::endl;
    }
    mainFarm->removeFarmUnit(cornField);
    delete dfsIterator;

    // Clean up
    delete mainFarm;
    delete wheatField;
    delete cornField;
    delete drySoil;
    delete fruitfulSoil;
}

int main() {
       // Test DrySoil methods
    std::cout << "Testing DrySoil Methods:" << std::endl;
    DrySoil* drySoil = new DrySoil();
    drySoil->harvestCrops();
    std::cout << "Rain Result: " << drySoil->rain() << std::endl;
    std::cout << "Soil State Name: " << drySoil->getName() << std::endl;
    drySoil->cropYieldState();
    delete drySoil;

    std::cout << "\n---------------------------------------\n" << std::endl;

    // Test FloodedSoil methods
    std::cout << "Testing FloodedSoil Methods:" << std::endl;
    FloodedSoil* floodedSoil = new FloodedSoil();
    floodedSoil->harvestCrops();
    std::cout << "Rain Result: " << floodedSoil->rain() << std::endl;
    std::cout << "Soil State Name: " << floodedSoil->getName() << std::endl;
    floodedSoil->cropYieldState();
    floodedSoil->drainageSystem();
    delete floodedSoil;

    std::cout << "\n---------------------------------------\n" << std::endl;

    // Test FruitfulSoil methods
    std::cout << "Testing FruitfulSoil Methods:" << std::endl;
    FruitfulSoil* fruitfulSoil = new FruitfulSoil();
    fruitfulSoil->harvestCrops();
    std::cout << "Rain Result: " << fruitfulSoil->rain() << std::endl;
    std::cout << "Soil State Name: " << fruitfulSoil->getName() << std::endl;
    fruitfulSoil->cropYieldState();
//    
 std::cout<<"Testing Decorator // and CropField"<<std::endl;
       // Create instances of soil states
    SoilStates* drySoil2 = new DrySoil();
    SoilStates* fruitfulSoil2 = new FruitfulSoil();

    // Create a crop field
    CropField* cornField = new CropField("Corn", 500, "Farm A");
    cornField->setSoilState(drySoil);

    // Attach trucks as observers
    FertilizerTruck* fertilizerTruck = new FertilizerTruck(1000, "Warehouse");
    DeliveryTruck* deliveryTruck = new DeliveryTruck(500, "Depot");

    cornField->attach(fertilizerTruck);
    cornField->attach(deliveryTruck);

    // Test getting total capacity, crop type, and soil state
    std::cout << "Total capacity: " << cornField->getTotalCapacity() << std::endl;
    std::cout << "Crop type: " << cornField->getCropType() << std::endl;
    std::cout << "Soil state: " << cornField->getName() << std::endl;

    // Test soil state change and notification
    std::cout << "\nChanging soil state to FruitfulSoil and notifying trucks." << std::endl;
    cornField->setSoilState(fruitfulSoil);

    // Check storage capacity and trigger truck operations
    cornField->checkStorageCapacity();

    // Test event triggering based on state
    cornField->triggerEventsBasedOnState();

    // Apply fertilizer using decorator
    std::cout << "\nApplying fertilizer to crop field using FertilizerDecorator." << std::endl;
    FertilizerDecorator* fertilizedField = new FertilizerDecorator(cornField,"CornField");
    fertilizedField->increaseProduction();
    fertilizedField->harvest();

    // Test ExtraBarnDecorator to increase capacity
    std::cout << "\nAdding extra barn to increase capacity using ExtraBarnDecorator." << std::endl;
    ExtraBarnDecorator* expandedField = new ExtraBarnDecorator(fertilizedField, 300,"CornField2");
    std::cout << "Total capacity after adding extra barn: " << expandedField->getTotalCapacity() << std::endl;


//
  // Create crop fields (farm units)
    FarmUnit* wheatField1 = new CropField("Wheat", 900, "Wheat Field");
    FarmUnit* cornField1 = new CropField("Corn", 600, "Corn Field");
    TruckSystemObserver* truck1=new FertilizerTruck();
    TruckSystemObserver* truck2= new DeliveryTruck(5687,"Hatfield");
    
    wheatField1->attach(truck1);
    cornField1->attach(truck2);
    
    std::cout<<"Info about Delivery truck"<<std::endl;
    std::cout << "Crop type: " << cornField1->getCropType() << std::endl;
    std::cout << "Current load: " << truck2->getCurrentLoad() << std::endl;
    truck2->setCurrentLoad(599);
    std::string location=truck2->getLocation();
    std::cout << "Location: " <<location << std::endl;
       
   
 
   wheatField1->buyTruck(truck1);
   cornField1->buyTruck(truck2);
    
    wheatField1->notifyObservers();
    cornField1->notifyObservers();
    
    truck1->startEngine();
    truck2->startEngine();

   wheatField1->detach(truck1);
   cornField1->detach(truck2);


    // Clean up
    delete cornField;
    delete fertilizerTruck;
    delete deliveryTruck;
    delete fertilizedField;
    delete expandedField;
    delete drySoil2;
    delete fruitfulSoil2;
    delete fruitfulSoil;
    
   testingIterators();

    testFarmComposite();


    return 0;
}

void testDecoCrop()
{
    
}


