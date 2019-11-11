/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: rationalmain.cpp
 * Description: Main program to test Rational class
 */
#include <iostream>
using namespace std;

// Include rational.h file for access
#include "rational.h"

int main()
{
    Rational a, b, c, s;

    cout << "\n\n========== Fractions Operations Solver ==========\n";
    cin >> a;
    cin >> b;

    cout << "\n===== Display a and b =====\n";
    cout << a << "\n";
    cout << b << "\n";
    cout << "\n";
    cout << "===== Display c =====\n";
    cout << c << "\n";  // Recall that c was instantiated with the default constructor

    // 'Mathematically' add a and b
    cout << "===== Compute s as the math sum of a and b, and display s =====\n";
    s = a+b;
    cout << s << "\n";

    // 'Mathematically' subtract a and b
    cout << "===== Compute s as the math difference of a and b, and display s =====\n";
    s = a-b;
    cout << s << "\n";

    // 'Mathematically' multiply a and b
    cout << "===== Compute s as the math product of a and b, and display s =====\n";
    s = a*b;
    cout << s << "\n";

    // 'Mathematically' divide a and b
    cout << "===== Compute s as the math quotient of a and b, and display s =====\n";
    s = a/b;
    cout << s << "\n";

    return 0;
}
