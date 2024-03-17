#ifndef H_arrayListType
#define H_arrayListType

#include <iostream>
#include <cassert>
#include "../include/arrayListType.h"

using namespace std;

template <class elemType>
class arrayListType
{
public:
    const arrayListType<elemType> &operator=(const arrayListType<elemType> &);
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const;
    int maxListSize() const;
    void print() const;
    bool isItemAtEqual(int location, const elemType &item) const;
    void insertAt(int location, const elemType &insertItem);
    void insertEnd(const elemType &insertItem);
    void removeAt(int location);
    void retrieveAt(int location, elemType &retItem) const;
    void replaceAt(int location, const elemType &repItem);
    void clearList();
    int seqSearch(const elemType &item) const;
    void insert(const elemType &insertItem);
    void remove(const elemType &removeItem);

    arrayListType(int size = 100);
    arrayListType(const arrayListType<elemType> &otherList);
    // Copy constructor

    ~arrayListType();
    // Destructor
    // Deallocate the memory occupied by the array.

protected:
    elemType *list; // Array to hold the list elements
    int length;     // to store the length of the list
    int maxSize;    // to store the maximum size of the list
};

// ⬇️ The implementation of the arrayListType class ⬇️
template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
    return (length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
    return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const
{
    return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
    return maxSize;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType &item) const
{
    return (list[location] == item);
}

// ⬆️ Each of the above Functions are O(1) ⬆️

// ⬇️ The print Function below is O(n) ⬇️
template <class elemType>
void arrayListType<elemType>::print() const
{
    for (int i = 0; i < length; i++)
    {
        cout << list[i] << " ";
    }
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType &insertItem)
{
    if (location < 0 || location >= maxSize)
        cerr << "The position of the item to be inserted is out of range" << endl;
    else
    {
        if (length >= maxSize) // list is full
            cerr << "Cannot insert in a full list" << endl;
        else
        {
            for (int i = length; i > location; i--)
                list[i] = list[i - 1];   // move the elements down
            list[location] = insertItem; // insert the item at the specified position
            length++;                    // increment the length
        }
    }
}

// The insertEnd Function is O(1)
template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType &insertItem)
{
    if (length >= maxSize)
        cerr << "Cannot insert in a full list" << endl;
    else
    {
        list[length] = insertItem; // insert the item at the end
        length++;                  // increment the length
    }
}

// The removeAt Function is O(n)
template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be removed is out of range" << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i + 1]; // move the elements up
        length--;                  // decrement the length
    }
}

// The retrieveAt Function is O(1)
template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType &retItem) const
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be retrieved is out of range" << endl;
    else
        retItem = list[location];
}

// The replaceAt Function is O(1)
template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType &repItem)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be replaced is out of range" << endl;
    else
        list[location] = repItem;
}

template <class elemType>
void arrayListType<elemType>::clearList()
{
    length = 0;
}

// Both the constructor and the destructor are O(1)
template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating an array of size 100." << endl;

        maxSize = 100;
    }
    else
        maxSize = size;

    length = 0;
    list = new elemType[maxSize];
    assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete[] list;
}

// Both The copy constructor and operator overloading is O(n)
template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType> &otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize];
    assert(list != NULL);

    for (int j = 0; j < length; j++) // Copy otherList
        list[j] = otherList.list[j];
}

// Overloading the assignment operator
template <class elemType>
const arrayListType<elemType> &arrayListType<elemType>::operator=(const arrayListType<elemType> &otherList)
{
    if (this != &otherList) // avoid self-assignment
    {
        delete[] list;
        maxSize = otherList.maxSize;
        length = otherList.length;

        list = new elemType[maxSize];
        assert(list != NULL);

        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
    return *this;
}

// The function seqSearch is O(n)
template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType &item) const
{
    int loc;
    bool found = false;

    for (loc = 0; loc < length; loc++)
    {
        if (list[loc] == item)
        {
            found = true;
            break;
        }
    }

    if (found)
        return loc;
    else
        return -1;
}
// The complexity of both insert and delete functions is O(n)
template <class elemType>
void arrayListType<elemType>::insert(const elemType &insertItem)
{
    int loc;

    if (length == 0)
        list[length++] = insertItem; // insert the item and increment the length
    else if (length == maxSize)
        cerr << "Cannot insert in a full list" << endl;
    else
    {
        loc = seqSearch(insertItem);

        if (loc == -1)
            list[length++] = insertItem;
        else
            cerr << "The item to be inserted is already in the list. No duplicates are allowed." << endl;
    }
}

template <class elemType>
void arrayListType<elemType>::remove(const elemType &removeItem)
{
    int loc;

    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);

        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list."
                 << endl;
    }
}

#endif
