#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	unsigned short order;

	fstream file_matrix("Matrix.txt");

	if (!file_matrix)
	{
		cout << "Error opening file" << endl;
		return 1;
	}

	cout << "The order of matrix: ";
	file_matrix >> order;
	cout << order;

	int * * matrix = new int * [order];
		for (int i = 0; i < order; i++)
			matrix[i] = new int[order];

	for (short i1 = 0; i1 < order; i1++)
		for (short i2 = 0; i2 < order; i2++)
		{
			file_matrix >> matrix[i1][i2];
		}

	file_matrix.close();

	cout << "\nEntered matrix:\n" << endl;

	for (short i1 = 0; i1 < order; i1++)
	{
		for (short i2 = 0; i2 < order; i2++)
		{
			cout << "\t" << matrix[i1][i2];
		}

		cout << "\n\n";
	}

	unsigned short number_of_positive;
	unsigned int positive_sum = 0, diag_sum = 0;

	for (short i2 = 0; i2 < order; i2++)
	{
		number_of_positive = 0;

		for (short i1 = 0; i1 < order; i1++)
		{
			if (matrix[i1][i2] >= 0)
				number_of_positive++;
		}

		if (number_of_positive == order)
		{
			for (short i = 0; i < order; i++)
				positive_sum += matrix[i][i2];
		}
	}

	cout << "\nThe sum of elements of positive matrix column is " 
			<< positive_sum << endl;

	unsigned int minimum = abs(matrix[1][0]) + abs(matrix[0][1]);
	
	for (short i1 = 1; i1 < order - 1; i1++)
	{
		diag_sum = 0;

		for (short i2 = 0; (i2 <= i1) && (i2 < order); i2++)
			diag_sum += abs(matrix[i2][i1 - i2]);

		if (diag_sum < minimum)
			minimum = diag_sum;
	}
	
	for (short i1 = 1; i1 < order - 1; i1++)
	{
		diag_sum = 0;

		for (short i2 = 0; i2 < (order - i1); i2++)
			diag_sum += abs(matrix[i1 + i2][order - 1 - i2]);

		if (diag_sum < minimum)
			minimum = diag_sum;
	}

	cout << "\nThe minimum of sum of modules of matrix diagonal elements is " 
			<< minimum << endl;

	for (int i = 0; i < order; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;

	return 0;
}