#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string inputMonth;
    int inputDay;

    cin >> inputMonth;
    cin >> inputDay;

    if (inputMonth == "January") {
        if (inputDay > 31 || inputDay < 0) {
            cout << "invalid\n";
        } else {
            cout << "winter\n";
        }
    } else if (inputMonth == "February") {
        if (inputDay > 31 || inputDay < 0) {
            cout << "invalid\n";
        } else {
            cout << "winter\n";
        }
    } else if (inputMonth == "March") {
        if (inputDay > 31 || inputDay < 0) {
            cout << "invalid\n";
        } else if (inputDay < 20) {
            cout << "winter\n";
        } else {
            cout << "spring\n";
        }
    } else if (inputMonth == "April") {
        if (inputDay > 30 || inputDay < 0) {
            cout << "invalid\n";
        } else {
            cout << "spring\n";
        }
    } else if (inputMonth == "May") {
        if (inputDay > 31 || inputDay < 0) {
            cout << "invalid\n";
        } else {
            cout << "spring\n";
        }
    } else if (inputMonth == "June") {
        if (inputDay > 30 || inputDay < 0) {
            cout << "invalid\n";
        } else if (inputDay < 21) {
            cout << "spring\n";
        } else {
            cout << "summer\n";
        }
    } else if (inputMonth == "July") {
        if (inputDay > 31 || inputDay < 0) {
            cout << "invalid\n";
        } else {
            cout << "summer\n";
        }
    } else if (inputMonth == "August") {
        if (inputDay > 31 || inputDay < 0) {
            cout << "invalid\n";
        } else {
            cout << "summer\n";
        }
    } else if (inputMonth == "September") {
        if (inputDay > 30 || inputDay < 0) {
            cout << "invalid\n";
        } else if (inputDay < 22) {
            cout << "summer\n";
        } else {
            cout << "autumn\n";
        }
    } else if (inputMonth == "October") {
        if (inputDay > 31 || inputDay < 0) {
            cout << "invalid\n";
        } else {
            cout << "autumn\n";
        }
    } else if (inputMonth == "November") {
        if (inputDay > 30 || inputDay < 0) {
            cout << "invalid\n";
        }  else {
            cout << "autumn\n";
        }
    } else if (inputMonth == "December") {
        if (inputDay > 31 || inputDay < 0) {
            cout << "invalid\n";
        } else if (inputDay < 21) {
            cout << "autumn\n";
        } else {
            cout << "winter\n";
        }
    } else {
        cout << "invalid\n";
    }

    return 0;
}