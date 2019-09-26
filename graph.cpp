/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: graph.cpp
 * Description: Displays graph of 10.0 * (1.0+sin(x)) from x = 0 to x = 20.
 */
#include <iostream>
using namespace std;
#include <iomanip>
#include <cmath>

int main() {
        cout << "\n\nA plot of y = 10*(1+sin(x)) from x=0 to 20.0\n\n";         //Plot and range chosen
        cout << right << setw(10) << 'X' << right << setw(10) << 'Y' << "\n";   // Table header

        float x = 0.0;          // Start of range
        float maX = 20.1;       // End of range (must be 20.1 since will be used to increment and compare later and c++ stores 20.0 differently after increments
        float minY = 100000;    // Arbitary large number to make comparison to number auto less
        float maxY = 0;         // Arbitary small number to make comparison to number auto more
        float minAtX;           // Where "location" (x) of minimum will be stored
        float maxAtX;           // Where "location" (x) of maximum will be stored
        float y;                // To be calculated
        int displaY;            // For displaying appropriate number of "*"

        cout << fixed;  // Formatting
        cout << setprecision(2);        // Set decimal precision to 2

        for (float x = 0; x <= maX; x = x + 0.20) {
                y = 10.0*(1 + sin(x));  // Formula chosen
                displaY = ceil(y);      // Picks appropriate number of "*" based on y just solved
                cout << right << setw(10) << x << right << setw(10) << y << " ";        // Display row

                if (y > maxY) {         // Store y and x if maximum occurs
                        maxY = y;
                        maxAtX = x;
                }

                if (y < minY) {         // Store y and x if minimum occurs
                        minY = y;
                        minAtX = x;
                }

                for (unsigned j = 0; j < displaY; ++j) {        // Display number of "*" based on displaY
                        cout << "*";
                }
                cout << "\n";   // Formatting

        }

        cout << "\n";   // Formatting

        cout << "The maximum of ";
        if (maxY > 9.99) {      // Formatting, if number is 10 and above, take away one number after decimal
                cout << setprecision(1);
                cout << maxY;
        } else {
                cout << setprecision(2);
                cout << maxY;
        }

        cout << " was at x=";

        if (maxAtX < 10) {      // Formatting, if number is 10 and above, take away one number after decimal
                cout << setprecision(2);
                cout << maxAtX << "\n";
        } else {
                cout << setprecision(1);
                cout << maxAtX << "\n";
        }

        cout << "The minimum of ";
        if (minY > 9.99) {      // Formatting, if number is 10 and above, take away one number after decimal
                cout << setprecision(1);
                cout << minY;
        } else {
                cout << setprecision(2);
                cout << minY;
        }

        cout << " was at x=";

        if (minAtX < 10) {      // Formatting, if number is 10 and above, take away one number after decimal
                cout << setprecision(2);
                cout << minAtX << "\n";
        } else {
                cout << setprecision(1);
                cout << minAtX << "\n";
        }

        cout << "\n\n"; // Formatting

        return 0;
}