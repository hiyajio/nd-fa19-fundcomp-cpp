/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: mortgage.cpp
 * Description: Displays amortization table based on principal, interest rate, and desired monthly payment inputted by user.  
 */
#include <iostream>
using namespace std;
#include <iomanip>

int main() {
        float ppal;               // Principal
        float intR;               // Interest Rate
        float inter;              // Monthy Interest
        float monP;               // Desired Monthly Payment
        float bal;                // Balance
        float mult = 1.0 / 12.0;  // Multiplier for Monthly Interest
        int month = 0;            // Counter for Months Needed
        float total = 0.0;        // Total Payment Storage

        cout << "\n\n===== Mortgage Calculator =====\n\n";
        cout << "What is your principal?\n";
        cin >> ppal;       // Ask for Principal
        while (ppal < 0) {      // Check if number negative -> If it is ask for input again
                cout << "Please input valid principal (non-negative).\n";
                cin >> ppal;
        }

        cout << "What is your interest rate? (percentage)\n";
        cin >> intR;       // Ask for Interest Rate
        while (intR < 0) {      // Check if number negative -> If it is ask for input again
                cout << "Please input valid interest rate (non-negative).\n";
                cin >> intR;
        }
        intR = intR / 100.0;    // Divide by 100 for it to be used properly in formula

        cout << "What is your desired monthly payment?\n";
        cin >> monP;       // Ask for Monthly Payment
        while (monP < 0) {      // Check if number negative -> If it is ask for input again
                cout << "Please input valid desired monthly payment (non-negative).\n";
                cin >> monP;
        }
        cout << "\n";   // Formatting

        cout << fixed;  // Formatting
        cout << setprecision(2);        // Print 2 Decimal Places only

        cout << left << setw(6) << "Month" << right << setw(12) << "Payment" << right << setw(15) << "Interest" << right << setw(15) << "Balance\n";    // Header for Table

        bal = ppal;     // Transfer to Balance for Computation

        while (bal > monP) {
                inter = intR * bal * mult;      // Compute for Interest
                bal = bal - monP + inter;       // Compute for New Balance
                if (bal > ppal) {       // Check if new balance is bigger than principal -> If it is, monthly payment too low, terminate program.
                        cout << "\n\nMonthly payment too low. Balance will increase every month.\n";
                        cout << "Change monthly payment and try again. Program is terminated.\n\n\n";
                        return 0;
                }

                total = total + monP;   // Tally Payment
                month++;                // Increase Month Counter

                cout << left << setw(5) << month << right << setw(7) << '$' << right << setw(7) << monP << right << setw(7) << '$' << right << setw(7) << inter << right << setw(7) << '$' << right << setw(9) << bal << "\n";          // Display New Row
        }
        if (monP > bal) {       // Check if monthly payment bigger than balance (Catch last row) -> Do different calculations for last row
                monP =  bal;
                inter = intR * bal * mult;

                total = total + monP;
                bal = 0;
                month++;

                cout << left << setw(5) << month << right << setw(7) << '$' << right << setw(7) << monP << right << setw(7) << '$' << right << setw(7) << inter << right << setw(7) << '$' << right << setw(9) << bal << "\n";          // Display Last Row
        }

        int year = month / 12;  // Get number of years from number of months
        month = month % 12;     // Get remaining number of months

        cout << "\n\n";         // Formatting
        cout << "You paid a total of $" << total << " over " << year << " years and " << month << " months.";           // Display Number of Years and Months

        cout << "\n\n\n";       // Formatting

        return 0;
}