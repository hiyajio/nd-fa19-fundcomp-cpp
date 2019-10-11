/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: mysayings.cpp
 * Description: Calculator asking user input for operation and numbers to be used in operation
 */
#include <iostream>                             // Library Declarations
using namespace std;
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <fstream>

void show_all_sayings(vector<string> &quotes);                          // Function Declarations
void enter_new_saying(string new_saying, vector<string> &quotes);
void list_sayings_word(string match_word, vector<string> &quotes);
void save_new_sayings(vector<string> &quotes, string new_file_name);
void delete_last_saying(vector<string> &quotes);
void list_random_saying(vector<string> &quotes);

int main() {
    int select = 0;         // Variable Declarations
    string file;
    string str;
    string new_saying;
    string match_word;
    string new_file_name;
    vector<string> quotes;

    cout << "\n\n======= Welcome to the sayings manager! =======\n\n";
    cout << "Enter name of startup file: ";
    cin >> file;        // Ask user for file name to be loaded
    cout << "\n\n";

    ifstream my_file(file);
    if (my_file.good()) {       // Checks if file exists, if not, display error message & terminate program
        while (getline(my_file, str)) {     // Turns file into vector<string>
            if (str.size() > 0) {
                quotes.push_back(str);
            }
        }

        while (select != 7) {      // Checks if input is not 7 (int for quit) to loop
            select = 0;
            cout << "Tasks you can perform:\n";
            cout << " 1: Show all sayings\n";
            cout << " 2: Enter a new saying\n";
            cout << " 3: List sayings that contain a given word\n";
            cout << " 4: Save all sayings in a new text file\n";
            cout << " 5: List a random saying\n";
            cout << " 6: Delete last saying in list\n";
            cout << " 7: Quit\n";
            while ((select <= 0) || (select > 7)) { // Checks if input appropriate
                cout << "\nEnter your choice: ";
                cin >> select;          // Ask user for input
                if ((select <= 0) || (select > 7)) {    // If input not correct, display error message
                    cout << "Please input numbers 1 - 7 (inclusive) only!\n\n";
                }
            }

            cout << "\n";

            switch (select) {
                case 1: // Call show_all_sayings Function
                    show_all_sayings(quotes);
                    break;
                case 2: // Call enter_new_saying Function
                    cin.ignore();       // Fixing getline
                    cout << "Enter a new saying: ";
                    getline (cin, new_saying);
                    enter_new_saying(new_saying, quotes);
                    break;
                case 3: // Call list_sayings_word Function
                    cout << "Enter the search word: ";
                    cin >> match_word;
                    list_sayings_word(match_word, quotes);
                    break;
                case 4: // Call save_new_sayings Function
                    cout << "Enter the name of the file where all sayings will be saved: ";
                    cin >> new_file_name;
                    save_new_sayings(quotes, new_file_name);
                    break;
                case 5: // Call list_random_saying Function
                    list_random_saying(quotes);
                    break;
                case 6: // Call delete_last_saying Function
                    delete_last_saying(quotes);
                    break;
                case 7: // Terminate program
                    cout << "That's all folks! [Looney Tunes]\n\n\n";
                    return 0;       // Exit
            }
        }
    } else {
        cout << "Error in opening file: \"" << file << "\"!\n\n\n";
            // Error message & formatting
    }
    return 0;
}

void show_all_sayings(vector<string> &quotes) {
    for (auto i = quotes.begin(); i < quotes.end(); i++) {  // Display all quotes using iterators
        cout << " -> " <<  *i << "\n";
    }
    cout << "\n";     // Formatting
}

void enter_new_saying(string new_saying, vector<string> &quotes) {
    quotes.push_back(new_saying);   // Add new saying to vector
    cout << "Quote successfully added!\n\n";     // Success message
}

void list_sayings_word(string match_word, vector<string> &quotes) {
    int counter = 0;
    for (auto i = quotes.begin(); i < quotes.end(); i++) {  // Run through whole vector
        if ((*i).find(match_word) != string::npos) {        // Check to see if match
            cout << " -> " << *i << "\n";     // If match, display whole quote
            counter++;
        }
    }
    if (counter == 0) {
        cout << "Sorry, no quotes in current database have that word!\n";
    }
    cout << "\n";       // Formatting
}

void save_new_sayings(vector<string> &quotes, string new_file_name) {
    ofstream new_file (new_file_name);         // Create new file under file name given

    for (auto i = quotes.begin(); i < quotes.end(); i++) {  // Run through whole vector
        new_file << *i;     // Save whole line
        new_file << "\n";   // Separate each line from each other
    }

    new_file.close();

    cout << "File successfully saved under name: \"" << new_file_name << "\"!\n\n";
        // Success message & formatting
}

void list_random_saying(vector<string> &quotes) {
    int r = rand() % quotes.size();     // Create random number w upper bound vector size

    cout << quotes.at(r) << "\n";       // Display quote based on random number as ref
    cout << "\n";     // Formatting
}

void delete_last_saying(vector<string> &quotes) {
    quotes.pop_back();      // Delete last quote in vector
    cout << "Last quote successfully deleted!\n\n";     // Success message
}