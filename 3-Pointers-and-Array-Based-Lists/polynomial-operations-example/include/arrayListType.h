#ifndef H_arrayListType
#define H_arrayListType
template <class elemType>
class arrayListType
{
public:
    const arrayListType<elemType> &operator=(const arrayListType<elemType> &);
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const;
    int maxListSize() const;
    void print() const;
    bool isItemAtEqual(int location, const elemType &item) const;
    void insertAt(int location, const elemType &insertItem);
    void insertEnd(const elemType &insertItem);
    void removeAt(int location);
    void retrieveAt(int location, elemType &retItem) const;
    void replaceAt(int location, const elemType &repItem);
    void clearList();
    int seqSearch(const elemType &item) const;
    void insert(const elemType &insertItem);
    void remove(const elemType &removeItem);

    arrayListType(int size = 100);
    arrayListType(const arrayListType<elemType> &otherList);
    // Copy constructor

    ~arrayListType();
    // Destructor
    // Deallocate the memory occupied by the array.

protected:
    elemType *list; // Array to hold the list elements
    int length;     // to store the length of the list
    int maxSize;    // to store the maximum size of the list
};

#endif