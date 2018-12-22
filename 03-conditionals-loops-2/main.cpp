#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const int kMaxIter = 500;

    double x_initial, x_final, dx, accuracy;

    cout << showpos << fixed;

    do {
        cout << "Please, enter the correct numbers!";
        cout << "\nEnter the initial number X1 (-1 < X1 < 1): ";
        cin >> x_initial;
        cout << "\nEnter the final number X2 (-1 < X2 < 1, X2 >= X1): ";
        cin >> x_final;
        cout << "\nEnter the step dX (dX > 0): ";
        cin >> dx;
        cout << "\nEnter the accuracy (> 0): ";
        cin >> accuracy;
    } while ((fabs(x_initial) >= 1) || (fabs(x_final) >= 1) ||
        (dx <= 0) || (accuracy <= 0) || (x_initial > x_final));

    cout << "|" << string(11, '\xc4') << "|" << string(17, '\xc4');
    cout << "|" << string(17, '\xc4') << "|" << string(9, '\xc4') << "|\n";
    cout << "|" << setw(6) << "x" << setw(6);
    cout << "|" << setw(16) << "ln((1+x)/(1-x))" << setw(2);
    cout << "|" << setw(16) << "ln((1+x)/(1-x))" << setw(2);
    cout << "|" << setw(7) << "iters" << setw(4) << "|\n";
    cout << "|" << string(11, ' ') << "|" << setw(12) << "(cmath)" << setw(6);
    cout << "|" << setw(12) << "(mine)" << setw(6) << "|" << string(9, ' ') << "|\n";
    cout << "|" << string(11, '\xc4') << "|" << string(17, '\xc4');
    cout << "|" << string(17, '\xc4') << "|" << string(9, '\xc4') << "|\n";

    for (double x = x_initial; x <= x_final; x += dx) {
        int n;
        double cn = 2 * x, f = cn;

        for (n = 1; (n <= kMaxIter) && (abs(cn) >= accuracy); n++) {
            cn = 2 * (pow(x, 1 + n * 2) / (1 + n * 2));
            f += cn;
        }

        cout << "|" << setw(10) << x << setw(2);
        cout << "|" << setw(13) << log((1 + x) / (1 - x)) << setw(5) << "|";

        if (n > kMaxIter)
            cout << "  row breaks up  ";
        else
            cout << setw(13) << f << setw(5);

        cout << "|" << setw(5) << n << setw(6) << "|\n";
    }

    cout << "|" << string(11, '\xc4') << "|" << string(17, '\xc4');
    cout << "|" << string(17, '\xc4') << "|" << string(9, '\xc4') << "|\n";

    return 0;
}