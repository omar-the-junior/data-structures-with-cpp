#ifndef H_nodeType
#define H_nodeType
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};
#endif
