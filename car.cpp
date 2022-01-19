// Anna Lee and Perm #: 5774344
// This is the only file to submit.
//g++ --std=c++11 -Wall car.cpp -o car
#include "car.hpp"
#include <cstddef>
#include <cstring>


Car::Car(){
    manufacturer = NULL;
    model = NULL;
    zeroToSixtyNs =0;
    headonDragCoeff =0;
    horsepower=0;
    backseatDoors = None;
    seatCount =0;
    

}

Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign) {

manufacturer = NULL;
model = NULL;
manufacturerChange(manufacturerName);
modelNameChange(modelName);
zeroToSixtyNs = perf.zeroToSixtyNs;
headonDragCoeff = perf.headonDragCoeff;
horsepower = perf.horsepower;
backseatDoors = backseatDoorDesign;
seatCount = numSeats;

}

Car::Car(Car const& o) {
    manufacturer = NULL;
    model = NULL;
  
  manufacturerChange (o.getManufacturer());
  modelNameChange (o.getModel());
zeroToSixtyNs = o.getStats().zeroToSixtyNs;
headonDragCoeff = o.getStats().headonDragCoeff;
horsepower = o.getStats().horsepower;
backseatDoors = o.getBackseatDoors();
seatCount = o.getSeatCount();
    //CONTINUE
}
Car& Car::operator=(Car const& o) {
    if (this == &o) {
        return *this;
    }
    manufacturer = NULL;
    model = NULL;
    manufacturerChange (o.getManufacturer());
    modelNameChange (o.getModel());
    zeroToSixtyNs = o.getStats().zeroToSixtyNs;
    headonDragCoeff = o.getStats().headonDragCoeff;
    horsepower = o.getStats().horsepower;
    backseatDoors = o.getBackseatDoors();
    seatCount = o.getSeatCount();
    return *this;

}
Car::~Car() {
    delete [] manufacturer;
    delete [] model;
}
char const* Car::getManufacturer() const {
    return manufacturer;
}
char const* Car::getModel() const {
    return model;
}
PerformanceStats Car::getStats() const {
    //DOO
    PerformanceStats hi = {horsepower, zeroToSixtyNs, headonDragCoeff};
    return hi;
}
uint8_t Car::getSeatCount() const {
    return seatCount;
}
DoorKind Car::getBackseatDoors() const {
    return backseatDoors;
}
void Car::manufacturerChange(char const* const newManufacturer) {
    delete [] manufacturer;
   manufacturer = new char [strlen(newManufacturer +1)];
   strcpy (manufacturer, newManufacturer);
}
void Car::modelNameChange(char const* const newModelName){
    delete [] model;
   model = new char [strlen (newModelName +1)];
   strcpy (model, newModelName); 
   }
void Car::reevaluateStats(PerformanceStats newStats){
//DOO
horsepower = newStats.horsepower;
zeroToSixtyNs = newStats.zeroToSixtyNs;
headonDragCoeff = newStats.headonDragCoeff;
}
void Car::recountSeats(uint8_t newSeatCount){
    seatCount = newSeatCount;
}
void Car::reexamineDoors(DoorKind newDoorKind){
    backseatDoors = newDoorKind;
}