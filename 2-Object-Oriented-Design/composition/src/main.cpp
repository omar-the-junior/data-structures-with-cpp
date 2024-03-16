#include <iostream>
#include "../include/personalInfoType.h"

int main()
{
    personalInfoType person("John", "Doe", 12, 31, 1999, 1234);

    person.printPerfonalInfo();
    return 0;
}
