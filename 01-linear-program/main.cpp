#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846

using namespace std;

int main() {
    double angle;
    cout << "Enter the angle in degrees: ";
    cin >> angle;

    cout << "Your result of solution with the first formula is ";
    cout << 1 - 0.25*pow(sin(2 * angle*PI / 180), 2)
        + cos(2 * angle*PI / 180);

    cout << "\nOf course, your result of solution with the second formula is ";
    cout << pow(cos(angle*PI / 180), 2)
        + pow(cos(angle*PI / 180), 4) << " too";

    return 0;
}