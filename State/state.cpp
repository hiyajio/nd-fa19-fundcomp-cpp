/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: state.cpp
 * Description: Implementation of State class in state.h for Part 3 of lab (State)
 */
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
using namespace std;

#include "state.h"  // Include state.h file for access

State::State(vector<string> &defStates) {
    states = defStates;
}

State::~State() {

}

void State::showInfoAll() const{
    int counter = 0;
    cout << "===============" << "\n";
    for (auto i = states.begin(); i < states.end(); i++) {
        switch (counter) {  // Formatting for displaying all info for all states
            case 0:
                cout << *i;
                counter++;
                break;
            case 1:
                cout << ": " << *i << "\n";
                counter++;
                break;
            case 2:
                cout << "Capital: " << *i << "\n";
                counter++;
                break;
            case 3:
                cout << "Population: " << *i << "\n";
                counter++;
                break;
            case 4:
                cout << "Year joined Union: " << *i << "\n";
                counter++;
                break;
            case 5:
                cout << "Reps in Congress: " << *i << "\n";
                cout << "===============" << "\n";
                counter = 0;
                break;
        }
    }
    cout << "\n";
}

void State::showInfoAbbr(string userAbbr) const{
    transform(userAbbr.begin(), userAbbr.end(), userAbbr.begin(), ::toupper);   // Format user input to fit vector input of abbreviation of state
    int counter = 0;
    for (auto i = states.begin(); i < states.end(); i=i+6) {  // Run through whole vector
        if ((*i).find(userAbbr) != string::npos) {        // Check to see if match
            cout << *i << ": " << *(i+1) << "\n";
            cout << "Capital: " << *(i+2) << "\n";
            cout << "Population: " << *(i+3) << "\n";
            cout << "Year joined Union: " << *(i+4) << "\n";
            cout << "Reps in Congress: " << *(i+5) << "\n";
            cout << "===============" << "\n";
            counter++;
        }
    }
    if (counter == 0) {
        cout << "Sorry, no state abbreviation like that!\n";    // Display error message if no match
    }
    cout << "\n";
}

void State::showInfoName(string userName) const{
    transform(userName.begin(), userName.end(), userName.begin(), ::tolower);   // Format user input to fit vector input of name of state
    userName[0] = toupper(userName[0]);
    for (auto i = 0; i < userName.size(); i++) {
        if (userName[i] == ' ') {
            userName[i+1] = toupper(userName[i+1]);
        }
    }
    int counter = 0;
    for (auto i = states.begin()+1; i < states.end(); i=i+6) {  // Run through whole vector
        if ((*i).find(userName) != string::npos) {        // Check to see if match
            cout << *(i-1) << ": " << *(i) << "\n";
            cout << "Capital: " << *(i+1) << "\n";
            cout << "Population: " << *(i+2) << "\n";
            cout << "Year joined Union: " << *(i+3) << "\n";
            cout << "Reps in Congress: " << *(i+4) << "\n";
            cout << "===============" << "\n";
            counter++;
        }
    }
    if (counter == 0) {
        cout << "Sorry, no capital like that!\n";   // Display error message if no match
    }
    cout << "\n";
}

void State::showInfoCptl(string userCptl) const{
    transform(userCptl.begin(), userCptl.end(), userCptl.begin(), ::tolower);   // Format user input to fit vector input of capital of state
    userCptl[0] = toupper(userCptl[0]);
    for (auto i = 0; i < userCptl.size(); i++) {
        if (userCptl[i] == ' ') {
            userCptl[i+1] = toupper(userCptl[i+1]);
        }
    }
    int counter = 0;
    for (auto i = states.begin()+2; i < states.end(); i=i+6) {  // Run through whole vector
        if ((*i).find(userCptl) != string::npos) {        // Check to see if match
            cout << *(i-2) << ": " << *(i-1) << "\n";
            cout << "Capital: " << *(i) << "\n";
            cout << "Population: " << *(i+1) << "\n";
            cout << "Year joined Union: " << *(i+2) << "\n";
            cout << "Reps in Congress: " << *(i+3) << "\n";
            cout << "===============" << "\n";
            counter++;
        }
    }
    if (counter == 0) {
        cout << "Sorry, no capital like that!\n";   // Display error message if no match
    }
    cout << "\n";
}

