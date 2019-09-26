/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: sums.cpp
 * Description: Sums squares and square roots of 1-10 separately yet in the same loop
 */
#include <iostream>
using namespace std;
#include <cmath>

int main() {
        double sumSquares = 0;
        double sumRoots = 0;

        for (int i = 1; i < 11; i++) {
                sumSquares = sumSquares + pow(i, 2);
                sumRoots = sumRoots + sqrt(i);
        }

        cout << "Sum of squares of 1-10: " << endl;
        cout << sumSquares << endl;

        cout << "Sum of square roots of 1-10: " << endl;
        cout << sumRoots << endl;

        return 0;
}