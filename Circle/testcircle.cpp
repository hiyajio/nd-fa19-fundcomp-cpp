/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: testcircle.cpp
 * Description: Main program to test Circle class for Part 1 of lab (Circle)
 */
#include <iostream>
using namespace std;

// Include circle.h file for access
#include "circle.h"

int main()
{
    Circle c1(7), c2;

    cout << "circle 1:" << endl;
    c1.info();

    cout << "circle 2:" << endl;
    c2.setRadius(5.2);
    c2.info();

    return 0;
}