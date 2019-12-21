/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: crossboard.cpp
 * Description: Implementation of Crossboard class in crossboard.h
 */
#include <iostream>		// Initialize needed libraries
using namespace std;
#include <cstdlib>
#include <unistd.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "crossboard.h"

Crossboard::Crossboard() {		 // Implementation of Crossboard: sets up board w inputted words
	cells = vector<vector<char>>(SPACE, vector<char>(SPACE,ENUL));
	words = {};
}

Crossboard::~Crossboard() {

}

Crossboard::Crossboard(vector<string> words) {	// Implementation of Crossboard w vector from file
	cells = vector<vector<char>>(SPACE, vector<char>(SPACE,ENUL));
	init(words);
}

bool compare(string firWord, string secWord) {	// Implementation of compare: check which word is longer
	if(firWord.size() == secWord.size()){
		return firWord < secWord;
	}

	return firWord.size() < secWord.size();
}

void Crossboard::init(vector<string> words) {	// Implementation of init: arrange words in terms of length and check for errors
	vector<string> validWords;

	for(string word:words) {
		if(validWords.size() >= 20) {	// Error checks
			cout << "Error: Maximum numbers of words reached!\n";
			break;
		}
		if(word.size() < 2) {	// Check if letter instead of word (invalid)
			cout << "Error: Invalid word - '"<< word << "' is just a single letter!\n";
			continue;
		}
		if(word.size() > 15) {	// Check if word too long (invalid)
			cout << "Error: Invalid word - '"<< word << "' is too long!\n";
			continue;
		}
		for(char& letter:word) {	// Check for invalid characters
			if(!isalpha(letter)) {
				cout << "Error: Invalid word - '"<< word << "' contains illegal characters!\n";
				goto escape;
			}
			letter = toupper(letter);	// Formatting
		}
		validWords.push_back(word);
		escape:;
	}

	sort(validWords.begin(), validWords.end(), compare);
	Error err = arrange(validWords);
	cout << err.message << "\n";
}

void Crossboard::showSolution(string filename) {	// Implementation of showSolution: Solution board
	ostream* output;
	ofstream ofs;

	if(filename != "") {
		ofs.open(filename);
		output = &ofs;
	} else {
		output = &cout;
	}

	(*output) << "Solution: " << "\n";	// Formatting
	for(int i = 0; i <= SPACE; i++) {
		(*output) << "=";
	}
	(*output) << "=\n";

	for(vector<char>row: cells) {	// Display Solution board
		(*output) << "|";
		for(char cell: row) {
			(*output) << cell;
		}
		(*output) << "|" << "\n";
	}

	for(int i = 0; i <= SPACE; i++) {	// Formatting
		(*output) << "=";
	}
	(*output) << "=\n\n";
}

void Crossboard::showPuzzle(string filename) {	// Implementation of showPuzzle: Puzzle board
	ostream* output;
	ofstream ofs;

	if(filename != "") {
		ofs.open(filename, ios_base::app);
		output = &ofs;
	} else {
		output = &cout;
	}

	(*output) << "Crossword puzzle: " << "\n";	// Formatting
	for(int i = 0; i <= SPACE; i++) {
		(*output) << "=";
	}
	(*output) << "=\n";

	for(vector<char>row: cells) {	// Display Puzzle board
		(*output) << "|";
		for(char cell: row) {
			if(cell == '.') {
				(*output) << '#';
			} else if(isalpha(cell)) {
				(*output) << " ";
			} else {
				(*output) << "Error: Fed character not period (.) or alphanumeric!";
			}
		}
		(*output) << "|" << "\n";
	}

	for(int i = 0; i <= SPACE; i++) {	// Formatting
		(*output) << "=";
	}
	(*output) << "=\n\n";
}

void Crossboard::showClues(string filename) {	// Implementation of showClues: Clues table
	ostream* output;
	ofstream ofs;

	if(filename != "") {
		ofs.open(filename,ios_base::app);
		output = &ofs;
	} else {
		output = &cout;
	}

	(*output) << "Clues: " << "\n";	// Formatting

	for(Word word:words) {	// Set up and show Clues table
		(*output) << setw(2) << word.col << "," << setw(2) << word.row << left << setw(6);

		switch(word.pos) {
			case across:
				(*output) << " Across ";
				break;
			case down:
				(*output) << " Down   ";
				break;
			default:
				cout << "Error: Invalid position - not across or down!";
		}
		string shuffled = word.word;
		while(shuffled == word.word) {
			random_shuffle(shuffled.begin(), shuffled.end());
		}
		(*output) << right << shuffled << "\n";
	}
	(*output) << "\n\n";
}

void Crossboard::display(string filename) {		// Implementation of display: combine all displays needed
	showSolution(filename);
	showPuzzle(filename);
	showClues(filename);
}

