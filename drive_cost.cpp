#include <iostream>
using namespace std;
#include <iomanip>

/* Define your function here */
double DrivingCost(double, double, double);

int main() {
    cout << fixed << setprecision(2);
    double drivenMiles[3] = {10, 50, 400};
    double milesPerGallon;
    double dollarsPerGallon;
    double cost;
    cin >> milesPerGallon;
    cin >> dollarsPerGallon;

    for (int i = 0; i < 3; ++i) {
        cost = DrivingCost(drivenMiles[i], milesPerGallon, dollarsPerGallon);

        cout << cost;

        if (i != 2) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }

    return 0;
    }

    double DrivingCost(double drivenMiles, double milesPerGallon, double dollarsPerGallon) {
    double cost;
    cost = drivenMiles / milesPerGallon * dollarsPerGallon;

    return cost;
}