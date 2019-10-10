/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: dig_vect2.cpp
 * Description: In-lab exercise 1 (digitsfreq.cpp) but here, both digits and freq are still objects of the C++ <vector> class; but use iterators to access both their contents; do not use indexing.
 */
#include <iostream>
using namespace std;
#include <vector>       // Include <vector> library
#include <cmath>        // <cmath> for easy displaying of numbers w/o using new counter

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
        for (auto i = a.begin(); i != a.end(); i++) {   // Looping through vectors w iterators
                freq.at(*i)++;  // Increase counter if number in current position is same
        }
}

void results(vector<int>& freq)
{
        for (auto n = freq.begin(); n != freq.end(); n++) {     // Looping through vector w iterators
                cout <<  "digit " << abs(distance(n, freq.begin())) << " occurs " << *n << " times" << endl;
                        // Display counters for each number using abs (since distance will be -)
        }
}