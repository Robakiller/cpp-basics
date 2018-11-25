#include "functions.h"

double fdMaxElement(double & vdMaxElement, double * padArray, int viN)
{
	double vdSum = 0, vdFinalPositive = -1;

	vdMaxElement = padArray[0];

	for (unsigned short i = 0; i < viN; i++)
	{
		if (padArray[i] > vdMaxElement)
			vdMaxElement = padArray[i];

		if (padArray[i] > 0)
			vdFinalPositive = i;
	}

	if (vdFinalPositive != -1)
		for (unsigned short i = 0; i < vdFinalPositive; i++)
			vdSum += padArray[i];

	return vdSum;
}

void fvElementOfFinishArray(double * padArray, int viN, double & vdMin, double & vdMax)
{
	for (unsigned short i = 0; i < viN; i++)
	{
		if ((padArray[i] >= vdMin) && (padArray[i] <= vdMax))
			padArray[i] = 0;
		cout << "The element " << i + 1 << " of array: " << padArray[i] << endl;
	}
}