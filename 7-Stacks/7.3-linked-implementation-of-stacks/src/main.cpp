#include <string>
#include <iostream>
#include "../include/linkedSTackType.h"

using namespace std;

void testCopy(linkedStackType<int> OStack);
int main()
{
    linkedStackType<int> stack;
    linkedStackType<int> otherStack;
    linkedStackType<int> newStack;

    stack.push(34);
    stack.push(43);
    stack.push(27);

    newStack = stack;

    cout << "After the assignment operator, newStack: " << endl;

    while (!newStack.isEmptyStack())
    {
        cout << newStack.top() << endl;
        newStack.pop();
    }

    otherStack = stack;

    cout << "*~~~~~~~Testing the copy constructor~~~~~~~*" << endl;

    testCopy(otherStack);

    cout << "After the copy constructor, otherStack: " << endl;

    while (!otherStack.isEmptyStack())
    {
        cout << otherStack.top() << endl;
        otherStack.pop();
    }
    return 0;
}

void testCopy(linkedStackType<int> OStack)
{
    cout << "Stack in the function testCopy: " << endl;

    while (!OStack.isEmptyStack())
    {
        cout << OStack.top() << endl;
        OStack.pop();
    }
}