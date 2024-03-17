#ifndef H_linkedListIterator
#define H_linkedListIterator

#include "./nodeType.h"

template <class Type>
class linkedListIterator
{
private:
    nodeType<Type> *current;

public:
    linkedListIterator();
    linkedListIterator(nodeType<Type> *ptr);

    Type operator*();

    linkedListIterator<Type> operator++();
    bool operator==(const linkedListIterator<Type> &right) const;
    bool operator!=(const linkedListIterator<Type> &right) const;
};

// ⬇️ Implementation of the linkeListIterator ⬇️
template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = NULL;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current = current->link;
    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type> &right)
    const
{
    return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type> &right) const
{
    return (current != right.current);
}

#endif // H_linkedListIterator