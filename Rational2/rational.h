/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: rational.h
 * Description: Class interface for Rational class
 */
#include <string>
using namespace std;

// Class interface of Rational
// Added names for variables to be used for easier translatability
// Added setRational(), simplify() and overload operators
class Rational {
        friend ostream & operator<< (ostream &, Rational &);
        friend istream & operator>> (istream &, Rational &);
    public:
        Rational();
        Rational(int, int);
        ~Rational();
        int getNumer();
        int getDenom();
        void setNumer(int);
        void setDenom(int);
        void setRational(int, int);
        Rational simplify(Rational);
        Rational operator+ (Rational);
        Rational operator- (Rational);
        Rational operator* (Rational);
        Rational operator/ (Rational);
        Rational operator<< (Rational);
        Rational operator>> (Rational);
    private:
        int numer;
        int denom;
};
