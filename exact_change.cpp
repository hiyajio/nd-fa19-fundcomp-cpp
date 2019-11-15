#include <iostream>
using namespace std;
#include <math.h>

int main() {

    int money;
    int dollar = 0;
    int quarter = 0;
    int dime = 0;
    int nickel = 0;
    int penny = 0;

    cin >> money;

    if (money <= 0) {
        cout << "no change\n";
    } else {
        if (money > 100) {
            int i = trunc(money/100);
            for (; dollar < i; dollar++) {
            money = money - 100;
            }
            if (dollar > 1) {
            cout << dollar << " dollars\n";
            } else {
            cout << dollar << " dollar\n";
            }
        }
        if (money > 25) {
            int j = trunc(money/25);
            for (; quarter < j; quarter++) {
            money = money - 25;
            }
            if (quarter > 1) {
            cout << quarter << " quarters\n";
            } else {
            cout << quarter << " quarter\n";
            }
        }
        if (money > 10) {
            int k = trunc(money/10);
            for (; dime < k; dime++) {
            money = money - 10;
            }
            if (dime > 1) {
            cout << dime << " dimes\n";
            } else {
            cout << dime << " dime\n";
            }
        }
        if (money > 5) {
            int l = trunc(money/5);
            for (; nickel < l; nickel++) {
            money = money - 5;
            }
            if (nickel > 1) {
            cout << nickel << " nickels\n";
            } else {
            cout << nickel << " nickel\n";
            }
        }
        if (money > 0) {
            int m = trunc(money/1);
            for (; penny < m; penny++) {
            money = money - 1;
            }
            if (penny > 1) {
            cout << penny << " pennies\n";
            } else {
            cout << penny << " penny\n";
            }
        }
    }

    return 0;
}