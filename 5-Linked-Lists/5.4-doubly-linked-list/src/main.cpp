#include <iostream>
#include "../include/doublyLinkedList.h"

using namespace std;

int main()
{
    doublyLinkedList<int> list;

    // Insert values
    list.insert(10);
    list.insert(20);
    list.insert(30);

    // Print the list
    cout << "List after inserting 10, 20, 30: ";
    list.print();

    // Check the length of the list
    cout << "List length: " << list.length() << endl;

    // Search for a value
    if (list.search(20))
    {
        cout << "Found 20 in the list." << endl;
    }
    else
    {
        cout << "Did not find 20 in the list. Something is wrong." << endl;
    }

    // Delete a value
    list.deleteNode(20);

    // Print the list again
    cout << "List after deleting 20: ";
    list.print();

    // Check the length of the list again
    cout << "List length: " << list.length() << endl;

    // Try to delete a value that is not in the list
    list.deleteNode(40);

    // Destroy the list
    list.destroy();

    // Check if the list is empty after destruction
    if (list.length() == 0)
    {
        cout << "List is empty as expected." << endl;
    }
    else
    {
        cout << "List is not empty. Something is wrong." << endl;
    }

    return 0;
}