#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double x;
    double y;
    double z;

    cin >> x;
    cin >> y;
    cin >> z;

    double ans1;
    double ans2;
    double ans3;
    double ans4;

    ans1 = pow(x, y);

    ans2 = pow(x, pow(y, z));

    ans3 = abs(x);

    ans4 = sqrt(pow(x*y, z));

    cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << "\n";

    return 0;
}