#include <iostream>
#include <string>
using namespace std;

int main() {

    char letter;
    string phrase;
    int counter = 0;

    cin >> letter;
    getline (cin, phrase);

    for (unsigned i = 0; i <= phrase.length(); i++) {
        if (letter == phrase[i]) {
            counter++;
        }
    }

    cout << counter << "\n";

    return 0;
}