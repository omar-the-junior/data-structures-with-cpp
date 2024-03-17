#include <iostream>
#include "../include/nodeType.h"
#include "../include/buildListForward.h"
#include "../include/buildListBackward.h"

using namespace std;

void printList(nodeType *list)
{
    nodeType *temp = list;
    while (temp != nullptr)
    {
        std::cout << temp->info << " ";
        temp = temp->link;
    }
    std::cout << std::endl;
}

int main()
{
    nodeType *forwardList = buildListForward();

    nodeType *backwardList = buildListBackward();

    cout << "Forward List result: ";
    printList(forwardList);
    cout << "Backward List result: ";
    printList(backwardList);
    return 0;
}