vector<Word> Crossboard::wordsAt(int row, int col) {	// Implementation of wordsAt: check locations of every word on board
	vector<Word> wordAtPosition;
	int startRow = -1;
	int startCol = -1;
	int offsetR = 0;

	while(cells[row - offsetR][col] != ENUL) {	// For checking if down orientation
		offsetR++;
		if(row-offsetR < 0) {
			break;
		}
		if(row - offsetR == 0) {
			if(cells[row-offsetR][col] != ENUL) {
				offsetR++;
			}
			break;
		}
	}

	offsetR--;
	startRow = row - offsetR;
	startCol = col;
	for(Word word:words) {
		if(word.row == startRow && word.col == startCol && word.pos == down) {
			wordAtPosition.push_back(word);
			break;
		}
	}

	startRow = -1;
	startCol = -1;
	int offsetC = 0;
	while(cells[row][col-offsetC] != ENUL) {	// For checking if across orientation
		offsetC++;
		if(col-offsetC < 0) {
			break;
		}
		if(col - offsetC == 0) {
			if(cells[row][col-offsetC] != ENUL) {
				offsetC++;
			}
			break;
		}
	}

	offsetC--;
	startRow = row;
	startCol = col - offsetC;
	for(Word word:words) {
		if(word.row == startRow && word.col == startCol && word.pos == across) {
			wordAtPosition.push_back(word);
			break;
		}
	}
	return wordAtPosition;
}

vector<int> Crossboard::fitInBoard(string word, int ignore) {	// Implementation of fitInBoard: fit word in board given restraints
	vector<int> coords= {-1,-1, -1,-1}; 	// Row, Column, Index, Position
	int match = 0;

	for(int row = 0; row < (int) cells.size(); row++) {
		for(int col = 0; col < (int) cells[row].size(); col++) {
			for(int letter = 0; letter < (int) word.size(); letter++) {
				if(word[letter] == cells[row][col]) {
					vector<Word> inWord = wordsAt(row,col);
					match++;
					if(match > ignore) {
						coords[0] = row;
						coords[1] = col;
						coords[2] = letter;

						if(inWord[0].pos == across) {
							coords[3] = down;
						} else {
							coords[3] = across;
						}
						goto exit;
					}
				}
			}
		}
	}
	exit:;
	return coords;
}

Error Crossboard::arrange(vector<string> words) {	// Implementation of arrange: actually place words on board
	Error err = Error();
	err.success = false;

	string longest = words.back();	// Place first word
	int col = SPACE/4;

	while(!err.success) {
		err = addWord(longest, SPACE/2, col, across);
		col = col/2;
	}
	words.pop_back();

	while(words.size() > 0) {	// Place words after longest first word
		err.success = false;
		int offset = -1;

		string word = words.back();
		words.pop_back();

		bool found = false;		// Check if placement possible

		for(char letter: word) {
			for(vector<char>column: cells) {
				if(find(column.begin(), column.end(), letter) != column.end()) {
					found = true;
				}
			}
		}

		if(!found) {
			cout << "Error: Cannot place " << word << " in Crossword!\n";
			continue;
		}

		while(!err.success) {
			err = tryWord(word,offset);
			offset++;
			if(offset > SPACE*SPACE) {	// Rearrange/scramble
				if((*this).words.size() == 1) {
					string notPart = words.back();
					words.pop_back();

					cout << "Error: Cannot place " << notPart << " in Crossword!\n";
					word = words.back();
					words.pop_back();
					offset = -1;
				} else {
					Word lastWord = (*this).words.back();
					Error what = delWord(lastWord.row, lastWord.col, lastWord.pos);
					offset = lastWord.offset + 1;

					words.push_back(word);
					word = lastWord.word;
				}
			}
		}
	}
	return err;
}

Error Crossboard::tryWord(string word, int offset) {	// Implementation of tryWord: check for appropriate space in board
	Error err = Error();
	vector<int> coords = fitInBoard(word,offset);

	if(coords[0] == -1) {
		err.error("Error: No placement for word!");
		return err;
	}

	Position position = (Position) coords[3];

	if(position == across) {
		coords[1] = coords[1]-coords[2];
	} else {
		coords[0] = coords[0]-coords[2];
	}
	err = addWord(word,coords[0],coords[1],position, offset);

	return err;
}

Error Crossboard::addWord(string word, int row, int col, Position pos, int offset) {	// Implementation of addWord: error checks before placing (call place function) word
	Error err;

	for(Word dict: words) {
		if(word == dict.word) {
			err.error("Error: Word given already in dictionary!");
			return err;
		}
	}

	Word newWord;
	newWord.word = word;
	newWord.row = row;
	newWord.col = col;
	newWord.pos = pos;
	newWord.offset = offset;
	err = place(newWord);

	if(err.success) {
		if(words.size() < 20) {
			words.push_back(newWord);
		} else {
			err.error("Error: Maximum number of words reached!");
		}
	}
	return err;
}

