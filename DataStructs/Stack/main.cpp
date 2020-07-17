#include "IntStack.h"
#include <iostream>
//#include <stack> to use the stack STL

using namespace std;

int main(){

    int catchVar; // holds values popped off the stack
    int size = 6;

    // define a stack object to hold a value
    IntStack stack(size);

    // push values into the stack
    cout << "Pushing 'Hello'\n";
    stack.push('H');
    stack.push('e');
    stack.push('l');
    stack.push('l');
    stack.push('o');

    // pop the values off the stack
    cout << "Popping . . .\n";
    stack.pop(catchVar);
    cout << catchVar << endl;

    return 0;

}