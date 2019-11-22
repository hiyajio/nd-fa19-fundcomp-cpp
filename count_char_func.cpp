#include <iostream>
using namespace std;
#include <string>

int CountCharacters(char userChar, string userString);

int main() {
    char userChar;
    string userString;
    int chars = 0;

    cin >> userChar;
    getline(cin, userString);

    chars = CountCharacters(userChar, userString);

    cout << chars << "\n";

    return 0;
    }

    int CountCharacters(char userChar, string userString) {
    int chars = 0;

    for (unsigned i = 0; i < userString.length(); i++) {
        if (userString[i] == userChar) {
            chars++;
        }
    }

    return chars;
}