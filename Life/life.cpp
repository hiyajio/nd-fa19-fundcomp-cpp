/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: life.cpp
 * Description: Main program to test Life class
 */
#include <iostream>     // Initialize needed libraries
using namespace std;
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "lifeboard.h"

int main(int argc, char* argv[]) {
    char select = 'd';  // Initialize needed variables
    int x, y;
    unsigned int delay = 10000;
    Lifeboard init;
    string file;
    vector<char> commands;
    int coords[1000000];
    char c;

    switch (argc) {
        case 1:     // Interactive mode
            cout << "\n\n============= GAME OF LIFE =============\n";
            cout << "========= Initial empty board: =========\n\n";
            init.show();
            while (select != 'q') {   // Checks if input is not 'q' to loop
                select = 'd';
                cout << "What would you like to do? (enter character from selection)\n";
                cout << " a : ask for coordinates where to add a new live cell (no action needed if cell is already alive)\n";
                cout << " r : ask for coordinates where a cell should be removed (no action needed if cell is already dead)\n";
                cout << " n : advance the simulation to the next iteration by applying the rules of the game\n";
                cout << " q : quit the program\n";
                cout << " p : play the game continuously (forever, without asking for more input; you can press control-C to stop the program)\n";
                while (select == 'd') { // Checks if input appropriate
                    cout << "Enter your choice: ";
                    cin >> select;          // Ask user for input
                    if ((select != 'a') && (select != 'r') && (select != 'n') && (select != 'q') && (select != 'p')) {    // If input not correct, display error message
                        cout << "Please input characters 'a', 'r', 'n', 'q', 'p' only!\n\n";
                    }
                }

            switch (select) {
                case 'a': // Call live() Function
                    cout << "Enter the x-coordinate (0 - 39): ";
                    cin >> x;
                    while ((x < 0) || (x > 40)) {
                        cout << "\nInvalid x given. Board is 40x40 (0 - 39).\n";
                        cout << "Enter the x-coordinate (0 - 39): ";
                        cin >> x;
                    }       // Check if x input is valid
                    cout << "Enter the y-coordinate (0 - 39): ";
                    cin >> y;
                    while ((y < 0) || (y > 40)) {
                        cout << "\nInvalid y given. Board is 40x40 (0 - 39).\n";
                        cout << "Enter the y-coordinate (0 - 39): ";
                        cin >> y;
                    }       // Check if y input is valid
                    init.live(y, x);
                    init.show();
                    break;
                case 'r': // Call kill() Function
                    cout << "Enter the x-coordinate (0 - 39): ";
                    cin >> x;
                    while ((x < 0) || (x > 40)) {
                        cout << "\nInvalid x given. Board is 40x40 (0 - 39).\n";
                        cout << "Enter the x-coordinate (0 - 39): ";
                        cin >> x;
                    }       // Check if x input is valid
                    cout << "Enter the y-coordinate (0 - 39): ";
                    cin >> y;
                    while ((y < 0) || (y > 40)) {
                        cout << "\nInvalid y given. Board is 40x40 (0 - 39).\n";
                        cout << "Enter the y-coordinate (0 - 39): ";
                        cin >> y;
                    }       // Check if y input is valid
                    init.kill(y, x);
                    init.show();
                    break;
                case 'n': // Call nextGen() Function
                    init.nextGen();
                    init.show();
                    break;
                case 'q': // Quit program
                    cout << "\nGame of Life has ended! Goodbye!\n\n\n";
                    return 0;       // Exit
                    break;
                case 'p': // Call nextGen() Function endlessly
                    while (true) {
                        cout << "\033[2J\033[H";
                        init.nextGen();
                        init.show();
                        usleep(delay);
                    }
                    break;
                }
            }
            break;
        case 2:    // Batch mode
            ifstream my_file(argv[1]);
            char move;
            x = 100;
            y = 100;
            if (my_file.is_open()) {
                while (my_file) {     // Gets file and checks the command given
                    my_file >> move;
                    if (move == 'a') {
                        my_file >> x >> y;
                        init.live(y, x);
                    } else if (move == 'r') {
                        my_file >> x >> y;
                        init.kill(y, x);
                    } else if (move == 'p') {
                        while (true) {
                            cout << "\033[2J\033[H";
                            init.nextGen();
                            init.show();
                            usleep(delay);
                        }
                    }
                }

            } else {
                cout << "Error in opening file: \"" << file << "\"!\n\n\n"; // Error message & formatting
            }
        break;
    }

    return 0;
}