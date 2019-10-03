/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: ndfootball.cpp
 * Description: Calculator asking user input for operation and numbers to be used in operation
 */
#include <iostream>                             // Library Declarations
#include "nd_data.h"
using namespace std;
#include <iomanip>
#include <string.h>
#include <stdio.h>

void record_given_year(int wins[], unsigned int m, int losses[], unsigned int n, int year);      // Function Declarations
void years_least_wins(int wins[], unsigned int m, int win);
void years_least_losses(int losses[], unsigned int n, int loss);
void years_exact_wins(int wins[], unsigned int m, int win);
void years_exact_losses(int losses[], unsigned int n, int loss);
void records_year_from(int wins[], unsigned int m, int losses[], unsigned int n, int year);
void records_year_to(int wins[], unsigned int m, int losses[], unsigned int n, int year);
void winning_records(int wins[], unsigned int m, int losses[], unsigned int n);
void losing_records(int wins[], unsigned int m, int losses[], unsigned int n);

int main() {
    int select = 0;
    int year, win, loss;
    unsigned int m = sizeof(wins)/sizeof(wins[0]);
    unsigned int n = sizeof(losses)/sizeof(losses[0]);

    while (select != 10) {   // Checks if input is not 10 to loop
        select = 0;
        cout << "\n\n======= Notre Dame Football Record Checker =======\n\n";
        cout << "What would you like to do? (enter number from selection)\n";
        cout << "  1: Display a Record Given a Year:\n";
        cout << "  2: Display Years with at Least \"n\" Win/s\n";
        cout << "  3: Display Years with at Least \"n\" Loss/es\n";
        cout << "  4: Display Years with Exactly \"n\" Win/s\n";
        cout << "  5: Display Years with Exactly \"n\" Loss/es\n";
        cout << "  6: Display All Records Starting from Year \"n\"\n";
        cout << "  7: Display All Records Ending on Year \"n\"\n";
        cout << "  8: Display All Winning Records\n";
        cout << "  9: Display All Losing Records\n";
        cout << " 10: Exit program\n\n";
        while ((select <= 0) || (select > 10)) { // Checks if input appropriate
            cout << "Enter your choice: ";
            cin >> select;          // Ask user for input
            if ((select <= 0) || (select > 10)) {    // If input not correct, display error message
                cout << "Please input numbers 1 - 10 (inclusive) only\n\n";
            }
        }

    switch (select) {
        case 1: // Call record_given_year Function
            cout << "Enter the year: ";
            cin >> year;
            while ((year < 1900) || (year > 2018)) {
                cout << "\nInvalid year given. We only have records of 1900 - 2018.\n";
                cout << "Enter the year: ";
                cin >> year;
            }       // Check if year input is valid
                record_given_year(wins, m, losses, n, year);
                break;
        case 2: // Call years_least_wins Function
            cout << "Enter minimum number of win/s: ";
            cin >> win;
            while (win > 12) {
                cout << "\nInvalid number of win/s given. Records show only 12 at most per year.\n";
                cout << "Enter minimum number of win/s: ";
                cin >> win;
            }       // Check if win input is valid
            years_least_wins(wins, m, win);
            break;
        case 3: // Call years_least_losses Function
            cout << "Enter minimum number of loss/es: ";
            cin >> loss;
            while (loss > 9) {
                cout << "\nInvalid number of loss/es given. Records show only 9 at most per year.\n";
                cout << "Enter minimum number of loss/es: ";
                cin >> loss;
            }       // Check if loss input is valid
            years_least_losses(losses, n, loss);
            break;
        case 4: // Call years_exact_wins Function
            cout << "Enter exact number of win/s: ";
            cin >> win;
            while ((win < 2) || (win > 12)) {
                cout << "\nInvalid number of win/s given. Records show at least 2 and at most 12 per year.\n";
                cout << "Enter exact number of win/s: ";
                cin >> win;
            }
            years_exact_wins(wins, m, win);
            break;
        case 5: // Call years_exact_losses Function
            cout << "Enter exact number of loss/es: ";
            cin >> loss;
            while ((loss < 0) || (loss > 9)) {
                cout << "\nInvalid number of loss/es given. Records show at least 0 and at most 9 per year.\n";
                cout << "Enter exact number of loss/es: ";
                cin >> loss;
            }
            years_exact_losses(losses, n, loss);
            break;
        case 6: // Call records_year_from Function
            cout << "Enter starting year: ";
            cin >> year;
            while ((year < 1900) || (year > 2018)) {
                cout << "\nInvalid year given. We only have records of 1900 - 2018.\n";
                cout << "Enter the year: ";
                cin >> year;
            }
            records_year_from(wins, m, losses, n, year);
            break;
        case 7: // Call records_year_to Function
            cout << "Enter ending year: ";
            cin >> year;
            while ((year < 1900) || (year > 2018)) {
                cout << "\nInvalid year given. We only have records of 1900 - 2018.\n";
                cout << "Enter the year: ";
                cin >> year;
            }
            records_year_to(wins, m, losses, n, year);
            break;
        case 8: // Call winning_records Function
            winning_records(wins, m, losses, n);
            break;
        case 9: // Call losing_records Function
            losing_records(wins, m, losses, n);
            break;
        case 10: // Terminate program
            cout << "\nThat's all folks! Go Irish!\n\n\n";
            return 0;       // Exit
        }
    }
    return 0;
}

