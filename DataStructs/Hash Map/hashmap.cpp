/** 
 * Date: March 11, 2020
 * World News at the time of writing this: COVID-19 declared a pandemic by WHO.
 * 
 * Hash map/table container (Ordered & Unordered): unordered_map is normally expected to have constant complexity. 
 * That is, an insertion, lookup, etc., typically takes a constant or fixed amount of time, regardless of how many
 * items are in the table. 
 * A map, on the other hand, has a logarithmic complexity. Which means the time to insert or retrieve an item grows,
 * but quite slowly, as the map grows larger. For example, if it takes 1 microsecond to lookup one of 1 million items,
 * then you can expect it to take around 2 microseconds to lookup one of 2 million items, 3 microseconds for one of 4 million 
 * items, 4 microseconds for one of 8 million items, etc.
 * 
 * For situations where you insert a lot of data, then iterate through the table once to retrieve results (e.g., counting the
 * number of unique words in a file) chances are that a map will be the best container to use. However, an unordered_map should
 * be used when a lot more lookups are made compared to insertions.
*/

//#include <unordered_map> // unordered hash map; insert and access time is O(1)
#include <map> // hash map STL (ordered map): the elements are sorted by the key; insert and access time is O(log n)
#include <iterator>
#include <iostream>
using namespace std;

int main() {

    // empty map container
    map<int, int> testNums;

    // insert elements
    cout << "Inserting elements into the map . . .\n";
    testNums.insert(pair<int, int>(1,11));
    testNums.insert(pair<int, int>(2,22));
    testNums.insert(pair<int, int>(3,50));
    testNums.insert(pair<int, int>(4,50));

    // create an iterator of map type to cycle through for loop
    map<int, int>::iterator i;

    // print map pair values 
    // Note that first returns the key and second returns the value paired to that key
    for(i = testNums.begin(); i != testNums.end(); i++) {
        
        cout << '\t' << i->first << '\t' << i->second << '\n';
    }

    // remove element containing key = 4
    testNums.erase(4);

    cout << "Removing the last inserted element in the map and printing values again . . .\n";

    for(i = testNums.begin(); i != testNums.end(); i++) {
        
        cout << '\t' << i->first << '\t' << i->second << '\n';
    }
    cout << endl;
    cout << "\t" << "lower.bound(1)" << endl;
    cout << "\t" << testNums.lower_bound(1)->first << "\t";
    cout << testNums.lower_bound(1)->second << endl;
    cout << "\t" << "upper.bound(2)" << endl;
    cout << "\t" <<  testNums.upper_bound(2)->first << "\t";
    cout <<  testNums.upper_bound(2)->second << endl;

    return 0;

}