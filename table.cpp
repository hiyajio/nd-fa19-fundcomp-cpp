/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: table.cpp
 * Description: Displays integer multiplication table through user input asking for size of table (X and Y axes) and with top row header and left column header
 */
#include <iostream>
using namespace std;
#include <iomanip>

int main() {
        int x;  // For x-axis input
        int y;  // For y-axis input

        cout << "\n\n===== Multiplication Table Maker =====\n\n";
        cout << "What is your x-axis for the table? (input integer)\n";
        cin >> x;       // Ask for x-axis input

        cout << "What is your y-axis for the table? (input integer)\n";
        cin >> y;       // Ask for y-axis input
        cout << "\n";   // Formatting

        cout << setw(5) << '*'; // Start table w/ '*' on upper left corner

        for (int k = 1; k <= x; ++k) {
                cout << right << setw(5) << k;  // Create x-axis header
        }

        for (int i = 1; i <= y; ++i) {
                cout << "\n" << right << setw(5) << i;  // Create y-axis header (moves cursor to next row in table)

                for (int j = 1; j <= x; ++j) {
                        cout << right << setw(5) << i * j;      // Fill up table using x*y
                }
        }

        cout << "\n\n\n";       //Formatting

        return 0;
}