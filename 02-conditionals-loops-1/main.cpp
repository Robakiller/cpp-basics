#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	const double kZero = 1e-15;

	int ac, bc, cc;
	double a, b, c, x_initial, x_final, dx;

	do {
		cout << "Please, enter the correct numbers!" << endl;
		cout << "Enter the number a: "; 
			cin >> a;
		cout << "\nEnter the number b: "; 
			cin >> b;
		cout << "\nEnter the number c: "; 
			cin >> c;
		cout << "\nEnter the initial number X1: "; 
			cin >> x_initial;
		cout << "\nEnter the final number X2 (X2 >= X1): "; 
			cin >> x_final;
		cout << "\nEnter the step dX (> 0): "; 
			cin >> dx;
	} while ((dx <= 0) || (x_initial > x_final));

	cout <<"\n\n" << string(33, '-') << endl;
	cout <<"|\tX\t||\tF\t|" << endl;
	cout << string(33, '-') << endl;

	ac = static_cast<int>(trunc(a));
	bc = static_cast<int>(trunc(b));
	cc = static_cast<int>(trunc(c));

	cout << fixed;
	cout.precision(3);
	cout << showpos;
	
	for (x_initial; x_initial <= x_final; x_initial += dx) {
		if ((x_initial < 0) && (abs(b) >= kZero))
			if (abs(10 + b) < kZero) {
				cout << "|\t" << x_initial << "\t||" 
						<< "division by 0 |" << endl;;
				continue;
			}
			else if (((ac | bc) & cc) == 0) {
				cout << "|\t" << x_initial << "\t||\t"
						<< static_cast<int>(a - x_initial / (10 + b)) << "\t|" << endl;
			}
			else {
				cout << "|\t" << x_initial << "\t||\t"
						<< a - x_initial / (10 + b) << "\t|" << endl;
			}
		
		else if ((x_initial > 0) && (abs(b) < kZero))
			if (abs(x_initial - c) < kZero) {
				cout << "|\t" << x_initial << "\t||"
						<< "division by 0 |" << endl;;
				continue;
			}
			else if (((ac | bc) & cc) == 0) {
				cout << "|\t" << x_initial << "\t||\t"
						<< static_cast<int>((x_initial - a) / (x_initial - c)) << "\t|" << endl;
			}
			else {
				cout << "|\t" << x_initial << "\t||\t"
						<< (x_initial - a) / (x_initial - c) << "\t|" << endl;
			}

		else 
			if (abs(c) < kZero) {
				cout << "|\t" << x_initial << "\t||"
						<< "division by 0 |" << endl;;
				continue;
			}
			else if (((ac | bc) & cc) == 0) {
				cout << "|\t" << x_initial << "\t||\t"
						<< static_cast <int>(3 * x_initial + 2 / c) << "\t|" << endl;
			}
			else {
				cout << "|\t" << x_initial << "\t||\t"
						<< 3 * x_initial + 2 / c << "\t|" << endl;
			}
	}

	cout << string(33, '-') << endl;

	return 0;
}