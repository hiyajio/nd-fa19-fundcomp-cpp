/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: rational.cpp
 * Description: Implementation of Rational class in rational.h for Part 2 of lab (Rational)
 */
#include <iostream>
#include <string>
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
int Rational::getNumer() const {
    return numer;
}

// getDenom() implementation returns denom
int Rational::getDenom() const {
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

// info() implementation displays numer, and denom in proper format
void Rational::print() const {
    cout << numer << "/" << denom << "\n";
}

// add() implementation calculates and returns sum
Rational Rational::add(Rational ration) const {
    Rational sum;
    // For easier use in computing
    int otherDenom = ration.getDenom();
    int otherNumer = ration.getNumer();

    // (a/b)+(c/d) = ((a*d)+(b*c))/(b*d)
    sum.numer = (numer * otherDenom) + (denom * otherNumer);
    sum.denom = denom * otherDenom;
    return sum;
}

// subtract() implementation calculates and returns difference
Rational Rational::subtract(Rational ration) const {
    Rational difference;
    // For easier use in computing
    int otherDenom = ration.getDenom();
    int otherNumer = ration.getNumer();

    // (a/b)-(c/d) = ((a*d)-(b*c))/(b*d)
    difference.numer = (numer * otherDenom) - (denom * otherNumer);
    difference.denom = denom * otherDenom;
    return difference;
}

// multiply() implementation calculates and returns product
Rational Rational::multiply(Rational ration) const {
    Rational product;

    // (a/b)*(c/d) = (a*c)/(b*d)
    product.numer = numer * ration.getNumer();
    product.denom = denom * ration.getDenom();
    return product;
}

// divide() implementation calculates and returns quotient
Rational Rational::divide(Rational ration) const {
    Rational quotient;

    // (a/b)/(c/d) = (a/b)*(d/c)
    quotient.numer = numer * ration.getDenom();
    quotient.denom = denom * ration.getNumer();
    return quotient;
}