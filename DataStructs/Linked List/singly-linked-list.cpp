// Author: Oswaldo Vielma
// Date: January 10, 2020
// Note: other variations include the doubly linked list which has two pointers pointing to next node and previous node. 
//       In a circular linked list, the last node is pointing to the first node. 
//       Lastly, the STL provides a linked list container ( #include <list> ) which implements most of the methods here.

// Pitfalls of using pointers: slower than normal variables b/c they have to be dereferenced,
// memory leak or memory corruption (if good practices aren't followed), segmentation faults, potential access to
// restricted regions of memory.

#include <iostream>

using namespace std;

// Because the ListNode structure contains a pointer to an object of the same type as that being 
// declared, it is known as a self-referential data structure.
struct ListNode {

    int value;
    ListNode *next; // holds address of a ListNode object, points to next node
};
ListNode *headNode = nullptr; // defines the headNode of the linked list, before using it must be initialized to nullptr

// Linked List operation prototypes
void appendNode(int);
void insertNode(int);
void deleteNode(int);
void reverseLL();
void search(int);
void displayList();

int main() {

    int choice, value;

    do {
        // Option Menu
        cout << "\n0. Exit"
             << "\n1. Append"
             << "\n2. Insert"
             << "\n3. Delete"
             << "\n4. Reverse"
             << "\n5. Search"
             << "\n6. Display"
             << "\n\nWhat linked list operation do you want to perform? ";
        cin >> choice;

        switch(choice){

            case 1:
                    cout << "\nEnter the value of the node you want to append: ";
                    cin >> value;
                    appendNode(value);
                    break;
            case 2:
                    cout << "\nEnter the value of the node you want to insert: ";
                    cin >> value;
                    insertNode(value);
                    break;
            case 3:
                    cout << "\nEnter the value of the node you want to delete: ";
                    cin >> value;
                    deleteNode(value);
                    break;
            case 4:
                    reverseLL();
                    break;
            case 5:
                    cout << "\nWhat value do you want to search for? ";
                    cin >> value;
                    search(value);
                    break;
            case 6:
                    displayList();
                    break;
            default:
                    break; // if none of the choices above is selected, the user is shown menu again
        }

    } while(choice != 0);

    cout << "\nGoodbye!\n";

    return 0;
   
}

// append a node to the end of the linked list
void appendNode(int n) {

    ListNode *newNode = new ListNode;    // create a new node of type ListNode
    ListNode *nodeTracker;               // pointer to move through list of nodes

    newNode->value = n;                 // store data (n) in the new node
    newNode->next = nullptr;            // set value of next node to nullptr

    // if there are no nodes (no headNode) in the list, make the newNode the first node (headNode)
    if(!headNode) {
        headNode = newNode;
        cout << "\nSuccessfully appended node to the list\n";
    }
    // if there are nodes, find end of the list and insert new node
    else {
        nodeTracker = headNode; // initialize nodeTracker to headNode

        // while there are still nodes to traverse (true), find the last node in the list
        while(nodeTracker->next) {
            nodeTracker = nodeTracker->next;
        }
        // insert newNode as the last node
        nodeTracker->next = newNode;
        cout << "\nSuccessfully appended node to the list\n";
    }
}

