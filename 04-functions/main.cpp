#include <iostream>
#include <cmath>
#include <cfloat>
#include <string>

using namespace std;

void fvTable(void);
void fvBreakRow(double);
void fdFillTable(double, double, int);

int main()
{
	int viN;
	const int cviMaxIter = 500;
	double vdAccuracy, vdX_initial, vdX_final, vdDX;

	cout << "Enter the initial number X: "; cin >> vdX_initial;
	cout << "\nEnter the final number X: "; cin >> vdX_final;
	cout << "\nEnter the step dX: "; cin >> vdDX;
	cout << "\nEnter the accuracy: "; cin >> vdAccuracy;

	fvTable();

	for (double i = vdX_initial; i <= vdX_final; i += vdDX)
	{
		double vdCn = i, vdF = vdCn;
		int viI = static_cast<int>(trunc(fabs(i)));

		for (viN = 0; fabs(vdCn) >= vdAccuracy; viN++)
		{
			if ((viN >= cviMaxIter) || (viI > 1))
			{
				fvBreakRow(i);
				break;
			}

			vdCn *= ((2 * viN + 1)*pow(i, 2)) / (2 * viN + 3);
			vdF += vdCn;
		}

		if ((viI < 1) && (fabs(fabs(i) - 1) > 1e-15))
			fdFillTable(i, vdF, viN);
	}

	cout << string(39, '-') << endl;

	return 0;
}

void fvTable()
{
	cout << "\n\n" << string(39, '-');
	cout << "\n|";
	cout.width(7); cout << "X";
	cout.width(7); cout << "||";
	cout.width(7); cout << "F";
	cout.width(7); cout << "||";
	cout.width(5); cout << "N";
	cout.width(6); cout << "|\n";
	cout << string(39, '-') << endl;
	cout << showpos << fixed;
}

void fvBreakRow(double i)
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
}

void fdFillTable(double i, double vdF, int viN)
{
	cout << "|";
	cout << showpos;
	cout.precision(6);
	cout.width(5); cout << i;
	cout.width(5); cout << "||";
	cout.precision(6);
	cout.width(5); cout << 2 * vdF;
	cout.width(5); cout << "||";
	cout << noshowpos;
	cout.precision(6);
	cout.width(5); cout << viN + 1;
	cout.width(5); cout << "|";

	cout << showpos;
	cout << "In comparison with " << log((1 + i) / (1 - i))
		<< " of cmath function" << endl;;
}