#ifndef PIERRES_H
#define PIERRES_H

#include <iostream>
#include <string>
#include <vector>
#include "Driver.h"
#include "Franchise.h"
#include "defs.h"

using namespace std;

class Pierres{
    public:
        Pierres();
        ~Pierres();
        void addDriver(const string& name, const Location&);
        void addFranchise(const string& name, const Location&);
        void takeOrder(const string& customerName, int menuItem, const Location&);
        void driverPickup(const string& franchiseId, int numOrders);
        void driverDeliver(const string& driverId, int numOrders);
        void printFranchises() const;
        void printDrivers() const;
    private:
        vector<Driver*> drivers;
        vector<Franchise*> franchises;
        
};

#endif