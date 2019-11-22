#include <iostream>
#include <vector>
using namespace std;
#include <math.h>

void ExactChange(int userTotal, vector<int> &coinVals);

int main() {
    int userTotal;
    vector<int> coinVals(5);

    cin >> userTotal;

    ExactChange(userTotal, coinVals);

    return 0;
    }

    void ExactChange(int userTotal, vector<int> &coinVals) {

    if (userTotal <= 0) {
        cout << "no change\n";
    } else {
        if (userTotal > 100) {
            int i = trunc(userTotal/100);
            for (; coinVals.at(0) < i; coinVals.at(0)++) {
            userTotal = userTotal - 100;
            }
            if (coinVals.at(0) > 1) {
            cout << coinVals.at(0) << " dollars\n";
            } else {
            cout << coinVals.at(0) << " dollar\n";
            }
        }
        if (userTotal > 25) {
            int j = trunc(userTotal/25);
            for (; coinVals.at(1) < j; coinVals.at(1)++) {
            userTotal = userTotal - 25;
            }
            if (coinVals.at(1) > 1) {
            cout << coinVals.at(1) << " quarters\n";
            } else {
            cout << coinVals.at(1) << " quarter\n";
            }
        }
        if (userTotal > 10) {
            int k = trunc(userTotal/10);
            for (; coinVals.at(2) < k; coinVals.at(2)++) {
            userTotal = userTotal - 10;
            }
            if (coinVals.at(2) > 1) {
            cout << coinVals.at(2) << " dimes\n";
            } else {
            cout << coinVals.at(2) << " dime\n";
            }
        }
        if (userTotal > 5) {
            int l = trunc(userTotal/5);
            for (; coinVals.at(3) < l; coinVals.at(3)++) {
            userTotal = userTotal - 5;
            }
            if (coinVals.at(3) > 1) {
            cout << coinVals.at(3) << " nickels\n";
            } else {
            cout << coinVals.at(3) << " nickel\n";
            }
        }
        if (userTotal > 0) {
            int m = trunc(userTotal/1);
            for (; coinVals.at(4) < m; coinVals.at(4)++) {
            userTotal = userTotal - 1;
            }
            if (coinVals.at(4) > 1) {
            cout << coinVals.at(4) << " pennies\n";
            } else {
            cout << coinVals.at(4) << " penny\n";
            }
        }
    }

}
