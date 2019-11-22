#include <iostream>
using namespace std;
#include <math.h>

int MaxMagnitude (int, int);

int main() {
    int userVal1;
    int userVal2;
    int magnitude;

    cin >> userVal1;
    cin >> userVal2;

    magnitude = MaxMagnitude(userVal1, userVal2);
    cout << magnitude << "\n";

    return 0;
    }

    int MaxMagnitude(int userVal1, int userVal2) {
    int magnitude;
    if (abs(userVal1) > abs(userVal2)) {
        magnitude = userVal1;
    } else if (abs(userVal1) < abs(userVal2)) {
        magnitude = userVal2;
    } else {
        magnitude = userVal1;
    }

    return magnitude;
}