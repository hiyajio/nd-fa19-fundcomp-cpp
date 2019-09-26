/* Formula Calculator - Hypotenuse Solver
 * Name: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
        float aV;
        float bV;
        float cV;

        // Begin program, ask user for input
        cout << "\n\n\n=====Hypotenuse Solver through Pythagoras' Theorem=====\n\n";
        cout << "Side 1 (a in formula)? ";
        cin >> aV;
        cout << "Side 2 (b in formula)? ";
        cin >> bV;

        // Variables to store squares of a & b
        float aVS;
        float bVS;

        // Square the two inputs for formula
        aVS = pow(aV, 2.0);
        bVS = pow(bV, 2.0);

        // Pythagoras' Theorem
        cV = sqrt(aVS + bVS);

        // Display hypotenuse to user
        cout << "\n\n=====Hypotenuse of Triangle through Selected Sides=====\n\n";
        cout << cV << " is side c or the hypotenuse!\n\n\n";

        return 0;
}
