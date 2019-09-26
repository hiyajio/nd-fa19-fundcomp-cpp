/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: roots.cpp
 * Description: Computes the roots of a quadratic equation
 */
#include <iostream>
using namespace std;
#include <cmath>

int main()
{
    double a, b, c, disc;
    double x1, x2;

    cout << "Enter the coefficients (a,b,c) of a quadratic equation: ";
    cin >> a >> b >> c;

    double root1;
    double root2;

    root1 = (-b + sqrt(pow(b, 2) - 4*a*c))/(2*a);
    root2 = (-b - sqrt(pow(b, 2) - 4*a*c))/(2*a);

    cout << "Roots of the quadratic equation: " << endl;
    cout << root1 << endl;
    cout << root2 << endl;

    return 0;
}