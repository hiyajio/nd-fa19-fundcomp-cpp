/* Developer: Juan Sergio Buenviaje
 * Lab: Tuesdays 2:25 - 3:15pm
 * Program: grades.cpp
 * Description: Rolls through array of grades and gets size, average, & standard deviation.
 */
#include <iostream>                             // Library Declarations
#include <iomanip>
#include <cmath>
using namespace std;

double get_arrsize(int arr[], int sent);        // Function Declarations
double get_average(int arr[], int size);
double get_standev(int arr[], int size, double ave);

int main()
{
    double ave;     // Variable Declarations
    double sd;
    double size;
    int sent = -1;  // Sentinel Value
    int grades[50] = {
            96,73,62,87,80,63,93,79,71,99,
            82,83,80,97,89,82,93,92,95,89,
            71,97,91,95,63,81,76,98,64,86,
            74,79,98,82,77,68,87,70,75,97,
            71,94,68,87,79, -1
    };              // Grades Array

    cout << setprecision(5);        // Formatting Display
    cout << "\n\n======= Mean & Standard Dev. of Grades =======\n\n";       // Header

    size = get_arrsize(grades, sent);       // Call get_arrsize Function

    cout << "Size of Grades Array: " << size << "\n\n";     // Display Returned Size

    ave = get_average(grades, size);        // Call get_average Function
    sd = get_standev(grades, size, ave);    // Call get_standev Function

    cout << "Average of Grades Array: " << ave << "\n";     // Display Returned Average
    cout << "Standard Deviation of Grades Array: " << sd << "\n\n\n";
            // Diplay Returned Standard Dev

    return 0;
}

double get_arrsize(int arr[], int sent) {
    int i = 0;                      // Initialize Looping Value
    while (arr[i] != sent) {        // Terminate once Sentinel Value is Seen
        i += 1;                 // Increment Value for no Infinite Loop
    }

    return i;                       // Return Size
}

double get_average(int arr[], int size) {
    double ave;                     // Initialize Variables
    double total = 0;

    for (int i = 0; i < size; ++i) {
        total = total + arr[i]; // Add to Total
    }

    ave = total / size;             // Get Average from Total / Size of Array
    return ave;                     // Return Average
}

double get_standev(int arr[], int size, double ave) {
    double sd;                      // Initialize Variables
    double var = 0;

    for (int i = 0; i < size; ++i) {
        var += (arr[i] - ave) * (arr[i] - ave);
                                    // Get Variance Total from Array Value & Average
    }

    var /= size;                    // Get Variance by Dividing with Array Size
    sd = sqrt(var);                 // Get Standard Deviation from Square Root of Variance
    return sd;                      // Return Standard Deviation
}