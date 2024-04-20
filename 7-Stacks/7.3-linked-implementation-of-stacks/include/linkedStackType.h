#ifndef H_StackType
#define H_StackType

#include "./nodeType.h"
#include "./stackADT.h"
#include <cassert>
#include <iostream>

using namespace std;
template <class Type>
class linkedStackType : public stackADT<Type>
{
public:
    const linkedStackType<Type> &operator=(const linkedStackType<Type> &);

    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void push(const Type &newItem);
    Type top() const;
    void pop();

    linkedStackType();
    linkedStackType(const linkedStackType<Type> &otherStack);
    ~linkedStackType();

private:
    nodeType<Type> *stackTop;
    void copyStack(const linkedStackType<Type> &otherStack);
};

template <class Type>
void linkedStackType<Type>::initializeStack()
{
    nodeType<Type> *temp; // pointer to delete the node

    while (stackTop != NULL)
    {
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
}

template <class Type>
bool linkedStackType<Type>::isFullStack() const
{
    return false;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return (stackTop == NULL);
}

template <class Type>
void linkedStackType<Type>::push(const Type &newItem)
{
    nodeType<Type> *newNode;

    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = stackTop;

    stackTop = newNode;
}

template <class Type>
Type linkedStackType<Type>::top() const
{
    assert(stackTop != NULL);

    return stackTop->info;
}

template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;
    if (stackTop != NULL)
    {
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}

template <class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type> &otherStack)
{
    nodeType<Type> *newNode, *current, *last;

    if (stackTop != NULL) // If the stack is non-empty make it empty
        initializeStack();

    if (otherStack.stackTop == NULL)
        stackTop = NULL;
    else
    {
        current = otherStack.stackTop;

        stackTop = new nodeType<Type>;
        stackTop->info = current->info;
        stackTop->link = NULL;

        last = stackTop;
        current = current->link;

        while (current != NULL)
        {
            newNode = new nodeType<Type>;

            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

template <class Type>
linkedStackType<Type>::linkedStackType()
{
    stackTop = NULL;
}

template <class Type>
linkedStackType<Type>::~linkedStackType()
{
    initializeStack();
}

// Copy constructor
template <class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type> &otherStack)
{
    stackTop = NULL;
    copyStack(otherStack);
}

template <class Type>
const linkedStackType<Type> &linkedStackType<Type>::operator=(const linkedStackType<Type> &otherStack)
{
    if (this != &otherStack) // avoid self-copy
        copyStack(otherStack);

    return *this;
}

#endif