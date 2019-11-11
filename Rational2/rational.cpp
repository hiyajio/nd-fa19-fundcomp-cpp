/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: rational.cpp
 * Description: Implementation of Rational class in rational.h
 */
#include <iostream>
#include <string>
#include <numeric>
using namespace std;

// Include rational.h file for access
#include "rational.h"

// Implementation of Rational w/o default nums set
Rational::Rational() {
    // Set defaults to 1 and 1 if no values given
    numer = 1;
    denom = 1;
}

// Implementation of Rational w default nums set
Rational::Rational(int defNumer, int defDenom) {
    numer = defNumer;
    denom = defDenom;
}

Rational::~Rational() {

}

// getNumer() implementation returns numer
int Rational::getNumer() {
    return numer;
}

// getDenom() implementation returns denom
int Rational::getDenom() {
    return denom;
}

// setNumer() implementation overwrites numer w new value
void Rational::setNumer(int newNumer){
    numer = newNumer;
}

// setDenom() implementation overwrites denom w new value
void Rational::setDenom(int newDenom){
    denom = newDenom;
}

// setRational() implementation calls setNumer() & setDenom()
void Rational::setRational(int newNumer, int newDenom) {
    setNumer(newNumer);
    setDenom(newDenom);
}

// simplify() implementation reduces/simplifies fractions for printing
Rational Rational::simplify(Rational frac) {
    int fact = gcd(frac.getNumer(), frac.getDenom());   // gcd() from <numeric> library
    int newNumer = frac.getNumer()/fact;
    int newDenom = frac.getDenom()/fact;
    if ((frac.getNumer() > 0) && (frac.getDenom() < 0)) {
        newNumer = -newNumer;
        newDenom = -newDenom;
    }
    frac.setNumer(newNumer);
    frac.setDenom(newDenom);
    return frac;
}

// Overload operator '+' calculates and returns sum
Rational Rational::operator+ (Rational ration) {
    Rational sum;
    // For easier use in computing
    int otherDenom = ration.getDenom();
    int otherNumer = ration.getNumer();

    // (a/b)+(c/d) = ((a*d)+(b*c))/(b*d)
    sum.numer = (numer * otherDenom) + (denom * otherNumer);
    sum.denom = denom * otherDenom;
    sum = simplify(sum);
    return sum;
}

// Overload operator '-' calculates and returns difference
Rational Rational::operator- (Rational ration) {
    Rational difference;
    // For easier use in computing
    int otherDenom = ration.getDenom();
    int otherNumer = ration.getNumer();

    // (a/b)-(c/d) = ((a*d)-(b*c))/(b*d)
    difference.numer = (numer * otherDenom) - (denom * otherNumer);
    difference.denom = denom * otherDenom;
    difference = simplify(difference);
    return difference;
}

// Overload operator '*' calculates and returns product
Rational Rational::operator* (Rational ration) {
    Rational product;

    // (a/b)*(c/d) = (a*c)/(b*d)
    product.numer = numer * ration.getNumer();
    product.denom = denom * ration.getDenom();
    product = simplify(product);
    return product;
}

// Overload operator '/' calculates and returns quotient
Rational Rational::operator/ (Rational ration) {
    Rational quotient;

    // (a/b)/(c/d) = (a/b)*(d/c)
    quotient.numer = numer * ration.getDenom();
    quotient.denom = denom * ration.getNumer();
    quotient = simplify(quotient);
    return quotient;
}

// Overload operator '<<' formats cout
ostream & operator<< (ostream & os, Rational & r) {
    os << r.numer << "/" << r.denom;
    return os;
}

// Overload operator '>>' formats cin
istream & operator>> (istream & is, Rational & r) {
    int num, den;
    cout << "Enter the numerator of fraction: ";
    is >> num;
    cout << "Enter the denominator of fraction: ";
    is >> den;
    r.setRational(num, den);
    return is;
}