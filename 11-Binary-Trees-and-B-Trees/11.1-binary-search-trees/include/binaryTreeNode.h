#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

template <class elemType>
struct binaryTreeNode
{
    elemType info;
    binaryTreeNode<elemType> *llink;
    binaryTreeNode<elemType> *rlink;
};

#endif // BINARYTREENODE_H