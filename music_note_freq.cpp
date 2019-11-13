#include <iostream>
#include <math.h>
using namespace std;

int main() {

    double fZero;
    double r;
    double fN;
    double frac;

    cin >> fZero;

    frac = (double)1/12;
    r = pow(2.0, frac);

    for (int n = 0; n < 5; n++)
    {
        fN = fZero * pow(r, n);
        printf("%.2f", fN);

        if (n < 4)
        {
            cout << " ";
        }
        else
        {
            cout << "\n";
        }
    }

    return 0;
}