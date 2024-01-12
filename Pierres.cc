#include "Pierres.h"

Pierres::Pierres(){

}

Pierres::~Pierres(){
    for(int i = 0; i < drivers.size(); i++){
        delete drivers.at(i);
    }

    for(int i = 0; i < franchises.size(); i++){
        delete franchises.at(i);
    }
}
void Pierres::addDriver(const string& name, const Location& location){
    drivers.push_back(new Driver(name, location));
}

void Pierres::addFranchise(const string& name, const Location& location){
    franchises.push_back(new Franchise(name, location));
}

void Pierres::takeOrder(const string& customerName, int menuItem, const Location& location){
    if(franchises.empty()) return;

    Order* order = new Order(customerName, menuItem, location);

    int closestIndex = 0;
    int closestLocation = franchises.at(0)->getLocation().getDistance(location);
    
    for(int i = 1; i < franchises.size(); i++){
        int closeLocation = franchises.at(i)->getLocation().getDistance(location);

        if(closeLocation < closestLocation) {
            closestLocation = closeLocation;
            closestIndex = i;
        }
    }

    franchises.at(closestIndex)->addOrder(order);
}

void Pierres::driverPickup(const string& franchiseId, int numOrders){
    bool hasId = false;
    int franchiseIndex;
    for(int i = 0; i < franchises.size(); i++){
        if(franchises.at(i)->equals(franchiseId)){
            franchiseIndex = i;
            hasId = true;
            break;
        }
    }

    if(!hasId){
        cout << "No franchise exists with the specified ID" << endl;
        return;
    }

    if(drivers.empty()) {
        cout << "No drivers exist at this franchise" << endl;
        return;
    }

    int closestIndex = 0;
    Franchise* franchise = franchises.at(franchiseIndex);
    Location location = franchise->getLocation();
    int closestLocation = drivers.at(0)->getLocation().getDistance(location);
    bool foundDriver = false;

    for(int i = 1; i < drivers.size(); i++){
        if(drivers.at(i)->isFree()){
            int closeLocation = drivers.at(i)->getLocation().getDistance(location);

            if(closeLocation < closestLocation){
                closestLocation = closeLocation;
                closestIndex = i;
                foundDriver = true;
            }
        }
    }

    if(!foundDriver){
        cout << "No drivers are available" << endl;
        return;
    }

    drivers.at(closestIndex)->setLocation(location);

    if(numOrders < franchise->getNumOrders()){
        for(int i = 0; i < numOrders; i++){
            drivers.at(closestIndex)->addOrder(franchise->getNextOrder());
        }
    } else {
        for(int i = 0; i < franchise->getNumOrders(); i++){
            drivers.at(closestIndex)->addOrder(franchise->getNextOrder());
        }
    }
}

void Pierres::driverDeliver(const string& driverId, int numOrders){
    bool hasId = false;
    int driverIndex;
    for(int i = 0; i < drivers.size(); i++){
        if(drivers.at(i)->equals(driverId)){
            driverIndex = i;
            hasId = true;
            break;
        }
    }

    if(!hasId){
        cout << "No driver exists with the specified ID" << endl;
        return;
    }

    Driver* driver = drivers.at(driverIndex);

    if(driver->getNumOrders() < numOrders){
        for(int i = 0; i < driver->getNumOrders(); i++){
            Order* order = driver->getNextOrder();
            driver->setLocation(order->getLocation());
            cout << "Delivering: " << endl;
            order->print();

            delete order;
        }
    } else {
        for(int i = 0; i < numOrders; i++){
            Order* order = driver->getNextOrder();
            driver->setLocation(order->getLocation());
            cout << "Delivering: " << endl;
            order->print();

            delete order;
        }
    }
}

void Pierres::printFranchises() const{
    for(int i = 0; i < franchises.size(); i++){
        franchises.at(i)->print();
    }
}

void Pierres::printDrivers() const{
    for(int i = 0; i < drivers.size(); i++){
        drivers.at(i)->print();
    }
}