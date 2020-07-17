#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

// search prototypes
int linearSearch(const int [], int, int);
int binarySearch(const int [], int, int);
void quicksort(int [], int, int);
int partition(int [], int, int, int);

const int SIZE = 20;

int main() {

    // array, note if array is partially initialized, the rest of the elements will be set to 0
    int list[SIZE] = {11, 7, 12, 17, 93, 69, 71, 94, 5, 10, 100, 75, 299, 111, 1000, 3393, 2048, 1, 45, 50};
    int list2[SIZE] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 40000, 50000, 60000, 100000};
    int list3[9] = {15, 3, 2, 1, 9, 5, 7, 8, 6};
    int searchValue;
    int result;
    int n = 10;

    cout << "Enter an integer value you want to search in the array: ";
    cin >> searchValue;

    result = linearSearch(list, SIZE, searchValue);
    //result = binarySearch(list2, SIZE, searchValue);

    if(result == -1){
        cout << "Your search value was not found in the list!\n";
    }
    else
        cout << "Your search value was found at position " << result + 1 << "!\n\n";

    cout << endl;
    cout << "list3 before sorting: \n";
    int l3size = sizeof(list3);
    for(int i = 0; i < l3size; i++) {
        cout << list3[i];
    }
    cout << endl << "Calling quicksort() . . ." << endl;
    quicksort(list3, list3[0], list3[l3size - 1]);
    cout << "list3 after quicksort():\n";
    for(int i = 0; i < l3size; i++) {
        cout << list3[i];
    }

    return 0;

}

// The advantage of a linear search is it's simplicity and it doesn't
// require data be sorted. Disadvantage: O(n) is worst case time complexity,
// O(n/2) for the average case.
int linearSearch(const int list[], int numElements, int value){
    
    bool found = false;
    int position = -1;
    int index = 0;

    while(found == false && index < numElements){
        if(list[index] == value){
            found = true;
            position = index;
        }
        index++;
    }

    return position;
}

// The advantage of a binary search is that half of the search elements
// are eliminated with each iteration. Disadvantage is that items need to be sorted. Time complexity is O(log n).
int binarySearch(const int list[], int numElements, int value){

    int first = 0,
        last = numElements - 1,
        middle,
        position = -1;
    bool found = false;

    while(!found && first <= last){
        middle = (first + last) / 2;
        if(list[middle] == value){
            found = true;
            position = middle;
        }
        else if(list[middle] > value){
            last = middle - 1;
        }
        else
            first = middle + 1;    
    }
    return position;
}

//// ***  QUICK SORT *** ////
void quicksort(int listToSort[], int low, int high) {

    // check
    if(low >= high)
        return;

    int pivot = listToSort[(low + high) / 2]; // there are different ways to pick the pivot but I'll make the pivot the middle for now
    int index = partition(listToSort, low, high, pivot);

    quicksort(listToSort, low, index - 1);
    quicksort(listToSort, index + 1, high);

}

int partition(int arr[], int low, int high, int pivot) {

    while(low <= high){
        while(arr[low] < pivot) {
            low++;
        }

        while(arr[high] > pivot) {
            high--;
        }

        if(low <= high) {
            swap(low, high); // maybe switch from traditional array to vector for easier implementation?
            low++;
            high--;
        }
    }
    return low;
}