#include <iostream>
#include <cmath>
#include <cfloat>
#include <string>

using namespace std;

int main()
{
	int viN, n;
	const int cviMaxIter = 500;
	double vdAccuracy, vdX_initial, vdX_final, vdDX;

	cout << showpos << fixed;
	cout << "Enter the initial number X: "; cin >> vdX_initial;
	cout << "\nEnter the final number X: "; cin >> vdX_final;
	cout << "\nEnter the step dX: "; cin >> vdDX;
	cout << "\nEnter the accuracy: "; cin >> vdAccuracy;
	cout << "\n\n" << string(39, '-');
	cout << "\n|";
	cout.width(7); cout << "X";
	cout.width(7); cout << "||";
	cout.width(7); cout << "F";
	cout.width(7); cout << "||";
	cout.width(5); cout << "N";
	cout.width(6); cout << "|\n";
	cout << string(39, '-') << endl;

	for (double i = vdX_initial; i <= vdX_final ; i += vdDX)
	{
		double vdCn = i, vdF = vdCn;
		int viI = trunc(fabs(i));

		for (n = 0; fabs(vdCn) >= vdAccuracy; n++)
		{
			if ((n >= cviMaxIter)||(viI > 1))
			{
				cout << "|";
				cout << showpos;
				cout.precision(6);
				cout.width(5); cout << i;
				cout.width(5); cout << "||";
				cout.precision(6);
				cout << "RowBreaksUp";
				cout.width(3); cout << "||";
				cout.precision(6);
				cout.width(5); cout << "-";
				cout.width(6); cout << "|\n";

				break;
			}

			vdCn *= ((2*n+1)*pow(i, 2)) / (2*n+3);
			vdF += vdCn;
		}

		if ((viI < 1)&&(fabs(fabs(i) - 1) > 1e-15))
		{
			cout << "|";
			cout << showpos;
			cout.precision(6);
			cout.width(5); cout << i;
			cout.width(5); cout << "||";
			cout.precision(6);
			cout.width(5); cout << 2*vdF;
			cout.width(5); cout << "||";
			cout << noshowpos;
			cout.precision(6);
			cout.width(5); cout << n+1;
			cout.width(5); cout << "|";

			cout << showpos;
			cout << "In comparison with " << log((1 + i) / (1 - i)) 
				<< " of cmath function" << endl;;
		}
	}

	cout << string(39, '-') << endl;

	return 0;
}