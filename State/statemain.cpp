/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: statemain.cpp
 * Description: Main program to test State class for Part 3 of lab (State)
 */
#include <iostream>                             // Library Declarations
using namespace std;
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <fstream>

#include "state.h"  // Include state.h file for access

int main() {
    int select = 0;         // Variable Declarations
    string file;
    string str;
    string abbr;
    string name;
    string cptl;
    int year;
    int pop;
    int rep;
    string new_file_name;
    vector<string> state(300);
    char c;

    cout << "\n\n======= Welcome to the states information center! =======\n\n";
    cout << "Enter name of startup file: ";
    cin >> file;        // Ask user for file name to be loaded
    cout << "\n\n";

    ifstream my_file(file);
    if (my_file.good()) {       // Checks if file exists, if not, display error message & terminate program

        int i = 0;
        while (my_file.get(c)) {     // Gets individual char from file one-by-one
            if (isalnum(c)) {
                state[i] += c;
            } else if (c == ',') {
                i++;
            } else if (c == '\n') {
                i++;
            } else if (c == ' ') {
                state[i] += ' ';
            }
        }

        State us(state);

        while (select != 11) {      // Checks if input is not 11 (int for quit) to loop
            select = 0;
            cout << "Tasks you can perform:\n";
            cout << "  1: Show info on all states\n";
            cout << "  2: Display info given state abbreviation\n";
            cout << "  3: Display info given state name\n";
            cout << "  4: Display info given state capital\n";
            cout << "  5: Display states given minimum population\n";
            cout << "  6: Display states given maximum population\n";
            cout << "  7: Display states given minimum year\n";
            cout << "  8: Display states given maximum year\n";
            cout << "  9: Display states given minimum representatives in state\n";
            cout << " 10: Display states given maximum representatives in state\n";
            cout << " 11: Quit\n";
            while ((select <= 0) || (select > 11)) { // Checks if input appropriate
                cout << "\nEnter your choice: ";
                cin >> select;          // Ask user for input
                if ((select <= 0) || (select > 11)) {    // If input not correct, display error message
                    cout << "Please input numbers 1 - 11 (inclusive) only!\n\n";
                }
            }

            cout << "\n";

            switch (select) {
                case 1: // Call showInfoAll Function
                    us.showInfoAll();
                    break;
                case 2: // Call showInfoAbbr Function
                    cout << "Enter abbreviation of state: ";
                    cin >> abbr;
                    cout << "\n";
                    us.showInfoAbbr(abbr);
                    break;
                case 3: // Call showInfoName Function
                    cout << "Enter name of state: ";
                    cin.ignore();
                    getline (cin, name);
                    cout << "\n";
                    us.showInfoName(name);
                    break;
                case 4: // Call showInfoCptl Function
                    cout << "Enter capital of state: ";
                    cin.ignore();
                    getline (cin, cptl);
                    cout << "\n";
                    us.showInfoCptl(cptl);
                    break;
                case 5: // Call showStatePopMin Function
                    cout << "Enter minimum population of state (max is 39,145,000): ";
                    cin >> pop;
                    while ((pop < 0) || (pop > 39145000)) {     // Check if population given is valid
                        if (pop < 0) {
                            cout << "\nInvalid population given. You cannot have population less than 0.\n";
                        } else {
                            cout << "\nInvalid population given. Maximum number of population for one state is 39,145,000.\n";
                        }   // Prompt user again since input is invalid
                        cout << "Enter minimum population of state (max is 39,145,000): ";
                        cin >> pop;
                    }
                    cout << "\n";
                    us.showStatePopMin(pop);
                    break;
                case 6: // Call showStatePopMax Function
                    cout << "Enter maximum population of state (max is 39,145,000): ";
                    cin >> pop;
                    while ((pop < 0) || (pop > 39145000)) {     // Check if population given is valid
                        if (pop < 0) {
                            cout << "\nInvalid population given. You cannot have population less than 0.\n";
                        } else {
                            cout << "\nInvalid population given. Maximum number of population for one state is 39,145,000.\n";
                        }   // Prompt user again since input is invalid
                        cout << "Enter maximum population of state (max is 39,145,000): ";
                        cin >> pop;
                    }
                    cout << "\n";
                    us.showStatePopMax(pop);
                    break;
                case 7: // Call showStateYearMin Function
                    cout << "Enter minimum year joined Union (1787 - 1959): ";
                    cin >> year;
                    while ((year < 1787) || (year > 1959)) {    // Check if year given is valid
                        cout << "\nInvalid year given. States joined Union from 1787 to 1959 only.\n";
                        cout << "Enter minimum year joined Union (1787 - 1959): ";  // Prompt user again since input is invalid
                        cin >> year;
                    }
                    cout << "\n";
                    us.showStateYearMin(year);
                    break;
                case 8: // Call showStateYearMax Function
                    cout << "Enter maximum year joined Union (1787 - 1959): ";
                    cin >> year;
                    while ((year < 1787) || (year > 1959)) {    // Check if year given is valid
                        cout << "\nInvalid year given. States joined Union from 1787 to 1959 only.\n";
                        cout << "Enter maximum year joined Union (1787 - 1959): ";  // Prompt user again since input is invalid
                        cin >> year;
                    }
                    cout << "\n";
                    us.showStateYearMax(year);
                    break;
                case 9: // Call showStateRepMin Function
                    cout << "Enter minimum number of representatives in Congress (1 - 53): ";
                    cin >> rep;
                    while ((rep < 1) || (rep > 53)) {   // Check if number of reps given is valid
                        cout << "\nInvalid number of reps given. States have at least 1 and at most 53 representatives in Congress.\n";
                        cout << "Enter minimum number of representatives in Congress (1 - 53): ";   // Prompt user again since input is invalid
                        cin >> rep;
                    }
                    cout << "\n";
                    us.showStateRepMin(rep);
                    break;
                case 10: // Call showStateRepMax Function
                    cout << "Enter maximum number of representatives in Congress (1 - 53): ";
                    cin >> rep;
                    while ((rep < 1) || (rep > 53)) {   // Check if number of reps given is valid
                        cout << "\nInvalid number of reps given. States have at least 1 and at most 53 representatives in Congress.\n";
                        cout << "Enter maximum number of representatives in Congress (1 - 53): ";   // Prompt user again since input is invalid
                        cin >> rep;
                    }
                    cout << "\n";
                    us.showStateRepMax(rep);
                    break;
                case 11: // Terminate program
                    cout << "That's all folks!\n\n\n";
                    return 0;       // Exit
            }
        }
    } else {
        cout << "Error in opening file: \"" << file << "\"!\n\n\n"; // Error message & formatting
    }
    return 0;
}