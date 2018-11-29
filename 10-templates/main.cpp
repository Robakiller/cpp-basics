#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <typename MatrixDataType>
short OperateMatrix(const unsigned short, string);

template <typename MatrixDataType>
MatrixDataType DoFirstTask(const unsigned short, MatrixDataType**);

template <typename MatrixDataType>
MatrixDataType DoSecondTask(const unsigned short, MatrixDataType**);

int main() {
	const unsigned short kOrder = 3;
	unsigned short matrix_data_type;

data_type_entry:
	cout << "The data type of matrix (0 - float, 1 - integer, 2 - double): ";
	cin >> matrix_data_type;

	switch (matrix_data_type) {
		case 0: OperateMatrix<float>(kOrder, "float"); break;
		case 1: OperateMatrix<int>(kOrder, "int"); break;
		case 2: OperateMatrix<double>(kOrder, "double"); break;
		default: cout << "Please, enter the correct number of the data type of matrix!\n\n"; goto data_type_entry;
	}

	return 0;
}

template <typename MatrixDataType>
short OperateMatrix(const unsigned short kOrder, string matrix_data_type) {
	ifstream file_matrix(matrix_data_type + "Matrix.txt");

	if (!file_matrix) {
		cout << "Error opening file" << endl;
		return 1;
	}

	MatrixDataType** matrix = new MatrixDataType*[kOrder];
	for (short i = 0; i < kOrder; i++)
		matrix[i] = new MatrixDataType[kOrder];

	for (short i1 = 0; i1 < kOrder; i1++)
		for (short i2 = 0; i2 < kOrder; i2++) {
			file_matrix >> matrix[i1][i2];
		}

	cout << "\nEntered matrix:\n" << endl;

	for (short i1 = 0; i1 < kOrder; i1++) {
		for (short i2 = 0; i2 < kOrder; i2++) {
			cout << "\t" << matrix[i1][i2];
		}

		cout << "\n\n";
	}

	file_matrix.close();

	cout << "\nThe sum of elements of positive matrix column is "
			<< DoFirstTask<MatrixDataType>(kOrder, matrix) << endl;
	
	cout << "\nThe minimum of sum of modules of matrix diagonal elements is "
			<< DoSecondTask<MatrixDataType>(kOrder, matrix) << endl;

	for (int i = 0; i < kOrder; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;

	return 0;
}

template <typename MatrixDataType>
MatrixDataType DoFirstTask(const unsigned short kOrder, MatrixDataType** matrix) {
	unsigned short number_of_positive;
	MatrixDataType positive_sum = 0;

	for (short i2 = 0; i2 < kOrder; i2++) {
		number_of_positive = 0;

		for (short i1 = 0; i1 < kOrder; i1++) {
			if (matrix[i1][i2] >= 0)
				number_of_positive++;
		}

		if (number_of_positive == kOrder) {
			for (short i = 0; i < kOrder; i++)
				positive_sum += matrix[i][i2];
		}
	}

	return positive_sum;
}

template <typename MatrixDataType>
MatrixDataType DoSecondTask(const unsigned short kOrder, MatrixDataType** matrix) {
	MatrixDataType minimum = abs(matrix[1][0]) + abs(matrix[0][1]), 
						diag_sum = 0;

	for (short i1 = 1; i1 < kOrder - 1; i1++) {
		diag_sum = 0;

		for (short i2 = 0; (i2 <= i1) && (i2 < kOrder); i2++)
			diag_sum += abs(matrix[i2][i1 - i2]);

		if (diag_sum < minimum)
			minimum = diag_sum;
	}

	for (short i1 = 1; i1 < kOrder - 1; i1++) {
		diag_sum = 0;

		for (short i2 = 0; i2 < (kOrder - i1); i2++)
			diag_sum += abs(matrix[i1 + i2][kOrder - 1 - i2]);

		if (diag_sum < minimum)
			minimum = diag_sum;
	}

	return minimum;
}