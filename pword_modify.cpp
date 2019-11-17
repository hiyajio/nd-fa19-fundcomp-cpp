#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    string password;
    cin >> password;

    replace(password.begin(), password.end(), 'i', '!');
    replace(password.begin(), password.end(), 'a', '@');
    replace(password.begin(), password.end(), 'm', 'M');
    replace(password.begin(), password.end(), 'B', '8');
    replace(password.begin(), password.end(), 'o', '.');
    password.append("q*s");

    cout << password << "\n";

    return 0;
}