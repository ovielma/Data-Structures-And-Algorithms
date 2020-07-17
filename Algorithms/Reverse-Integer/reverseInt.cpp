#include <iostream>

using namespace std;

long int reverseInt(long int num){

    // handling negative numbers
    bool negativeFlag = false;
    if(num < 0){
        negativeFlag = true;
        num = -num;
        cout << num << endl;
    }

    int prev_rev_num = 0,
        rev_num = 0;
    while(num != 0) {
        int curr_int = num % 10;
        cout << "current int " << curr_int << endl;
        rev_num = (rev_num * 10) + curr_int;
        cout << "rev_num " << rev_num << endl;

        // checking if the reverse number overflowed. 
        // The values of (rev_num - curr_digit) / 10 and 
        // prev_rev_num must be same if no overflow occurred.
        if( (rev_num - curr_int) / 10 != prev_rev_num){
            cout << endl << "Overflow occurred!" << endl;
            return 0;
        }
        prev_rev_num = rev_num;
        cout << "prev_rev_num " << prev_rev_num << endl;
        num = num / 10;
    }

    // conditional operator (if negative, return negative, else return positive)
    return (negativeFlag == true) ? -rev_num : rev_num;

}

int main(){
    // use long int type for 32 bit number
    long int input,
            rev_input;

    cout << "Please enter a 32 bit integer: ";
    cin >> input;

    rev_input = reverseInt(input);

    cout << "Reverse integer is: " << rev_input << endl;
    return 0;

}