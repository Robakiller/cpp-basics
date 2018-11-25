#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	unsigned short vusiOrder, vusiNumberOfPositive;
	unsigned int vuiPositiveSum = 0, vuiDiagSum = 0;

	fstream fMatrix("Matrix.txt");

	cout << "The order of matrix: ";
	fMatrix >> vusiOrder;
	cout << vusiOrder;

	int * * aiMatrix = new int * [vusiOrder];
		for (int i = 0; i < vusiOrder; i++)
			aiMatrix[i] = new int[vusiOrder];

	for (short i1 = 0; i1 < vusiOrder; i1++)
		for (short i2 = 0; i2 < vusiOrder; i2++)
		{
			fMatrix >> aiMatrix[i1][i2];
		}

	fMatrix.close();

	cout << "\nEntered matrix:\n" << endl;

	for (short i1 = 0; i1 < vusiOrder; i1++)
	{
		for (short i2 = 0; i2 < vusiOrder; i2++)
		{
			cout << "\t" << aiMatrix[i1][i2];
		}

		cout << "\n\n";
	}

	for (short i2 = 0; i2 < vusiOrder; i2++)
	{
		vusiNumberOfPositive = 0;

		for (short i1 = 0; i1 < vusiOrder; i1++)
		{
			if (aiMatrix[i1][i2] >= 0)
				vusiNumberOfPositive++;
		}

		if (vusiNumberOfPositive == vusiOrder)
		{
			for (short i = 0; i < vusiOrder; i++)
				vuiPositiveSum += aiMatrix[i][i2];
		}
	}

	cout << "\nThe sum of elements of positive matrix column is " 
			<< vuiPositiveSum << endl;

	unsigned int vuiMinimum = abs(aiMatrix[1][0]) + abs(aiMatrix[0][1]);
	
	for (short i1 = 1; i1 < vusiOrder - 1; i1++)
	{
		vuiDiagSum = 0;

		for (short i2 = 0; (i2 <= i1) && (i2 < vusiOrder); i2++)
			vuiDiagSum += abs(aiMatrix[i2][i1 - i2]);

		if (vuiDiagSum < vuiMinimum)
			vuiMinimum = vuiDiagSum;
	}
	
	for (short i1 = 1; i1 < vusiOrder - 1; i1++)
	{
		vuiDiagSum = 0;

		for (short i2 = 0; i2 < (vusiOrder - i1); i2++)
			vuiDiagSum += abs(aiMatrix[i1 + i2][vusiOrder - 1 - i2]);

		if (vuiDiagSum < vuiMinimum)
			vuiMinimum = vuiDiagSum;
	}

	cout << "\nThe minimum of sum of modules of matrix diagonal elements is " 
			<< vuiMinimum << endl;

	for (int i = 0; i < vusiOrder; i++)
	{
		delete[] aiMatrix[i];
	}

	delete[] aiMatrix;

	return 0;
}