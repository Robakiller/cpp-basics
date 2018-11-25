#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <typename ttMatrixDataType>
short tfsiMatrixOperation(const unsigned short, string);

template <typename ttMatrixDataType>
void tfvFirstTask(const unsigned short, ttMatrixDataType * *);

template <typename ttMatrixDataType>
void tfvSecondTask(const unsigned short, ttMatrixDataType * *);

int main()
{
	const unsigned short cvusiOrder = 3;
	unsigned short vusiMatrixDataType;

	cout << "The data type of matrix (0 - float, 1 - integer, 2 - double): ";
	cin >> vusiMatrixDataType;

	switch (vusiMatrixDataType)
	{
		case 0: tfsiMatrixOperation<float>(cvusiOrder, "float"); break;
		case 1: tfsiMatrixOperation<int>(cvusiOrder, "int"); break;
		case 2: tfsiMatrixOperation<double>(cvusiOrder, "double"); break;
	}

	return 0;
}

template <typename ttMatrixDataType>
short tfsiMatrixOperation(const unsigned short cvusiOrder, string vsMatrixDataType)
{
	ifstream fMatrix(vsMatrixDataType + "Matrix.txt");

	if (!fMatrix)
	{
		cout << "Error opening file" << endl;
		return 1;
	}

	ttMatrixDataType * * attMatrix = new ttMatrixDataType *[cvusiOrder];
	for (short i = 0; i < cvusiOrder; i++)
		attMatrix[i] = new ttMatrixDataType[cvusiOrder];

	for (short i1 = 0; i1 < cvusiOrder; i1++)
		for (short i2 = 0; i2 < cvusiOrder; i2++)
		{
			fMatrix >> attMatrix[i1][i2];
		}

	cout << "\nEntered matrix:\n" << endl;

	for (short i1 = 0; i1 < cvusiOrder; i1++)
	{
		for (short i2 = 0; i2 < cvusiOrder; i2++)
		{
			cout << "\t" << attMatrix[i1][i2];
		}

		cout << "\n\n";
	}

	fMatrix.close();

	tfvFirstTask<ttMatrixDataType>(cvusiOrder, attMatrix);
	tfvSecondTask<ttMatrixDataType>(cvusiOrder, attMatrix);

	for (int i = 0; i < cvusiOrder; i++)
	{
		delete[] attMatrix[i];
	}

	delete[] attMatrix;

	return 0;
}

template <typename ttMatrixDataType>
void tfvFirstTask(const unsigned short cvusiOrder, ttMatrixDataType * * attMatrix)
{
	unsigned short vusiNumberOfPositive;
	ttMatrixDataType vttPositiveSum = 0;

	for (short i2 = 0; i2 < cvusiOrder; i2++)
	{
		vusiNumberOfPositive = 0;

		for (short i1 = 0; i1 < cvusiOrder; i1++)
		{
			if (attMatrix[i1][i2] >= 0)
				vusiNumberOfPositive++;
		}

		if (vusiNumberOfPositive == cvusiOrder)
		{
			for (short i = 0; i < cvusiOrder; i++)
				vttPositiveSum += attMatrix[i][i2];
		}
	}

	cout << "\nThe sum of elements of positive matrix column is " 
			<< vttPositiveSum << endl;
}

template <typename ttMatrixDataType>
void tfvSecondTask(const unsigned short cvusiOrder, ttMatrixDataType * * attMatrix)
{
	ttMatrixDataType vttMinimum = abs(attMatrix[1][0]) + abs(attMatrix[0][1]), 
						vttDiagSum = 0;

	for (short i1 = 1; i1 < cvusiOrder - 1; i1++)
	{
		vttDiagSum = 0;

		for (short i2 = 0; (i2 <= i1) && (i2 < cvusiOrder); i2++)
			vttDiagSum += abs(attMatrix[i2][i1 - i2]);

		if (vttDiagSum < vttMinimum)
			vttMinimum = vttDiagSum;
	}

	for (short i1 = 1; i1 < cvusiOrder - 1; i1++)
	{
		vttDiagSum = 0;

		for (short i2 = 0; i2 < (cvusiOrder - i1); i2++)
			vttDiagSum += abs(attMatrix[i1 + i2][cvusiOrder - 1 - i2]);

		if (vttDiagSum < vttMinimum)
			vttMinimum = vttDiagSum;
	}

	cout << "\nThe minimum of sum of modules of matrix diagonal elements is " 
			<< vttMinimum << endl;
}