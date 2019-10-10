/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: states1.cpp
 * Description: In-lab exercise 2 (cstringsdemo.cpp) but in this version, use C++ strings only, no C-style strings; and use a vector of strings for the 2D array of char's. Use indexing or access methods for access (either [] or .at()), do not use iterators.
 */
#include <iostream>
using namespace std;
#include <string>       // C string library
#include <vector>       // Include <vector> library

int main()
{
        string line1;           // Change to string
        string line2 = "notre dame fighting irish";
        vector<string> states = {"Indiana", "Michigan", "Ohio", "Illinois", "Iowa"};
                                // Change to vector<string> array

        cout << "enter a line: ";
        getline(cin, line1);    // This getline is method of iostream's cin

        cout << "the first line is: " << line1 << endl;
        cout << "the second line is: " << line2 << endl;

        // Display states through looping ang getting each element in array w indexing
        cout << "the states are:" << endl;
        for (int i = 0; i < states.size(); i++)
                cout << " - " << states[i] << endl;

        // Nested loop to get indiv char w/in each element in array w indexing
        cout << "displaying the states with a space between letters:" << endl;
        for (int i = 0; i < states.size(); i++) {
                cout << " - ";
                for (int j = 0; j < states[i].size(); j++)
                        cout << states[i][j] << " ";
                cout << endl;
        }

        return 0;
}