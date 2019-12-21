/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: crossboard.h
 * Description: Class interface for Crossboard class
 */
#include <iostream>		// Initialize needed libraries
using namespace std;
#include <fstream>
#include <vector>
#include <string>

const char ENUL = '.';	// Initialize constant variables
const int SPACE = 15;
enum Position{down, across, none};

bool compare(string firWord, string secWord);	// Used for determining longer word in crossboard.cpp

struct Word {		// Struct to help w Functions
	int row = -1;
	int col = -1;
	int offset = -1;
	string word;
	Position pos = none;
	bool operator == (Word w) {
		return word == w.word;
	}
};

struct Error {		// Struct to help w Errors
	string message = "";
	bool success = true;
	void error(string message){
		(*this).success = false;
		(*this).message = message;
	}
};

class Crossboard{	// Class interface of Crossboard
	public:
		Crossboard();
		~Crossboard();
		Crossboard(vector<string> words);
		void init(vector<string> words);
		void showSolution(string filename = "");
		void showPuzzle(string filename = "");
		void showClues(string filename = "");
		void display(string filename = "");
		vector<int> fitInBoard(string word, int ignore);
		vector<Word> wordsAt(int row, int col);
		Error arrange(vector<string>);
		Error tryWord(string word, int offset);
		Error addWord(string word, int row, int col, Position pos=none, int offset=-1);
		Error delWord(int row, int col, Position pos);
		Error place(Word);
	private:
		vector<vector<char>> cells;
		vector<Word> words;
};