void State::showStatePopMin(int userPop) const{
    for (auto i = states.begin()+3; i < states.end(); i=i+6) {  // Run through whole vector
        if (userPop <= stoi(*i)) {        // Check to see if population in vector is greater than input
            cout << *(i-3) << ": " << *(i-2) << "\n";
            cout << "Capital: " << *(i-1) << "\n";
            cout << "Population: " << *(i) << "\n";
            cout << "Year joined Union: " << *(i+1) << "\n";
            cout << "Reps in Congress: " << *(i+2) << "\n";
            cout << "===============" << "\n";
        }
    }
    cout << "\n";
}

void State::showStatePopMax(int userPop) const{
    int counter = 0;
    for (auto i = states.begin()+3; i < states.end(); i=i+6) {  // Run through whole vector
        if (userPop >= stoi(*i)) {        // Check to see if population in vector is less than input
            cout << *(i-3) << ": " << *(i-2) << "\n";
            cout << "Capital: " << *(i-1) << "\n";
            cout << "Population: " << *(i) << "\n";
            cout << "Year joined Union: " << *(i+1) << "\n";
            cout << "Reps in Congress: " << *(i+2) << "\n";
            cout << "===============" << "\n";
            counter++;
        }
    }
    if (counter == 0) {
        cout << "Sorry, no states with that maximum population!\n";
    }
    cout << "\n";
}

void State::showStateYearMin(int userYear) const{
    for (auto i = states.begin()+4; i < states.end(); i=i+6) {  // Run through whole vector
        if (userYear <= stoi(*i)) {        // Check to see if year in vector is greater than input
            cout << *(i-4) << ": " << *(i-3) << "\n";
            cout << "Capital: " << *(i-2) << "\n";
            cout << "Population: " << *(i-1) << "\n";
            cout << "Year joined Union: " << *(i) << "\n";
            cout << "Reps in Congress: " << *(i+1) << "\n";
            cout << "===============" << "\n";
        }
    }
    cout << "\n";
}

void State::showStateYearMax(int userYear) const{
    for (auto i = states.begin()+4; i < states.end(); i=i+6) {  // Run through whole vector
        if (userYear >= stoi(*i)) {        // Check to see if year in vector is less than input
            cout << *(i-4) << ": " << *(i-3) << "\n";
            cout << "Capital: " << *(i-2) << "\n";
            cout << "Population: " << *(i-1) << "\n";
            cout << "Year joined Union: " << *(i) << "\n";
            cout << "Reps in Congress: " << *(i+1) << "\n";
            cout << "===============" << "\n";
        }
    }
    cout << "\n";
}

void State::showStateRepMin(int userRep) const{
    for (auto i = states.begin()+5; i < states.end(); i=i+6) {  // Run through whole vector
        if (userRep <= stoi(*i)) {        // Check to see if reps in vector is greater than input
            cout << *(i-5) << ": " << *(i-4) << "\n";
            cout << "Capital: " << *(i-3) << "\n";
            cout << "Population: " << *(i-2) << "\n";
            cout << "Year joined Union: " << *(i-1) << "\n";
            cout << "Reps in Congress: " << *(i) << "\n";
            cout << "===============" << "\n";
        }
    }
    cout << "\n";
}

void State::showStateRepMax(int userRep) const{
    for (auto i = states.begin()+5; i < states.end(); i=i+6) {  // Run through whole vector
        if (userRep >= stoi(*i)) {        // Check to see if reps in vector is less than input
            cout << *(i-5) << ": " << *(i-4) << "\n";
            cout << "Capital: " << *(i-3) << "\n";
            cout << "Population: " << *(i-2) << "\n";
            cout << "Year joined Union: " << *(i-1) << "\n";
            cout << "Reps in Congress: " << *(i) << "\n";
            cout << "===============" << "\n";
        }
    }
    cout << "\n";
}