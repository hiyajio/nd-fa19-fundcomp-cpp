/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: crossword.cpp
 * Description: Main program to test Crossboard class
 */
#include <iostream>		// Initialize needed libraries
using namespace std;
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <string>

#include "crossboard.h"

void import(string filename, Crossboard&);
void prompt(Crossboard&);

int main(int argc, char *argv[]){
	Crossboard board = Crossboard();	// Initialize needed variables

	cout << "\n\n=============== Crossword Anagram Maker ===============\n";

	switch (argc) {
		case 1:		// 1 Input Mode (Make user input words)
			prompt(board);
			break;
		case 2:		// 2 Input Mode (Take in .txt)
			import(argv[1], board);
			break;
		case 3:		// 3 Input Mode (Take in .txt and save in other .txt)
			import(argv[1], board);
			board.display(argv[2]);
			break;
		default:	// Catch <1 && <3 error
			cout << "Wrong number of arguments given. Try again!\n\n";
			return 1;
	}
	board.display();

	return 0;
}

void import(string filename, Crossboard& board){
	ifstream file(filename);	// Initialize needed variables
	string word;
	vector<string> words;

	if(file.is_open()) {		// Check if file is good, if it is push in vector
		while(file >> word) {
			words.push_back(word);
		}
	} else {
		cout << "Invalid file name given. Try again!\n\n";	// Error message for invalid file
		return;
	}
	words.pop_back();	// Take off '.' from vector

	if(words.size() > 0) {		// Initialize vector of words received
		board.init(words);
	}
}

void prompt(Crossboard& board){
	string word = "";		// Initialize needed variables
	vector<string> words;
	int counter = 0;

	cout << "\nEnter words for the crossword (once done, type '.' and press enter/return):\n";

	while(word != "." && counter < 20) {	// Push in vector if not period and not 21st word
		cin >> word;
		words.push_back(word);
		counter++;
	}
	words.pop_back();	// Take off '.' from vector

	if(counter == 20) {		// Error message for reaching maximum
		cout << "Maximum number of words reached (maximum of 20 only)\n\n";
	}

	if(words.size() > 0) {		// Initialize vector of words received
		board.init(words);
	}
}