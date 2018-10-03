#include <iostream>

using namespace std;

int main()
{
	double vdA, vdB, vdC, vdX_initial, vdX_final, vdDX;

	cout << "Enter the number a: "; cin >> vdA;
	cout << "\nEnter the number b: "; cin >> vdB;
	cout << "\nEnter the number c: "; cin >> vdC;
	cout << "\nEnter the initial number X: "; cin >> vdX_initial;
	cout << "\nEnter the final number X: "; cin >> vdX_final;
	cout << "\nEnter the step dX: "; cin >> vdDX;
	cout << "\n\n--------------------------------";
	cout << "\n\tX\t||\tF" << endl;
	cout << "--------------------------------" << endl;

	for (vdX_initial; vdX_initial <= vdX_final; vdX_initial += vdDX)
	{
		if ((vdX_initial < 0) && (vdB != 0)) 
			cout << "\t" << vdX_initial << "\t||\t" << vdA - vdX_initial / (10 + vdB) << endl;
		else if ((vdX_initial > 0)&&(vdB == 0)) 
			cout << "\t" << vdX_initial << "\t||\t" << (vdX_initial - vdA) / (vdX_initial - vdC) << endl;
		else 
			cout << "\t" << vdX_initial << "\t||\t" << 3*vdX_initial + 2/vdC << endl;
	}
	cout << "--------------------------------" << endl;

	system("PAUSE");

	return 0;
}