// insert a node in the middle of the linked list
void insertNode(int n) {

    ListNode *newNode = new ListNode; // create a new node
    ListNode *nodeTracker;            // pointer used to traverse the linked list
    ListNode *prevNode;               // pointer needed for previous node

    newNode->value = n;               // store the data (n) in the new node's value variable
    prevNode = nullptr;               // initialize prevNode to nullptr

    // If there are no nodes in the list, then make newNode the first node
    if(!headNode) {
        headNode = newNode;
        newNode->next = nullptr;
        cout << "\nSuccessfuly inserted the node in the list!\n";
    }
    else {
        // Begin at the headNode of the linked list
        nodeTracker = headNode;

        // skip all values less than n (this loop advances nodeTracker & prevNode by one node each iteration)
        while(nodeTracker->value < n && nodeTracker != nullptr) {
            prevNode = nodeTracker;
            nodeTracker = nodeTracker->next;
        }

        // If the newNode is to be the first in the list, insert it before all other nodes
        if(prevNode == nullptr) {
            headNode = newNode;
            newNode->next = nodeTracker;
            cout << "\nSuccessfuly inserted the node in the list!\n";
        }
        // else, insert it after prevNode
        else
        {
            prevNode->next = newNode;
            newNode->next = nodeTracker;
            cout << "\nSuccessfuly inserted the node in the list!\n";
        }
    }
}

// remove a node from the linked list
void deleteNode(int n) {

    ListNode *prevNode;         // to point to previous node
    ListNode *nodeTracker;      // to traverse the linked list

    // if there are no nodes, exit
    if(!headNode)
        cout << "\nLinked list is empty!\n";
        return;
    // determine if the first node is the right node
    if(headNode->value == n){
        nodeTracker = headNode->next;
        delete headNode;
        cout << "\nSuccessfully deleted node!\n";
        headNode = nodeTracker;
    }
    else {
        // initialize nodeTracker to headNode of the list
        nodeTracker = headNode;

        // skip all nodes that are not equal to desired
        while(nodeTracker != nullptr && nodeTracker->value != n){
            prevNode = nodeTracker;
            nodeTracker = nodeTracker->next;
        }
        
        // If node was found, it is being pointed to by nodeTracker, link prevNode to node after nodeTracker, then delete nodeTracker
        if(nodeTracker) {
            prevNode->next = nodeTracker->next;
            delete nodeTracker;
            cout << "\nSuccessfully deleted node!\n";
        }
    }
}

// reverse the nodes in the linked list (iterative method)
// Ex: 1->2->3->nullptr to 3->2->1->nullptr
void reverseLL() {

    // if there are no nodes, exit
    if(!headNode)
        cout << "\nLinked list is empty!\n";
        return;

    ListNode *currNode = headNode;     // current node
    ListNode *prevNode = nullptr;      // previous node
    ListNode *nextNode = nullptr;      // next node

    while(currNode != nullptr) {
        
        nextNode = currNode->next;     // store next
        currNode->next = prevNode;     // reverse nodes
        prevNode = currNode;           // move current node ahead
        currNode = nextNode;           // move next node ahead
    }
    headNode = prevNode;               // store previous node's value in headNode

    cout << "\nSuccessfully reversed the linked list!\n";
}

// searches for a node in the linked list
void search(int n) {

    ListNode *nodeTracker = headNode; // begin at the head of the linked list
    bool found = false;

    // if linked list is empty, exit
    if(!nodeTracker) {
        cout << "\nLinked list is empty!\n";
        return;
    }

    while(nodeTracker != nullptr) {
        
        if(nodeTracker->value == n) {
            cout << "\nThe value was found in the linked list!\n";
            found = true;
            break;
        }
        nodeTracker = nodeTracker->next;
    }
    if(found == false)
        cout << "\nThe value was not found in the linked list.\n";
}

// display the linked list
void displayList() {

    // if there are no nodes, exit
    if(!headNode)
        cout << "\nLinked list is empty!\n";
        return;

    ListNode *nodeTracker;  // create node for traversing linked list
    nodeTracker = headNode; // assign nodeTracker to the head of the linked list to begin traversing

    cout << endl;
    // while nodeTracker points to a node (and not nullptr), keep traversing list
    while(nodeTracker) {
        // check if last node of linked list has been reached
       if(nodeTracker->next == nullptr) {
            cout << nodeTracker->value;
            cout << nodeTracker->next;
            break;  // ignore the rest of the code
       }
        cout << nodeTracker->value << "->";
        nodeTracker = nodeTracker->next;
    }
    cout << endl;
}