/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: primes.cpp
 * Description: Displays prime numbers between 1 - 1000 using Sieve of Eratosthenes Algorithm.
 */
#include <iostream>                             // Library Declarations
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int size = 1000;                        // Variable Declarations
    int numb[size];
    for (int i = 0; i < size; ++i) {
            numb[i] = 1;    // Initialize Array to All Have 1's in Each Element
    }

    cout << "\n\n======= Prime Numbers between 1 - 1000 =======\n\n";
            // Header

    int limit = sqrt(size) + 1;     // Have to add 1 since sqrt function truncates
                                    // If not, sqrt becomes 31 which includes 961 as prime
                                    // because loop ends before checking 31

    for (int j = 2; j < limit; ++j) {       // Sieve of Eratosthenes Algorithm
            if (numb[j] == 1) {
                    int k = pow(j, 2);
                    for (k; k < size; k+=j) {
                            numb[k] = 0;
                    }
            }
    }

    int m = 0;      // Initialize counter for formatting (10 per row)

    for (int l = 2; l < size; ++l) {        // Display prime numbers
            if (numb[l] == 1) {
                    cout << right << setw(5) << l << " ";
                    m++;
            }
            if (m == 10) {                  // Create new row after displaying 10 numbers
                    cout << "\n";
                    m = 0;                  // Set to 0 to fill up row requirement again
            }
    }

    cout << "\n\n\n";                       // Formatting

    return 0;
}