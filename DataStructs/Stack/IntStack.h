#ifndef INTSTACK_H
#define INTSTACK_H

class IntStack
{
    private:
        int *stackArray; // pointer that points stack array
        int stackSize;   // the stack size
        int top;         // indicates the top of the stack

    public:
        // Constructor
        IntStack(int);

        // Copy Constructor
        IntStack(const IntStack &);

        // Destructor
        ~IntStack();

        // public methods
        void push(int);
        void pop(int &);
        bool isEmpty() const;
        bool isFull() const;

};
#endif