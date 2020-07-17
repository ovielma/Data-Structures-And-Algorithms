#include "dynamicStack.cpp"
#include <iostream>
#include <string>
using namespace std;

void pushItem(DynamicStack<string> &);
void popItem(DynamicStack<string> &);

int main() {

    DynamicStack<string> stack;

    pushItem(stack);
    popItem(stack);

    return 0;

}

void pushItem(DynamicStack<string> &stack) {

    string item;

    // push item on the stack
    cout << "\nEnter the value to push onto the stack: ";
    getline(cin, item);
    stack.push(item);
}

void popItem(DynamicStack<string> &stack) {

    string item = "";

    stack.pop(item);

    if(item != "")
        cout << item << " was popped from the stack\n";
}