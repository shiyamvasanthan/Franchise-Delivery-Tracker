#include "Queue.h"

Queue::Queue():head(nullptr), tail(nullptr), numOrders(0){

}

Queue::~Queue(){
    Node* curr = head;
    Node* prev = nullptr;

    while(curr != nullptr){
        prev = curr;
        curr = curr->next;
        delete prev;
    }
}

bool Queue::empty() const{
    return numOrders == 0;
}

int Queue::size() const{
    return numOrders;
}

Order* Queue::peekFirst(){
    Node* curr = head;

    if(curr == nullptr) return nullptr;

    return curr->data;
}

Order* Queue::popFirst(){
    Order* order = peekFirst();

    if(order == nullptr) return nullptr;

    Node* curr = head;
    head = curr->next;

    if(numOrders - 1 == 1) tail = head;

    delete curr;
    numOrders--;
    return order;
}

void Queue::addLast(Order* order) {
    Node* node = new Node;
    node->data = order;
    node->next = nullptr;
    
    if(empty()){
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }

    numOrders++;
}