void record_given_year(int wins[], unsigned int m, int losses[], unsigned int n, int year) {
    int index;              // Initialize variables needed
    index = year - 1900;

    cout << "\nYear " << right << setw(5) << year << " - Win/s: " << right << setw(2) << wins[index] << ", Loss/es: " << right << setw(2) << losses[index] << "\n\n\n";
    // Display year, wins and losses based on array index
}

void years_least_wins(int *wins, unsigned int m, int win) {
    cout << "\nYear/s with at least " << win << " win/s: \n";       // Header

    int counter = 0;        // Initialize variables needed
    int total = 0;
    for (int i = 0; i < m; ++i) {
        if (wins[i] >= win) {   // If wins is greater than or equal to input, display
            cout << 1900 + i << " ";
            counter++;      // Counter for formatting
            total++;        // Counter for total
        }
        if (counter == 10) {    // Reset to 0 for next row formatting
            cout << "\n";
            counter = 0;
        }
    }

    cout << "\nNumber of Year/s: " << total << "\n";        // Display total

    cout << "\n\n\n";       // Formatting
}

void years_least_losses(int *losses, unsigned int n, int loss) {
    cout << "\nYear/s with at least " << loss << " loss/es: \n";    // Header

    int counter = 0;        // Initialize variables needed
    int total = 0;
    for (int i = 0; i < n; ++i) {
        if (losses[i] >= loss) {        // If losses is greater than or equal to input, display
            cout << 1900 + i << " ";
            counter++;      // Counter for formatting
            total++;        // Counter for total
        }
        if (counter == 10) {    // Reset to 0 for next row formatting
            cout << "\n";
            counter = 0;
        }
    }

    cout << "\nNumber of Year/s: " << total << "\n";        // Display total

    cout << "\n\n\n";       // Formatting
}

void years_exact_wins(int *wins, unsigned int m, int win) {
    cout << "\nYear/s with exactly " << win << " win/s: \n";        // Header

    int counter = 0;        // Initialize variables needed
    int total = 0;
    for (int i = 0; i < m; ++i) {
        if (wins[i] == win) {   // If wins is equal to input, display
            cout << 1900 + i << " ";
            counter++;      // Counter for formatting
            total++;        // Counter for total
        }
        if (counter == 10) {    // Reset to 0 for next row formatting
            cout << "\n";
            counter = 0;
        }
    }

    cout << "\nNumber of Year/s: " << total << "\n";        // Display total

    cout << "\n\n\n";       // Formatting
}

void years_exact_losses(int *losses, unsigned int n, int loss) {
    cout << "\nYear/s with exactly " << loss << " loss/es: \n";     // Header

    int counter = 0;        // Initialize variables needed
    int total = 0;
    for (int i = 0; i < n; ++i) {
        if (losses[i] == loss) {        // If losses is equal to input, display
            cout << 1900 + i << " ";
            counter++;      // Counter for formatting
            total++;        // Counter for total
        }
        if (counter == 10) {    // Reset to 0 for next row formatting
            cout << "\n";
            counter = 0;
        }
    }

    cout << "\nNumber of Year/s: " << total << "\n";        // Display total

    cout << "\n\n\n";       // Formatting
}

void records_year_from(int *wins, unsigned int m, int *losses, unsigned int n, int year) {
    int index = year - 1900;        // Initialize variables needed
    int max = 2018 - 1900;
    int i = 0;

    cout << "\n";           // Formatting

    for (index; index <= max; ++index) {
        cout << "Year " << right << setw(5) << year + i << " - Win/s: " << right << setw(2) << wins[index] << ", Loss/es: " << right << setw(2) << losses[index] << "\n";
        // Display year, wins, and losses based on restricted index
        i++;    // Counter different for displaying year
    }

    cout << "\n\n\n";       // Formatting
}

void records_year_to(int *wins, unsigned int m, int *losses, unsigned int n, int year) {
    int index = year - 1900;        // Initialize variables needed
    int i = 0;

    cout << "\n";           // Formatting

    for (i; i <= index; ++i) {
        cout << "Year " << right << setw(5) << 1900 + i << " - Win/s: " << right << setw(2) << wins[i] << ", Loss/es: " << right << setw(2) << losses[i] << "\n";
        // Display year, wins, and losses based on restricted index
    }

    cout << "\n\n\n";       // Formatting
}

void winning_records(int *wins, unsigned int m, int *losses, unsigned int n) {
    int counter = 0;        // Initialize variables needed

    cout << "\n\nWinning Records\n\n";      // Header
    for (int i = 0; i < m; ++i) {
        if (wins[i] > losses[i]) {      // If wins > losses => winning record, display
            cout << "Year " << right << setw(5) << i + 1900 << " - Win/s: " << right << setw(2) << wins[i] << ", Loss/es: " << right << setw(2) << losses[i] << "\n";
            counter++;      // Counter for total
        }
    }

    cout << "\nNumber of Years with Winning Records: " << counter << "\n\n\n";
            // Display total
}

void losing_records(int *wins, unsigned int m, int *losses, unsigned int n) {
    int counter = 0;        // Initialize variables needed

    cout << "\n\nLosing Records\n\n";       // Header
    for (int i = 0; i < n; ++i) {
        if (wins[i] < losses[i]) {      // If wins < losses => losing record, display
            cout << "Year " << right << setw(5) << i + 1900 << " - Win/s: " << right << setw(2) << wins[i] << ", Loss/es: " << right << setw(2) << losses[i] << "\n";
            counter++;      // Counter for total
        }
    }

    cout << "\nNumber of Years with Losing Records: " << counter << "\n\n\n";
            // Display total
}