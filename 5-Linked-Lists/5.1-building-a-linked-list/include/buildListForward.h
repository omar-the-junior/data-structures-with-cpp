#ifndef H_buildListForward
#define H_buildListForward

#include "./nodeType.h"

#include <iostream>

using namespace std;

nodeType *buildListForward()
{
    nodeType *first, *newNode, *last;

    int num;

    cout << "Enter a list of integeres ending with -999."
         << endl;
    cin >> num;
    first = NULL;

    while (num != -999)
    {
        newNode = new nodeType;

        newNode->info = num;
        newNode->link = NULL;

        if (first == NULL)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->link = newNode;
            last = newNode;
        }
        cin >> num;
    }

    return first;
}

#endif