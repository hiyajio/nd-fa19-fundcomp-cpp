/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: addup.cpp
 * Description: In-lab exercise 9
 */
#include <iostream>
using namespace std;
#include <cstdlib>

int main(int argc, char* argv[])
{
    int num1, num2, sum;

    switch (argc) {
        case 1:
            cout << "Enter two integers: ";
            cin >> num1;
            cin >> num2;
            sum = num1 + num2;
            cout << "The sum is: " << sum << "\n";
            break;
        case 2:
            cout << "Incorrect usage: Too few arguments\n";
            break;
        case 3:
            num1 = atoi(argv[1]);
            num2 = atoi(argv[2]);
            sum = num1 + num2;
            cout << "The sum is: " << sum << "\n";
            break;
        default:
            cout << "Incorrect usage: Too many arguments\n";
    }

    return 0;
}