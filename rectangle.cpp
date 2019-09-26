/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: rectangle.cpp
 * Description: Displays perimeter and area of inputted length and width through functions
 */
#include <iostream>
using namespace std;

double find_perim(double, double);
double find_area(double, double);
void display(double, double);

int main() {
        double len, wid;
        double perim, area;

        cout << "\n\nEnter the length: ";
        cin >> len;
        cout << "Enter the width: ";
        cin >> wid;

        perim = find_perim(len, wid);   // Call the find_perim function
        area = find_area(len, wid);     // Call the find_area function

        display(perim, area);           // Call the display function

        return 0;
}

double find_perim(double len, double wid) {
        double perim;
        perim = len*2 + wid*2;

        return perim;
}

double find_area(double len, double wid) {
        double area;
        area = len * wid;

        return area;
}

void display(double perim, double area) {
        cout << "\nThe perimeter is: " << perim << "\n";
        cout << "The area is: " << area << "\n\n\n";

}