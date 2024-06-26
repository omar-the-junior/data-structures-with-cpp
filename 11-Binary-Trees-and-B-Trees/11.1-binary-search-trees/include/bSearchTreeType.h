#ifndef H_bSearchTreeType
#define H_bSearchTreeType

#include "./binaryTreeType.h"
#include "./binaryTreeNode.h"
#include <iostream>
#include <cassert>

using namespace std;

template <class elemType>
class bSearchTreeType : public binaryTreeType<elemType>
{
public:
    bool search(const elemType &searchItem) const;
    void insert(const elemType &insertItem);
    void deleteNode(const elemType &deleteItem);

private:
    void deleteFromTree(binaryTreeNode<elemType> *&p);
};

template <class elemType>
bool bSearchTreeType<elemType>::search(const elemType &searchItem) const
{
    binaryTreeNode<elemType> *current;
    bool found = false;
    if (this->root == NULL)

        cerr << "Cannot search an empty tree." << endl;
    else
    {
        current = this->root;
        while (current != NULL && !found)
        {
            if (current->info == searchItem)
                found = true;
            else if (current->info > searchItem)
                current = current->llink;
            else
                current = current->rlink;
        }
    }
    return found;
}

template <class elemType>
void bSearchTreeType<elemType>::insert(const elemType &insertItem)
{
    binaryTreeNode<elemType> *current;
    binaryTreeNode<elemType> *trailCurrent;
    binaryTreeNode<elemType> *newNode;

    newNode = new binaryTreeNode<elemType>;
    assert(newNode != NULL);
    newNode->info = insertItem;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    // if the tree is empty, insert newNode as the root
    if (this->root == NULL)
        this->root = newNode;
    else // the tree is not empty
    {
        // Traverse the tree to find the place to insert newNode

        // Set current to point to the root
        current = this->root;

        while (current != NULL) // search the tree
        {
            trailCurrent = current; // set trailCurrent to current

            // if the insertItem is already in the tree, return
            if (current->info == insertItem)
            {
                cerr << "The insert item is already in the list duplicates are not allowed." << insertItem << endl;
                return;
            }
            else if (current->info > insertItem) // if the insertItem is less than the info in current, go to the left
                current = current->llink;
            else // if the insertItem is greater than the info in current, go to the right
                current = current->rlink;
        }

        if (trailCurrent->info > insertItem)
            trailCurrent->llink = newNode;
        else
            trailCurrent->rlink = newNode;
    }
}

template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree(binaryTreeNode<elemType> *&p)
{
    binaryTreeNode<elemType> *current;
    binaryTreeNode<elemType> *trailCurrent;
    binaryTreeNode<elemType> *temp;

    if (p == NULL)
        cerr << "Error: The node to be deleted is NULL." << endl;
    else if (p->llink == NULL && p->rlink == NULL)
    {
        temp = p;
        p = NULL;
        delete temp;
    }
    else if (p->llink == NULL)
    {
        temp = p;
        p = temp->rlink;
        delete temp;
    }
    else if (p->rlink == NULL)
    {
        temp = p;
        p = temp->llink;
        delete temp;
    }
    else
    {
        current = p->llink;
        trailCurrent = NULL;

        while (current->rlink != NULL)
        {
            trailCurrent = current;
            current = current->rlink;
        }
        p->info = current->info;

        if (trailCurrent == NULL) // current did not move; current == p->llink; adjust p
            p->llink = current->llink;
        else
            trailCurrent->rlink = current->llink;
        delete current;
    }
}

template <class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType &deleteItem)
{
    binaryTreeNode<elemType> *current;
    binaryTreeNode<elemType> *trailCurrent;
    bool found = false;

    if (this->root == NULL)
        cout << "Cannot delete from the empty tree." << endl;
    else
    {
        current = this->root;
        trailCurrent = this->root;

        while (current != NULL && !found)
        {
            if (current->info && !found)
                found = true;
            else
            {
                trailCurrent = current;
                if (current->info > deleteItem)
                    current = current->llink;
                else
                    current = current->rlink;
            }
        }

        if (current == NULL)
            cout << "The delete item is not in the tree." << endl;
        else if (found)
        {
            if (current == this->root)
                deleteFromTree(this->root);
            else if (trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->llink);
            else
                deleteFromTree(trailCurrent->rlink);
        }
    }
}

#endif