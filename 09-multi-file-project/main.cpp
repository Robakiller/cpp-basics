#include "functions.h"

int main()
{
	int viN;

	cout << "Enter the positive number of array elements: " << endl;
	cin >> viN;

	double vdMaxElement, vdMin, vdMax, *padArray = new double[viN];

	for (unsigned short i = 0; i < viN; i++)
	{
		cout << "Enter the element " << i + 1 << " of array: " << endl;
		cin >> padArray[i];
	}

	cout << "\nDelete the elements on an interval [a,b]";
	cout << "\nEnter the number a: ";
	cin >> vdMin;
	cout << "Enter the number b: ";
	cin >> vdMax;

	cout << "\nSum of positive numbers is " 
			<< fdMaxElement(vdMaxElement, padArray, viN) << endl;

	cout << "\nMaximum is " << vdMaxElement << endl;

	fvElementOfFinishArray(padArray, viN, vdMin, vdMax);

	delete[] padArray;

	return 0;
}