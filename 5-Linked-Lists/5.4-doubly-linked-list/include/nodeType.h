#ifndef H_nodeType
#define H_nodeType
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *next;
    nodeType<Type> *back;
};
#endif
