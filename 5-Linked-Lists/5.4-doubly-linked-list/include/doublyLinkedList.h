#ifndef H_linkedListType
#define H_linkedListType

#include "./nodeType.h"
#include <iostream>
#include <cassert>

using namespace std;
template <class Type>
class doublyLinkedList
{
public:
    const doublyLinkedList<Type> &operator=(const doublyLinkedList<Type> &);
    void initializeList();
    bool isEmptyList() const;

    void destroy();
    void print() const;
    void reversePrint() const;
    int length() const;
    Type front() const;
    Type back() const;
    bool search(const Type &searchItem) const;
    void insert(const Type &insertItem);
    void deleteNode(const Type &deleteItem);
    doublyLinkedList();

    // Copy Constructor
    doublyLinkedList(const doublyLinkedList<Type> &otherList);

    ~doublyLinkedList();

protected:
    int count;
    nodeType<Type> *first;
    nodeType<Type> *last;

private:
    void copyList(const doublyLinkedList<Type> &otherList);
    // Function to make a copy of otherList
};

template <class Type>
doublyLinkedList<Type>::doublyLinkedList()
{
    first = NULL;
    last = NULL;
    count = 0;
}

template <class Type>
bool doublyLinkedList<Type>::isEmptyList() const
{
    return (first == NULL);
}

template <class Type>
void doublyLinkedList<Type>::destroy()
{
    nodeType<Type> *temp;
    while (first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }

    last = NULL;
    count = 0;
}

template <class Type>
void doublyLinkedList<Type>::initializeList()
{
    destroy();
}

template <class Type>
int doublyLinkedList<Type>::length() const
{
    return count;
}

template <class Type>
void doublyLinkedList<Type>::print() const
{
    nodeType<Type> *current; // pointer to traverse the list

    current = first;

    while (current != NULL)
    {
        cout << current->info << " ";
        current = current->next;
    }

    cout << endl;
}

template <class Type>
void doublyLinkedList<Type>::reversePrint() const
{
    nodeType<Type> *current; // pointer to traverse the list

    current = last;

    while (current != NULL)
    {
        cout << current->info << " ";
        current = current->back;
    }
}

template <class Type>
bool doublyLinkedList<Type>::search(const Type &searchItem) const
{
    bool found = false;
    nodeType<Type> *current; // pointer to traverse the list

    current = first;

    // The search method in this doubly linked list implementation is designed to work with sorted lists. The >= operator is used to stop the search as soon as it encounters a node with a value that is greater than or equal to the search item.

    // This is an optimization that takes advantage of the sorted nature of the list to potentially reduce the number of nodes that need to be checked.
    while (current != NULL && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->next;

    // Make sure the search item is in the list before proceeding
    if (found)
        found = (current->info == searchItem); // test for equality
    return found;
}

template <class Type>
Type doublyLinkedList<Type>::front() const
{
    assert(first != NULL);
    return first->info;
}

template <class Type>
Type doublyLinkedList<Type>::back() const
{
    assert(last != NULL);
    return last->info;
}

template <class Type>
void doublyLinkedList<Type>::insert(const Type &insertItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *newNode;
    bool found;

    newNode = new nodeType<Type>;
    newNode->info = insertItem;
    newNode->next = NULL;
    newNode->back = NULL;

    // If the list is empty, insert the new node at the beginning of the list.
    if (first == NULL)
    {
        first = newNode;
        last = newNode;
        count++;
    }
    else
    {
        found = false;
        current = first;

        // Search the list: if the list is sorted, we can stop the search as soon as we find a node with a value greater than or equal to the insert item.
        while (current != NULL && !found)
            if (current->info >= insertItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->next;
            }
        // If the insert item is less than the first node, insert the new node at the beginning of the list.
        if (current == first)
        {
            first->back = newNode;
            newNode->next = first;
            first = newNode;
            count++;
        }
        else
        {
            // If the insert item is greater than the last node, insert the new node at the end of the list.
            if (current != NULL)
            {
                trailCurrent->next = newNode;
                newNode->back = trailCurrent;
                newNode->next = current;
                current->back = newNode;
            }
            // If current is not null then the new node is inserted between two nodes somewhere in the middle of the list.
            else
            {
                trailCurrent->next = newNode;
                newNode->back = trailCurrent;
                last = newNode;
            }
            count++;
        }
    }
}

template <class Type>
void doublyLinkedList<Type>::deleteNode(const Type &deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;

    // If the list is empty, output an error message and return.
    if (first == NULL)
        cout << "Cannot delete from an empty list." << endl;
    // If the delete item is the first node, delete the first node.
    else if (first->info == deleteItem)
    {
        current = first;
        first = first->next;
        if (first != NULL)
            first->back = NULL;
        else
            last = NULL;

        count--;

        delete current;
    }
    // If the delete item is not the first node, search for the node with the delete item.
    else
    {
        found = false;
        current = first;
        // Search the list: if the list is sorted, we can stop the search as soon as we find a node with a value greater than or equal to the delete item.
        while (current != NULL && !found)
            if (current->info >= deleteItem)
                found = true;
            else
                current = current->next;
        // If the delete item is not in the list, output an error message and return.
        if (current == NULL)
            cout << "The item to be deleted is not in the list." << endl;
        // If the delete item is found, delete the node.
        else if (current->info == deleteItem)
        {
            // Set the value of trailCurrent to the node before the node to be deleted.
            trailCurrent = current->back;
            // As a first step, set the next pointer of trailCurrent to the node after the node to be deleted.
            trailCurrent->next = current->next;

            // If the current node is not the last node, set the back pointer of the node after the current node to trailCurrent.
            if (current->next != NULL)
                current->next->back = trailCurrent;
            // If the current node is the last node, set last to trailCurrent.
            if (current == last)
                last = trailCurrent;
            // Delete the node and decrement count.
            count--;
            delete current;
        }
        else // The delete item is not in the list.
            cout << "The item to be deleted is not in list." << endl;
    }
}

template <class Type>
void doublyLinkedList<Type>::copyList(const doublyLinkedList &otherList)
{
    nodeType<Type> *current;
    current = otherList.first;

    if (this != &otherList) // Avoid self-copy
    {
        if (first != NULL) // If the list is nonempty, make it empty
            destroy();

        if (otherList.first == NULL) // otherList is empty
        {
            first = NULL;
            last = NULL;
            count = 0;
        }
        else
        {
            while (current != NULL)
            {
                insert(current->info);
                current = current->next;
            }
        }
    }
}

template <class Type>
const doublyLinkedList<Type> &doublyLinkedList<Type>::operator=(const doublyLinkedList<Type> &otherList)
{
    if (this != &otherList) // Avoid self-copy
    {
        copyList(otherList);
    }

    return *this;
}

template <class Type>
doublyLinkedList<Type>::doublyLinkedList(const doublyLinkedList<Type> &otherList)
{
    first = NULL;
    last = NULL;
    count = 0;

    nodeType<Type> *temp = otherList.first; // temporary pointer to traverse the otherList

    // copy nodes from otherList
    while (temp != NULL)
    {
        insert(temp->info);
        temp = temp->next;
    }
}

template <class Type>
doublyLinkedList<Type>::~doublyLinkedList()
{
    destroy();
}

#endif