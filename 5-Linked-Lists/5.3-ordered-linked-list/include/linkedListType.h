#ifndef H_linkedListType
#define H_linkedListType

#include "./nodeType.h"
#include "./linkedListIterator.h"
#include <iostream>
#include <cassert>

using namespace std;
template <class Type>
class linkedListType
{
public:
    const linkedListType<Type> &operator=(const linkedListType<Type> &);
    void initializeList();
    bool isEmptyList() const;
    void print() const;
    int length() const;
    void destroyList();
    Type front() const;
    Type back() const;

    // These are pure virtual functions, denoted by '= 0' at the end of the function declaration.
    // A pure virtual function is a function that must be overridden in any non-abstract class that directly inherits from this class.
    // The purpose of these functions is to provide an interface for derived classes.
    // They make it possible to use polymorphism to invoke derived class methods through a base class pointer or reference.

    virtual bool search(const Type &searchItem) const = 0; // Must be overridden to search for a specific item.
    virtual void insertFirst(const Type &newItem) = 0;     // Must be overridden to insert an item at the beginning.
    virtual void insertLast(const Type &newItem) = 0;      // Must be overridden to insert an item at the end.
    virtual void deleteNode(const Type &deleteItem) = 0;   // Must be overridden to delete a specific item.
    linkedListIterator<Type> begin();
    linkedListIterator<Type> end();

    linkedListType();

    // Copy Constructor
    linkedListType(const linkedListType<Type> &otherList);

    ~linkedListType();

protected:
    int count;
    nodeType<Type> *first;
    nodeType<Type> *last;

private:
    void copyList(const linkedListType<Type> &otherList);
    // Function to make a copy of otherList
};

// .⬇️ Implementation of the linkedListType ⬇️

template <class Type>
linkedListType<Type>::linkedListType()
{
    first = NULL;
    last = NULL;
    count = 0;
}

// Copy Constructor is O(n)
template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type> &otherList)
{
    first = NULL;
    copyList(otherList);
}

// destructor is O(n)
template <class Type>
linkedListType<Type>::~linkedListType()
{
    destroyList();
}

// begin is O(1)
template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == NULL);
}

// destroyList is O(n)
template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp;
    while (first != NULL)
    {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = NULL;
    count = 0;
}

// initialize list is O(n)
template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList();
}

// print is O(n)
template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current;

    current = first;
    while (current != NULL)
    {
        cout << current->info << " ";
        current = current->link;
    }
}

// length is O(1)
template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}

// front is O(1)
template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != NULL); // If first is NULL, the list is empty, so we terminate the program.

    return first->info;
}

// back is O(1)
template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != NULL); // If last is NULL, the list is empty, so we terminate the program.

    return last->info;
}

// begin is O(1)
template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);
    return temp;
}

// end is O(1)
template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(NULL);
    return temp;
}

// copyList is O(n)
template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type> &otherList)
{
    nodeType<Type> *newNode; // pointer to create a node
    nodeType<Type> *current; // pointer to traverse the list

    if (first != NULL) // if the list is nonempty make it empty
        destroyList();

    if (otherList.first == NULL) // otherList is empty
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList.first; // current points to the list to be copied
        count = otherList.count;

        // Copy first node
        first = new nodeType<Type>;  // create the node
        first->info = current->info; // copy the info
        first->link = NULL;          // set the link field of the node to NULL
        last = first;                // make last point to the first node
        current = current->link;     // make current point to the next node

        // Copy the remaining list
        while (current != NULL)
        {
            newNode = new nodeType<Type>;  // create a node
            newNode->info = current->info; // copy the info
            newNode->link = NULL;          // set the link of newNode to NULL
            last->link = newNode;          // attach newNode after last
            last = newNode;                // make last point to the actual last node
            current = current->link;       // make current point to the next node
        }
    }
}

// operator= is O(n)
template <class Type>
const linkedListType<Type> &linkedListType<Type>::operator=(const linkedListType<Type> &otherList)
{
    if (this != &otherList) // avoid self-copy
    {
        copyList(otherList);
    }

    return *this;
}
#endif