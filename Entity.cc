#include "Entity.h"

Entity::Entity(char code, int i, const string& name, const Location& location):id(code + to_string(i)), name(name), location(location) {

}

Location Entity::getLocation() const{
    return location;
}
void Entity::setLocation(const Location& location){
    this->location = location;
}

int Entity::getNumOrders() const{
    return this->orders.size();
}

Order* Entity::getNextOrder() {
    return orders.popFirst();
}

void Entity::addOrder(Order* order){
    orders.addLast(order);
}

void Entity::print() const{
    location.print();
    cout << "Id " << id << " name " << name << " num orders " << getNumOrders() << endl; 
}

bool Entity::equals(const string& id) const{
    return this->id == id;
}
