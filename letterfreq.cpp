/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: letterfreq.cpp
 * Description: Counts and displays each occurrence of letter and white space in .txt file along w total # of letters, characters & space %
 */
#include <iostream>                             // Library Declarations
using namespace std;
#include <iomanip>
#include <string>
#include <list>
#include <vector>
#include <array>
#include <fstream>
#include <iterator>
#include <cctype>
#include <algorithm>

int main() {
    int select = 0;         // Variable Declarations
    string file;
    string str;
    list<char> letters({'a', 'b', 'c', 'd', 'e',
                        'f', 'g', 'h', 'i', 'j',
                        'k', 'l', 'm', 'n', 'o',
                        'p', 'q', 'r', 's', 't',
                        'u', 'v', 'w', 'x', 'y', 'z'});
    list<int> occur(26, 0);     // Initialize list "occur" w 0's
    char c;
    int alphaCount = 0;
    int charCount = 0;
    int spaceCount = 0;

    cout << setprecision(3);    // Formatting

    cout << "\n\n======= Welcome to the character counter! =======\n\n";
    cout << "Enter name of startup file: ";
    cin >> file;        // Ask user for file name to be loaded
    cout << "\n";

    ifstream my_file(file);
    if (my_file.good()) {       // Checks if file exists, if not, display error message & terminate program
        list<int>::iterator in;  // Create iterator pointing to first element for "occur"
        while (my_file.get(c)) {     // Gets individual char from file one-by-one
            c = tolower(c);     // Lowercase received char
            if (isalpha(c)) {   // If letter
                in = occur.begin();     // Initialize iterator
                alphaCount++;   // Increase letter count
                for (auto i = letters.begin(); i != letters.end(); i++) {
                    if (c == *i) {
                        advance(in, distance(letters.begin(), i));  // Move iterator based on list "letter" position
                        (*in)++;    // Increment accompanying slot in list "occur"
                    }
                }
            } else if (isspace(c)) {    // If a white space
                spaceCount++;   // Increase white space count
            }
            charCount++;    // Increase total char count
        }

        int counter = 0;    // Counter for formatting
        auto j = occur.begin();     // Initialize iterator for list "occur"
        for (auto i = letters.begin(); i != letters.end(); i++) {  // Display all letters using iterators (for list "letters")
            if (counter < 5) {
                cout << right << setw(2) << *i << ": ";
                if (alphaCount > 1000000) {     // Formatting
                    cout << setw(7);
                } else if (alphaCount > 100000) {
                    cout << setw(5);
                } else if (alphaCount > 10000) {
                    cout << setw(3);
                } else {
                    cout << setw(2);
                }
                cout << *j << " ";          // Display count of letter
                counter++;
            } else {
                cout << right << setw(2) << *i << ": ";
                if (alphaCount > 1000000) {     // Formatting
                    cout << setw(7);
                } else if (alphaCount > 100000) {
                    cout << setw(5);
                } else if (alphaCount > 10000) {
                    cout << setw(3);
                } else {
                    cout << setw(2);
                }
                cout << *j << " \n";        // Display count of letter
                counter = 0;
            }
            j++;    // Increment list "occur"
        }

        cout << "\n\n";     // Formatting
        cout << "There were " << alphaCount << " letters.\n";                   // Display total letters
        cout << "There were " << charCount << " total characters.\n";           // Display total char
        cout << "There were " << spaceCount << " white space characters.\n";    // Display total white space

        double spacePercent = (double(spaceCount)/double(charCount))*100.0;     // Compute for space %
        cout << "Space percentage: " << spacePercent << "%\n\n\n";              // Display space %

    } else {
        cout << "Error in opening file: \"" << file << "\"!\n\n\n"; // Error message & formatting
    }

    return 0;
}