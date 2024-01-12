#include "Franchise.h"

const char Franchise::code = 'F';
int Franchise::nextId = 1;
const string Franchise::menu[MENU_ITEMS] = {"1. Large Poutine", "2. Medium Poutine", "3. Small Poutine"};

Franchise::Franchise(const string& name, const Location& location):Entity(code, nextId, name, location){
    nextId++;
}

void Franchise::print() const{
    Entity::print();
    cout << "This is a franchise." << endl;
}

void Franchise::printMenu(){
    for(int i = 0; i < MENU_ITEMS; i++){
        cout << menu[i] << endl;
    }
}

string Franchise::getMenu(int index){
    if(index < 0 || index >= MENU_ITEMS) return "unknown menu item";

    return menu[index];
}