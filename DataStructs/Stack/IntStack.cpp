#include "IntStack.h"
#include <iostream>

using namespace std; 

// Constructor definition: initializes an empty stack
IntStack::IntStack(int size) {
    stackArray = new int[size];
    stackSize = size;
    top = -1;
}

// Copy Constructor
IntStack::IntStack(const IntStack &obj) {
    // create a stack array 
    if(obj.stackSize > 0)
        stackArray = new int[obj.stackSize];
    else
        stackArray = nullptr;

    // copy the stack size attribute
    stackSize = obj.stackSize;

    // copy the stack contents
    for(int count = 0; count < stackSize; count++){
        stackArray[count] = obj.stackArray[count];
    }

    // set the top of the stack
    top = obj.top;
    
}

// Destructor
IntStack::~IntStack(){
    
    delete [] stackArray;
}

// push method pushes argument onto the stack
void IntStack::push(int num){

    if(isFull()){
        cout << "The stack is full!\n";
    }
    else
    {
        top++;
        stackArray[top] = num;
    }
    
}

// pop method pops the value at the top of the stack and
// copies it into the variable passed as an argument
void IntStack::pop(int &num){
    if(isEmpty){
        cout << "The stack is empty!\n";
    }
    else
    {
        num = stackArray[top];
        top--;
    }
    
}

// Returns true if the stack is full and false otherwise
bool IntStack::isFull() const {

    bool status;

    if(top == stackSize - 1){
        status = true;
    }
    else
        status = false;

    return status;

}

// Returns true if the stack is empty and false otherwise
bool IntStack::isEmpty() const {

    bool status;

    if(top == -1){
        status = true;
    }
    else
        status = false;

    return status;
    
}