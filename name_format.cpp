#include <iostream>
#include <string>
using namespace std;

int main() {

    string firstName;
    string middleName;
    string lastName;

    cin >> firstName;
    cin >> middleName;
    cin >> lastName;

    if (lastName == "") {
        lastName = middleName;
        cout << lastName << ", " << firstName << "\n";

    } else {
        middleName = middleName.at(0);
        cout << lastName << ", " << firstName << " " << middleName << ".\n";

    }

    return 0;
}