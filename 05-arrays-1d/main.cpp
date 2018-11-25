#include <iostream>

using namespace std;

int main()
{
	const unsigned short cvusiN = 10;

	cout << "The number of array elements: " << cvusiN << endl;

	double vdMaxElement, vdSum = 0, vdMin, vdMax, vdFinalPositive = -1,
		padArray[cvusiN] = {7, 0, 4, 3, -2, 9, 0, 2, -1, -3};

	for (unsigned short i = 0; i < cvusiN; i++)
	{
		cout << "The element " << i + 1 
			<< " of array: " << padArray[i] << endl;
	}

	vdMaxElement = padArray[0];

	for (unsigned short i = 0; i < cvusiN; i++)
	{
		if (padArray[i] > vdMaxElement)
			vdMaxElement = padArray[i];

		if (padArray[i] > 0)
			vdFinalPositive = i;
	}

	if (vdFinalPositive != -1)
		for (unsigned short i = 0; i < vdFinalPositive; i++)
			vdSum += padArray[i];

	cout << "\nDelete the elements on an interval [a,b]";
	cout << "\nEnter the number a: ";
	cin >> vdMin;
	cout << "Enter the number b: ";
	cin >> vdMax;

	for (unsigned short i = 0; i < cvusiN; i++)
	{
		if ((padArray[i] >= vdMin)&&(padArray[i] <= vdMax))
			padArray[i] = 0;
		cout << "The element " << i + 1 
			<< " of array: " << padArray[i] << endl;
	}

	cout << "\nMaximum is " << vdMaxElement << endl;
	cout << "\nSum of numbers before last positive one is " << vdSum << endl;

	return 0;
}