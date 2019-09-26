/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: gcdmain.cpp
 * Description: Gets greatest common divisor between two integers through functions
 */
#include <iostream>
using namespace std;

int getgcd(int, int);   // Initialize functions needed
void display(int);

int main() {
        int num1;       // Initialize variables needed
        int num2;
        int gcd;

        cout << "\n\n======= Greatest Common Divisor Calculator =======\n";
        cout << "\nEnter first number: ";       // Prompts user for first number
        cin >> num1;                            // Stores first number
        cout << "Enter second number: ";        // Prompts user for second number
        cin >> num2;                            // Stores second number

        gcd = getgcd(num1, num2);       // Calls getgcd function to compute and return gcd

        display(gcd);                   // Calls display function

        return 0;
}

int getgcd(int num1, int num2) {
        while (num1 != num2) {          // Non-recursive algorithm to obtain GCD
                if (num1 > num2) {
                        num1 = num1 - num2;
                } else {
                        num2 = num2 - num1;
                }

        }

        return num1;    // Return GCD
}

void display(int gcd) {         // Can be stated as unnecessary function, just wanted more practice
        cout << "\nGreatest common divisor (GCD) is: " << gcd << "\n\n\n";      // Diplay GCD
}