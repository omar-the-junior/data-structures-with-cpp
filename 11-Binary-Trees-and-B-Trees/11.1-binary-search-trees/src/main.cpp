#include "../include/bSearchTreeType.h"
#include <iostream>

using namespace std;

int main()
{
    bSearchTreeType<int> tree;

    // Insert elements
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Traverse the tree
    cout << "Inorder traversal: ";
    tree.inorderTraversal();

    cout << endl;
    // Search for elements
    cout << "Search for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search for 100: " << (tree.search(100) ? "Found" : "Not Found") << endl;

    // Delete elements
    tree.deleteNode(20);
    cout << "After deleting 20\n";
    cout << "Search for 20: " << (tree.search(20) ? "Found" : "Not Found") << endl;

    tree.deleteNode(30);
    cout << "After deleting 30\n";
    cout << "Search for 30: " << (tree.search(30) ? "Found" : "Not Found") << endl;

    tree.deleteNode(50);
    cout << "After deleting 50\n";
    cout << "Search for 50: " << (tree.search(50) ? "Found" : "Not Found") << endl;

    return 0;
}