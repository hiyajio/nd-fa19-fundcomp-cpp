/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: rationalmain.cpp
 * Description: Main program to test Rational class for Part 2 of lab (Rational)
 */
#include <iostream>
using namespace std;

// Include rational.h file for access
#include "rational.h"

int main()
{
    Rational a(5,6), b(3,7), c, s;

    cout << "\n===== Display a and b =====\n";
    a.print();
    b.print();
    cout << "\n";
    cout << "===== Display c =====\n";
    c.print();  // Recall that c was instantiated with the default constructor
    cout << "\n";

    // 'Mathematically' add a and b
    cout << "===== Compute s as the math sum of a and b, and display s =====\n";
    s = a.add(b);
    s.print();
    cout << "\n";

    // 'Mathematically' subtract a and b
    cout << "===== Compute s as the math difference of a and b, and display s =====\n";
    s = a.subtract(b);
    s.print();
    cout << "\n";

    // 'Mathematically' multiply a and b
    cout << "===== Compute s as the math product of a and b, and display s =====\n";
    s = a.multiply(b);
    s.print();
    cout << "\n";

    // 'Mathematically' divide a and b
    cout << "===== Compute s as the math quotient of a and b, and display s =====\n";
    s = a.divide(b);
    s.print();
    cout << "\n\n";

    return 0;
}
