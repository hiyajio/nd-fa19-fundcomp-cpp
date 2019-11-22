#include <iostream>
#include <vector>
using namespace std;
#include <string>

string GetPhoneNumber(vector<string> nameVec, vector<string> phoneNumberVec, string contactName);

int main() {
    int amt;
    string contactName;

    cin >> amt;
    vector<string> nameVec(amt);
    vector<string> phoneNumberVec(amt);
    for (int i = 0; i < amt; i++) {
    cin >> nameVec.at(i);
    cin >> phoneNumberVec.at(i);
    }

    cin >> contactName;

    string phone = GetPhoneNumber(nameVec, phoneNumberVec, contactName);

    cout << phone << "\n";

    return 0;
}

string GetPhoneNumber(vector<string> nameVec, vector<string> phoneNumberVec, string contactName) {
    string phone;

    for (unsigned i = 0; i < nameVec.size(); i++) {
        if (contactName == nameVec.at(i)) {
            phone = phoneNumberVec.at(i);
        }
    }

    return phone;
}