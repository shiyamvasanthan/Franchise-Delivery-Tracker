#include "Order.h"
#include "Franchise.h"

Order::Order(const string& name, int menuItem, const Location& location):name(name), menuItem(menuItem), location(location){

}

Location Order::getLocation() const{
    return location;
}

void Order::print() const{
    cout << "Customer name " << name << " menu item " << Franchise::getMenu(menuItem) << endl;
}