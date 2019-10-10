/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: states1.cpp
 * Description: In-lab exercise 2 (cstringsdemo.cpp), same as states1.cpp but here use iterators; do not use indexing, nor any access operators or methods.
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
        getline(cin, line1);    // This getline is a method of iostream's cin

        cout << "the first line is: " << line1 << endl;
        cout << "the second line is: " << line2 << endl;

        // Display states through looping ang getting each element in array w iterators
        cout << "the states are:" << endl;
        for (auto i = states.begin(); i < states.end(); i++) {
                cout << " - " <<  *i << endl;
        }

        // Nested loop to get indiv char w/in each element in array w iterators
        cout << "displaying the states with a space between letters:" << endl;
        for (auto i = states.begin(); i < states.end(); i++) {
                cout << " - ";
                for (auto j = (*i).begin(); j < (*i).end(); j++)
                        cout << *j << " ";
                cout << endl;
        }

        return 0;
}
