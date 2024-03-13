class classIllusFriend
{
    friend void friendFunc(classIllusFriend cIFObject);

private:
    int x;

public:
    void print();
    void setX(int a);
};
