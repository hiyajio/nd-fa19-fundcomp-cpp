/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: cstringsdemo.cpp
 * Description: In-lab exercise 2: Intro to <vector> class
 */
#include <iostream>
using namespace std;
#include <cstring>  // the C string library; needed for strlen() below

int main()
{
        char line1[50];
        char line2[] = "notre dame fighting irish";
        char states[5][20] = {"Indiana", "Michigan", "Ohio", "Illinois", "Iowa"};

        cout << "enter a line: ";
        cin.getline(line1, 50);   // this getline is a method of iostream's cin
                                // it is for C strings only

        cout << "the first line is: " << line1 << endl;
        cout << "the second line is: " << line2 << endl;

        // display the states; recall that states[i] is a C string (array of char)
        cout << "the states are:" << endl;
        for (int i = 0; i < 5; i++)
                cout << " - " << states[i] << endl;

        // since we need to access each character here, we need nested for loops
        cout << "displaying the states with a space between letters:" << endl;
        for (int i = 0; i < 5; i++) {
                cout << " - ";
                for (int j = 0; j < strlen(states[i]); j++)
                        cout << states[i][j] << " ";
                cout << endl;
        }

        return 0;
}