/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: state.h
 * Description: Class interface for State class for Part 3 of lab (State)
 */
#include <string>
#include <vector>
#include <array>
using namespace std;

class State {   // Class interface of State
    public:
        State(vector<string> &defStates);
        ~State();
        void showInfoAll() const;
        void showInfoAbbr(string userAbbr) const;
        void showInfoName(string userName) const;
        void showInfoCptl(string userCptl) const;
        void showStatePopMin(int userPop) const;
        void showStatePopMax(int userPop) const;
        void showStateYearMin(int userYear) const;
        void showStateYearMax(int userYear) const;
        void showStateRepMin(int userRep) const;
        void showStateRepMax(int userRep) const;
    private:
        vector<string> states;
};