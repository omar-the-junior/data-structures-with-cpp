#ifndef H_personType
#define H_personType

#include <string>
using namespace std;
class personType
{
public:
    void print() const;
    void setName(string first, string last);
    personType &setFirstName(string first);
    personType &setLastName(string last);
    string getFirstName() const;
    string getLastName() const;
    // * Notice that in this definition of the class personType, we replace the default con- structor and the constructor with parameters by one constructor with default parameters.
    personType(string first = "", string last = "");

private:
    string firstName;
    string lastName;
};
#endif