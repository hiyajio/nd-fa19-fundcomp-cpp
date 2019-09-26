/* Football Score Formula
 * Name: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 */
#include <iostream>
using namespace std;;

int main()
{
        int td;
        int xtraPt;
        int fieldG;
        int safety;
        int total;

        // Begin program - ask user for input
        cout << "\n\n\n==========Football Score Formula==========\n\n";
        cout << "Number of touchdowns? ";
        cin >> td;
        cout << "Number of extra points? ";
        cin >> xtraPt;
        cout << "Number of field goals? ";
        cin >> fieldG;
        cout << "Number of safeties? ";
        cin >> safety;

        // Variables to store scores after multiplier
        int scoreTD;
        int scoreFG;
        int scoreS;

        scoreTD = td*6;          // x6 for touchdowns
        scoreFG = fieldG*3;      // x3 for field goals 
        scoreS = safety*2;       // x2 for safeties

        total = scoreTD + xtraPt + scoreFG + scoreS; // total all scores

        // Display to user total score
        cout << "\n\n==========Total Score==========\n\n" << total << " points!\n\n\n";

        return 0;
}