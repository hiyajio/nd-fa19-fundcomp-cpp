#include <iostream>
#include <string>      // Supports use of "string" data type
using namespace std;

int main() {
    int     userInt;
    double  userDouble;
    char    userChar;
    string  userString;

    cout << "Enter integer:" << endl;
    cin  >> userInt;
    cout << "Enter double:" << endl;
    cin  >> userDouble;
    cout << "Enter character:" << endl;
    cin  >> userChar;
    cout << "Enter string:" << endl;
    cin  >> userString;

    cout << userInt << " " << userDouble << " " << userChar << " " << userString << "\n";
    cout << userString << " " << userChar << " " << userDouble << " " << userInt << "\n";

    int userDtoI = (int)userDouble;

    cout << userDouble << " cast to an integer is " << userDtoI << "\n";

    return 0;
}