Error Crossboard::delWord(int row, int col, Position pos) {		// Implementation of delWord: error checks before placing word, will delete if not possible
	vector<Word> killWords = wordsAt(row,col);
	Word killWord;
	Error err;

	for(Word word:killWords) {
		if(word.pos == pos){
			killWord = word;
		}
	}

	if(killWords.size() == 0) {
		err.error("Error: No words at location!");
		return err;
	}

	if(killWord.pos == across) {
		for(int offset = 0; offset < (int) killWord.word.size(); offset++) {
			if(killWord.row - 1 < 0) {
				if(killWord.row + 1 >= SPACE) {
					cells[killWord.row][killWord.col+offset] = ENUL;
				} else {
					if(cells[killWord.row+1][killWord.col+offset] == ENUL) {
						cells[killWord.row][killWord.col+offset] = ENUL;
					}
				}
			} else {
				if(cells[killWord.row-1][killWord.col+offset] == ENUL) {
					if(killWord.row + 1 >= SPACE) {
						cells[killWord.row][killWord.col+offset] = ENUL;
					} else {
						if(cells[killWord.row+1][killWord.col+offset] == ENUL) {
							cells[killWord.row][killWord.col+offset] = ENUL;
						}
					}
				}
			}
		}
	} else {
		for(int offset = 0; offset < (int) killWord.word.size(); offset++) {
			if(killWord.col - 1 < 0) {
				if(killWord.col + 1 > SPACE) {
					cells[killWord.row+offset][killWord.col] = ENUL;
				}
			} else {
				if(cells[killWord.row+offset][killWord.col-1] == ENUL) {
					if(killWord.col + 1 > SPACE) {
						cells[killWord.row+offset][killWord.col] = ENUL;
					} else {
						if(cells[killWord.row+offset][killWord.col+1] == ENUL) {
							cells[killWord.row+offset][killWord.col] = ENUL;
						}
					}
				}
			}
		}
	}

	for(auto i = words.begin(); i < words.end(); i++) {
		if(*i == killWord) {
			words.erase(i);
		}
	}
	return err;
}

Error Crossboard::place(Word wordContainer) {	// Implementation of place: error checks before placing word
	Error err;
	int offsetR = 0;
	int offsetC = 0;
	vector<Word> overlapping = {};
	string word = wordContainer.word;
	int row = wordContainer.row;
	int col = wordContainer.col;
	Position pos = wordContainer.pos;

	if(row < SPACE && row >= 0 && col < SPACE && col >= 0) {	// Check if in board
		switch(pos) {
			case down:
				if(row + word.size() <= SPACE) {
					offsetR = 1;
				}else{
					err.error("Error: Word given too long!");
					return err;
				}
				break;
			case across:
				if(col + word.size() <= SPACE) {
					offsetC = 1;
				}else{
					err.error("Error: Word given too long!");
					return err;
				}
				break;
			default:
				err.error("Error: Default exit!");
				return err;
		}
	} else {
		err.error("Error: Invalid coordinates!");
		return err;
	}

	for(int i = 0; i < (int) word.size(); i++) {	// Check for word overlaps
		int offRow = row+(offsetR*i);
		int offCol = col+(offsetC*i);

		if(cells[offRow][offCol] == ENUL || cells[offRow][offCol] == word[i]) {
			if(cells[offRow][offCol] == word[i]) {
				for(Word adjWord:wordsAt(offRow,offCol)) {
					if(adjWord.pos == pos) {
						err.error("Error: Invalid location - creates long letter!");
						return err;
					}
					overlapping.push_back(adjWord);
				}
			}
			continue;
		} else {
			err.error("Error: Letter overlaps!");
			return err;
		}
	}

	for(int i = 0; i < (int) word.size(); i++) {	// Check for word next to each other
		int offRow = row+(offsetR*i);
		int offCol = col+(offsetC*i);
		for(int aRow = offRow-1; aRow <= offRow+1; aRow++) {
			if(aRow < 0 || aRow >= SPACE) {
				continue;
			}
			for(int aCol = col-1; aCol <= offCol+1; aCol++) {
				if(aCol < 0 || aCol >= SPACE || (aCol == offCol && aRow == offRow)) {
					continue;
				}
				if(cells[aRow][aCol] != ENUL) {
					for(Word adjWord:wordsAt(aRow,aCol)) {
						if(find(overlapping.begin(),overlapping.end(),adjWord) == overlapping.end()){
							err.error("Error: Letter overlaps!");
							return err;
						}
					}
				}
			}
		}
	}

	for(int i = 0; i < (int) word.size(); i++) {
		int offRow = row+(offsetR*i);
		int offCol = col+(offsetC*i);
		cells[offRow][offCol] = word[i];
	}
	return err;
}