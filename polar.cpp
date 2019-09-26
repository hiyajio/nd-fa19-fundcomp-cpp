/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: polar.cpp
 * Description: Displays radius, angle, and quadrant info based on user inputs x and y
 */
#include <iostream>
using namespace std;
#include <cmath>        // Include cmath for needed functions
#include <math.h>
#include <iomanip>

#define PI 3.14159265

double get_radius(double, double);      // Initialize functions needed
double get_angle(double, double);
void quadrant_info(double, double);

int main() {
        double x, y;            // Initialize variables needed
        double radius, angle;

        cout << "\n\n======= Quadrant and Polar Coordinates Calculator =======\n\n";
        cout << "Enter X - Coordinate: ";       // Prompts user for x
        cin >> x;                               // Stores x
        cout << "Enter Y - Coordinate: ";       // Prompts user for y
        cin >> y;                               // Stores y

        radius = get_radius(x, y);      // Call the get_radius function
        angle = get_angle(x, y);        // Call the get_angle function

        cout << fixed << setprecision(2);
        cout << "\nRadius (in Degrees): " << radius << "\n";
        cout << "Angle (in Degrees): " << angle << "\n";

        quadrant_info(x, y);   // Call the quadrant_info function

        return 0;
}

double get_radius(double x, double y) {
        double radius;
        double step;
        step = x*x + y*y;       // Made incremental step since sqrt() only takes in one var
        radius = sqrt(step);    // Continuation of formula for radius

        return radius;
}

double get_angle(double x, double y) {
        double angle;
        angle = atan2(y, x) * (180.0 / PI);     // Multiplied by 180/pi to convert it to degrees

        if (((x > 0) && (y < 0)) || ((x < 0) && (y < 0))) {
                angle = angle + 360.0;          // Extra step if in QIII or  QIV for proper angle
        }

        return angle;
}

void quadrant_info(double x, double y) {
        cout << "Quadrant Information: Point at ";
        if (x == 0) {
                if (y == 0) {
                        cout << "Origin\n\n\n";         // If x == 0 && y == 0
                } else {
                        cout << "Y-Axis\n\n\n";         // If x == 0 only
                }
        } else if (y == 0) {
                cout << "X-Axis\n\n\n";                 // If y == 0 only
        } else if (x > 0) {
                if (y > 0) {
                        cout << "Quadrant I\n\n\n";     // If x > 0 && y > 0
                } else {
                        cout << "Quadrant IV\n\n\n";    // If x > 0 && y < 0
                }
        } else {
                if (y > 0) {
                        cout << "Quadrant II\n\n\n";    // If x < 0 && y > 0
                } else {
                        cout << "Quadrant III\n\n\n";   // If x < 0 && y < 0
                }
        }
}