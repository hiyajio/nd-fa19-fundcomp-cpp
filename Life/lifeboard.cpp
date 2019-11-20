/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: lifeboard.cpp
 * Description: Implementation of Life class in lifeboard.h
 */
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

#include "lifeboard.h"  // Include lifeboard.h file for access

Lifeboard::Lifeboard() {    // Implementation of Lifeboard: sets up default empty board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = DEAD;
        }
    }
}

Lifeboard::~Lifeboard() {

}

void Lifeboard::show() {    // Implementation of show: displays current state of board
    for (int i = 0; i < SIZE; i++) {
        cout << BEND;
    }

    cout << "\n";

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }

    for (int i = 0; i < SIZE; i++) {
        cout << BEND;
    }
}

void Lifeboard::live(int x, int y) {    // Implementation of live: turns targeted cell to alive
    board[x][y] = ALIVE;
}

void Lifeboard::kill(int x, int y) {    // Implementation of kill: turns targeted cell to dead
    board[x][y] = DEAD;
}

void Lifeboard::nextGen() { // Implementation of nextGen: implements rules of Game of Life
    int deadCounter = 0;
    int liveCounter = 0;
    char newBoard[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            newBoard[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (newBoard[i][j] == ALIVE) {  // If cell is alive, check if next to 2-3 neighbors to keep living
                liveCounter = 0;
                if (newBoard[i-1][j-1] == ALIVE) {
                    liveCounter++;
                }
                if (newBoard[i][j-1] == ALIVE) {
                    liveCounter++;
                }
                if (newBoard[i+1][j-1] == ALIVE) {
                    liveCounter++;
                }
                if (newBoard[i-1][j] == ALIVE) {
                    liveCounter++;
                }
                if (newBoard[i+1][j] == ALIVE) {
                    liveCounter++;
                }
                if (newBoard[i-1][j+1] == ALIVE) {
                    liveCounter++;
                }
                if (newBoard[i][j+1] == ALIVE) {
                    liveCounter++;
                }
                if (newBoard[i+1][j+1] == ALIVE) {
                    liveCounter++;
                }

                if ((liveCounter == 2) || (liveCounter == 3)) {
                    board[i][j] = ALIVE;
                } else {
                    board[i][j] = DEAD;
                }
            } else {    // If cell is dead, check if next to exactly 3 neighbors to turn alive
                deadCounter = 0;
                if (newBoard[i-1][j-1] == ALIVE) {
                    deadCounter++;
                }
                if (newBoard[i][j-1] == ALIVE) {
                    deadCounter++;
                }
                if (newBoard[i+1][j-1] == ALIVE) {
                    deadCounter++;
                }
                if (newBoard[i-1][j] == ALIVE) {
                    deadCounter++;
                }
                if (newBoard[i+1][j] == ALIVE) {
                    deadCounter++;
                }
                if (newBoard[i-1][j+1] == ALIVE) {
                    deadCounter++;
                }
                if (newBoard[i][j+1] == ALIVE) {
                    deadCounter++;
                }
                if (newBoard[i+1][j+1] == ALIVE) {
                    deadCounter++;
                }

                if (deadCounter == 3) {
                    board[i][j] = ALIVE;
                }
            }

            deadCounter = 0;    // Reset counters
            liveCounter = 0;
        }
    }
}