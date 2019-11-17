#include <iostream>
#include <string>
using namespace std;

int main() {
    string userText;
    char period = '.';
    char space = ' ';
    char comma = ',';
    int counter = 0;

    getline(cin, userText);  // Gets entire line, including spaces.

    for (unsigned i = 0; i < userText.length(); i++) {
        if (userText[i] == period) {

        } else if (userText[i] == space) {

        } else if (userText[i] == comma) {

        } else {
            counter++;
        }
    }

    cout << counter << "\n";

    return 0;
}