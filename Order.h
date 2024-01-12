#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include "Location.h"
using namespace std;

class Order {
    public:
        Order(const string&, int, const Location&);
        Location getLocation() const;
        void print() const;
    private:
        string name;
        int menuItem;
        Location location;
        
};

#endif