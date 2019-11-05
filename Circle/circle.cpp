/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: circle.cpp
 * Description: Implementation of Circle class in circle.h for Part 1 of lab (Circle)
 */
#include <iostream>
#include <string>
// Include math.h for PI
#include <math.h>
using namespace std;

// Include circle.h file for access
#include "circle.h"

// Implementation of Circle w/o default radius set
Circle::Circle() {

}

// Implementation of Circle w default radius set
Circle::Circle(float defRadius) {
    radius = defRadius;
}

Circle::~Circle() {

}

// getRadius() implementation returns radius
float Circle::getRadius() const {
    return radius;
}

// setRadius() implementation overwrites radius w new value
void Circle::setRadius(float newRadius){
    radius = newRadius;
}

// circumference() implementation calculates and returns circumference
float Circle::circumference() const {
    // Circumference = 2(PI)r
    float circumference = M_PI * 2 * radius;
    return circumference;
}

// area() implementation calculates and returns area
float Circle::area() const {
    // Area = (PI)(r^2)
    float area = M_PI * radius * radius;
    return area;
}

// info() implementation displays radius, circumference and area of circle
void Circle::info() const {
    cout << "  radius: " << radius << "\n";
    cout << "  circumference: " << circumference() << "\n";
    cout << "  area: " << area() << "\n";
}