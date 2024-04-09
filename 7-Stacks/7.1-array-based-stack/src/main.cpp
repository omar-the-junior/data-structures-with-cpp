#include <iostream>
#include "../include/stackType.h"

using namespace std;

void testCopyConstructor(stackType<int> &otherStack);

int main()
{
    stackType<int> stack(50);
    stackType<int> copyStack(50);
    stackType<int> dummyStack(100);

    stack.initializeStack();
    stack.push(23);
    stack.push(45);
    stack.push(38);
    copyStack = stack;

    cout << "The elements of copyStack: ";

    while (!copyStack.isEmptyStack())
    {
        cout << copyStack.top() << " ";
        copyStack.pop();
    }

    cout << endl;

    copyStack = stack;
    testCopyConstructor(stack);

    if (!stack.isEmptyStack())
        cout << "The original stack is not empty." << endl
             << "The top element of the original stack: "
             << stack.top() << endl;

    dummyStack = stack; // copy stack into dummyStack;
    cout << "The elements of dummyStack: ";

    while (!dummyStack.isEmptyStack())
    {
        cout << dummyStack.top() << " ";
        dummyStack.pop();
    }

    cout << endl;

    return 0;
}

void testCopyConstructor(stackType<int> &otherStack)
{
    if (!otherStack.isEmptyStack())
        cout << "otherStack is not empty." << endl
             << "The top element of otherStack: "
             << otherStack.top() << endl;
}