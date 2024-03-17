#ifndef H_unorderedLinkedList
#define H_unorderedLinkedList

#include <iostream>
#include "./linkedListType.h"
#include "./nodeType.h"

using namespace std;

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:
    bool search(const Type &searchItem) const;
    void insertFirst(const Type &newItem);
    void insertLast(const Type &newItem);
    void deleteNode(const Type &deleteItem);
};

// ⬇️ Implementation of unorderedLinkedList ⬇️

template <class Type>
bool unorderedLinkedList<Type>::search(const Type &searchItem) const
{
    nodeType<Type> *current; // pointer to traverse the list
    bool found = false;

    current = this->first;

    while (current != NULL && !found)
        if (current->info == searchItem)
            found = true;
        else
            current = current->link;

    return found;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type &newItem)
{
    nodeType<Type> *newNode; // pointer to create the new node

    newNode = new nodeType<Type>; // create the new node
    newNode->info = newItem;      // store the new item in the node
    newNode->link = this->first;  // insert newNode before first
    this->first = newNode;        // make first point to the actual first node
    this->count++;                // increment count

    if (this->last == NULL) // if the list was empty, newNode is also the last node in the list
        this->last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type &newItem)
{
    nodeType<Type> *newNode;      // pointer to create the new node
    newNode = new nodeType<Type>; // create the new node
    newNode->info = newItem;      // store the new item in the node
    newNode->link = NULL;         // set the link field of newNode to NULL

    if (this->first == NULL)
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        this->last->link = newNode; // insert newNode after last
        this->last = newNode;       // make last point to the actual last node
        this->count++;              // increment count
    }
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type &deleteItem)
{
    nodeType<Type> *current;      // pointer to traverse the list
    nodeType<Type> *trailCurrent; // pointer just before current
    bool found;

    if (this->first == NULL)
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        if (this->first->info == deleteItem)
        {
            current = this->first;
            this->first = this->first->link;
            this->count--;

            if (this->first == NULL) // The list has only one node
                this->last = NULL;

            delete current;
        }
        else
        {
            found = false;
            trailCurrent = this->first; // set trailCurrent to point to the first node

            current = this->first->link; // set current to point to the second node

            while (current != NULL && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                    found = true;
            }
            if (found) // if found, delete the node
            {
                trailCurrent->link = current->link;
                this->count--;

                if (this->last == current)     // if the node to be deleted was the last node
                    this->last = trailCurrent; // update the value of last
                delete current;                // delete the node from the list
            }
            else
                cout << "The item to be deleted is not in the list." << endl;
        }
    }
}
#endif