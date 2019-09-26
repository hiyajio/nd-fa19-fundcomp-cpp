/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: menucalc.cpp
 * Description: Calculator asking user input for operation and numbers to be used in operation
 */
#include <iostream>
using namespace std;
#include <iomanip>
#include <string.h>

double add(double, double);      // Initialize functions needed
double subtract(double, double);
double multiply(double, double);
double divide(double, double);

int main() {
        int select = 0;
        double num1, num2;            // Initialize variables needed
        double result;
        string operate;

        cout << "\n\n======= Menu Calculator =======\n\n";

        while (select != 5) {   // Checks if input is not 5 to loop
                select = 0;
                cout << "What would you like to do? (enter number from selection)\n";
                cout << " 1 for addition\n";
                cout << " 2 for subtraction\n";
                cout << " 3 for multiplication\n";
                cout << " 4 for division\n";
                cout << " 5 to exit program\n\n";
                while ((select <= 0) || (select > 5)) { // Checks if input appropriate
                        cout << "Enter your choice: ";
                        cin >> select;          // Ask user for input
                        if ((select <= 0) || (select > 5)) {    // If input not correct, display error message
                                cout << "Please input numbers 1 - 5 (inclusive) only\n\n";
                        }
                }

                switch (select) {
                        case 1: // Addition
                                cout << "Enter two numbers: ";
                                cin >> num1;
                                cin >> num2;
                                operate = "+";
                                result = add(num1, num2);
                                break;
                        case 2: // Subtraction
                                cout << "Enter two numbers: ";
                                cin >> num1;
                                cin >> num2;
                                operate = "-";
                                result = subtract(num1, num2);
                                break;
                        case 3: // Multiplication
                                cout << "Enter two numbers: ";
                                cin >> num1;
                                cin >> num2;
                                operate = "*";
                                result = multiply(num1, num2);
                                break;
                        case 4: // Division
                                cout << "Enter two numbers: ";
                                cin >> num1;
                                cin >> num2;
                                cout << "\nInputs: " << num1 << ", " << num2 << "\n";   // Display inputs
                                if (num2 == 0) {
                                        cout << "Cannot divide by zero!\n\n";
                                } else {
                                        operate = "/";
                                        result = divide(num1, num2);
                                }
                                break;
                        case 5: // Terminate program
                                cout << "\nThat's all folks!\n\n\n";
                                return 0;       // Exit
                }

                if ((num2 == 0) && (select == 4)) {
                        // Do nothing (Do not output it inputs and equation)
                } else {
                        cout << "\nInputs: " << num1 << ", " << num2 << "\n";   // Display inputs
                        cout << "(" << num1 << ") " << operate << " (" << num2 << ") = " << result << "\n\n\n"; // Display results through equation of what happened
                }
        }

        return 0;
}

double add(double num1, double num2) {
        double sum;
        sum = num1 + num2;    // Add two nums for sum

        return sum;
}

double subtract(double num1, double num2) {
        double diff;
        diff = num1 - num2;    // Subtract two nums for difference

        return diff;
}

double multiply(double num1, double num2) {
        double prod;
        prod = num1 * num2;    // Multiply two nums for product

        return prod;
}

double divide(double num1, double num2) {
        double quot;
        quot = num1 / num2;    // Divide two nums for quotient

        return quot;
}