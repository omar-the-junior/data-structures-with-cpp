#include <string>
#include <iostream>
#include <fstream> // for file I/O
#include "../include/stackType.h"

using namespace std;

int main()
{
    double GPA;
    double highestGPA;
    string name;

    stackType<string> stack(100);

    // Declare an input file stream object
    ifstream infile;

    // Open the file
    infile.open("./students.txt");

    // Check if the file was successfully opened
    if (!infile)
    {
        cout << "The input file does not exist. " << endl
             << "Exiting Program..." << endl;
        return 1;
    }

    // Read the file data
    infile >> GPA >> name;

    // Initialize the highest GPA
    highestGPA = GPA;

    // Loop through the file data
    while (infile)
    {

        if (GPA > highestGPA)
        {
            stack.initializeStack();
            if (!stack.isFullStack())
                stack.push(name);

            highestGPA = GPA;
        }
        else if (GPA == highestGPA)
        {
            if (!stack.isFullStack())
                stack.push(name);
            else
            {
                cout << "Stack is full. Cannot add more students with the same GPA." << endl;
                return 1;
            }
        }
        infile >> GPA >> name; // read file data
    }

    infile.close();
    // Close the file

    cout << "Highest GPA: " << highestGPA << endl;
    cout << "The students holding the highest GPA are: " << endl;

    // Print the students names with the highest GPA
    while (!stack.isEmptyStack())
    {
        cout << stack.top() << endl;
        stack.pop();
    }

    cout << endl;
    return 0;
}