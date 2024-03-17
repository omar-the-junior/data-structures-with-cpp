#ifndef H_buildListBackward
#define H_buildListBackward

#include "./nodeType.h"

#include <iostream>

using namespace std;

nodeType *buildListBackward()
{
    nodeType *first, *newNode;
    int num;

    cout << "Enter a list of integeres ending with -999."
         << endl;

    cin >> num;
    first = NULL;

    while (num != -999)
    {
        newNode = new nodeType;
        newNode->info = num;
        newNode->link = first;

        first = newNode;
        cin >> num;
    }

    return first;
}
#endif