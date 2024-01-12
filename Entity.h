#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

class Entity {
    public:
        Entity(char, int, const string&, const Location&);        
        Location getLocation() const;
        void setLocation(const Location&);
        int getNumOrders() const;
        Order* getNextOrder();
        void addOrder(Order* order);
        void print() const;
        bool equals(const string&) const;
    protected:
        string id;
        string name;
        Location location;
        Queue orders;        
};

#endif