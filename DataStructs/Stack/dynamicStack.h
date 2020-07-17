#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H
#include <iostream>

/*
    This implementation is built on linked list instead of an array. A linked list–based stack 
    offers two advantages over an array-based stack. First, there is no need to specify the starting 
    size of the stack. A dynamic stack simply starts as an empty linked list, then expands by one node 
    each time a value is pushed. Second, a dynamic stack will never be full, as long as the system has 
    enough free memory.
*/

using namespace std;

template <class T>
class DynamicStack {

    private:
            // structure for stack of nodes
            struct StackNode {

                T value;
                StackNode *next; // pointer to the next node
            };
            StackNode *top;

    public:
            DynamicStack() { top = nullptr;}    // constructor, initialize top of stack to nullptr
            ~DynamicStack();                    // destructor

            void push(T);
            void pop(T &);
            bool isEmpty();
};
#endif