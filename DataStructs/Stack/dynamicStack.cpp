#include "dynamicStack.h"
#include <iostream>

using namespace std;

// destructor
template <class T>
DynamicStack<T>::~DynamicStack() {

    StackNode *nodeTracker, *nextNode;

    // position nodeTracker at the top of the stack
    nodeTracker = top;

    // traverse the stack, deleting every node
    while(nodeTracker != nullptr) {

        nextNode = nodeTracker->next;
        delete nodeTracker;
        nodeTracker = nextNode;
    }
}
// push()
template <class T>
void DynamicStack<T>::push(T item) {

    StackNode *newNode = nullptr; // pointer to n

    // allocate a new node and store item value there
    newNode = new StackNode;
    newNode->value = item;

    // if there are no nodes in the stack, make item the first node
    if(isEmpty()){
        top = newNode;
        newNode->next = nullptr;
        cout << "\nPushed " << top->value << " on the stack.\n";
    }
    else { // otherwise insert item before the top of the stack
        newNode->next = top; // top here contains the nullptr value as initialized by constructor
        top = newNode;
        cout << "\nPushed " << top->value << " on the stack.\n";
    }
}

// pop()
template <class T>
void DynamicStack<T>::pop(T &n) {

    StackNode *temp;

    // check if the stack is empty
    if(isEmpty()) {
        cout << "\nThe stack is empty!\n";
        return;
    }
    else { // pop the top of the stack
        cout << top->value << "\n";
        n = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}

// isEmpty()
template <class T>
bool DynamicStack<T>::isEmpty() {

    bool status;

    if(!top) {
        status = true;
    }
    else
        status = false;

    return status;
    
}