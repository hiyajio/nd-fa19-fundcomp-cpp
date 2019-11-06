/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: rational.h
 * Description: Class interface for Rational class for Part 2 of lab (Rational)
 */
#include <string>
using namespace std;

// Class interface of Rational
// Added names for variables to be used for easier translatability
// Added const depending on need of function
class Rational {
    public:
        Rational();
        Rational(int defNumer, int defDenom);
        ~Rational();
        int getNumer() const;
        int getDenom() const;
        void setNumer(int newNumer);
        void setDenom(int newDenom);
        void print() const;
        Rational add(Rational ration) const;
        Rational subtract(Rational) const;
        Rational multiply(Rational ration) const;
        Rational divide(Rational ration) const;
    private:
        int numer;
        int denom;
};
