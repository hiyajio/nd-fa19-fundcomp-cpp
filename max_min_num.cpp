#include <iostream>
using namespace std;

/* Define your functions here */
int LargestNumber(int, int, int);
int SmallestNumber(int, int, int);

int main() {
    int largest;
    int smallest;
    int num1;
    int num2;
    int num3;

    cin >> num1;
    cin >> num2;
    cin >> num3;

    largest = LargestNumber(num1, num2, num3);
    smallest = SmallestNumber(num1, num2, num3);

    cout << "largest: " << largest << "\n";
    cout << "smallest: " << smallest << "\n";

    return 0;
    }

    int LargestNumber(int num1, int num2, int num3) {
    int largest;

    if (num1 == num2) {
        if (num1 > num3) {
            largest = num1;
        } else if (num1 < num3) {
            largest = num3;
        } else {
            largest = num1;
        }
    }

    if (num2 == num3) {
        if (num2 > num1) {
            largest = num2;
        } else if (num2 < num1) {
            largest = num1;
        } else {
            largest = num2;
        }
    }

    if (num1 == num3) {
        if (num1 > num2) {
            largest = num1;
        } else if (num1 < num2) {
            largest = num2;
        } else {
            largest = num1;
        }
    }

    if (num1 > num2) {
        if (num1 > num3) {
            largest = num1;
        } else if (num3 > num1) {
            largest = num3;
        }
    } else if (num2 > num1) {
        if (num2 > num3) {
            largest = num2;
        } else if (num3 > num2) {
            largest = num3;
        }
    }

    return largest;
    }

    int SmallestNumber(int num1, int num2, int num3) {
    int smallest;

    if (num1 == num2) {
        if (num1 < num3) {
            smallest = num1;
        } else if (num1 > num3) {
            smallest = num3;
        } else {
            smallest = num1;
        }
    }

    if (num2 == num3) {
        if (num2 < num1) {
            smallest = num2;
        } else if (num2 > num1) {
            smallest = num1;
        } else {
            smallest = num2;
        }
    }

    if (num1 == num3) {
        if (num1 < num2) {
            smallest = num1;
        } else if (num1 > num2) {
            smallest = num2;
        } else {
            smallest = num1;
        }
    }

    if (num1 < num2) {
        if (num1 < num3) {
            smallest = num1;
        } else if (num3 < num1) {
            smallest = num3;
        }
    } else if (num2 < num1) {
        if (num2 < num3) {
            smallest = num2;
        } else if (num3 < num2) {
            smallest = num3;
        }
    }

    return smallest;
}