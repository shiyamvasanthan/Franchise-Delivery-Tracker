#include "Driver.h"

const char Driver::code = 'D';
int Driver::nextId = 1;

Driver::Driver(const string& name, const Location& location):Entity(code, nextId, name, location){
    nextId++;
}

bool Driver::isFree() const{
    return orders.empty();
}

void Driver::print() const{
    Entity::print();
    cout << "This person is a driver." << endl;
}

