/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: dig_vect1.cpp
 * Description: In-lab exercise 1 (digitsfreq.cpp) but here, both digits and freq are objects of the <vector> class; use indexing to access both their contents; do not use iterators.
 */
#include <iostream>
using namespace std;
#include <vector>       // Include <vector> library

void find_freqs(vector<int>& a, vector<int>& freq);     // Function prototypes w vectors
void results(vector<int>& freq);

int main()
{
        // Array w random digits
        vector<int> digits = {4,3,6,5,7,8,9,4,6,3,1,3,5,7,6,3,6,5,6,7,0,2,9,7,1,3,2,1,6,7,4,6,2,8,1,4,5,6,0,2,7,6,4,5,6,8,3,5,7,1,5};

        // Freq array tallies the frequency of digits
        // iow: for each digit i from 0 to 9, freq[i] will contain
        // # of i's that are in the digits[] array
        vector<int> freq(10);           // Initialize the array to all 0's
        find_freqs(digits, freq);       // Compute digits' frequencies
        results(freq);                  // Display frequencies for each digit

        return 0;
}

void find_freqs(vector<int>& a, vector<int>& freq)
{
        for (int i = 0; i < a.size(); i++) {            // Looping through vectors w indexing
                for (int j = 0; j < a.size(); j++) {
                        if (a[j] == i) {
                                // If number in currect index is equal to regular
                                // marching number (0 - 9), increase counter at position
                                freq.at(i)++;
                        }
                }
        }
}

void results(vector<int>& freq)
{
        for (int n = 0; n < freq.size(); n++)           // Looping through vector w indexing
                cout <<  "digit " << n << " occurs " << freq[n] << " times" << endl;
                                                        // Display counters for each number
}