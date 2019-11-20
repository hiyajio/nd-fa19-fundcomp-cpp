/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: lifeboard.h
 * Description: Class interface for Life class
 */
const int SIZE = 40;    // Initialize constant variables
const char DEAD = ' ';
const char ALIVE = 'X';
const char BEND = '=';

class Lifeboard{    // Class interface of Lifeboard
    public:
        Lifeboard();
        ~Lifeboard();
        void show();
        void live(int, int);
        void kill(int, int);
        void nextGen();
    private:
        char board[SIZE][SIZE];
};
