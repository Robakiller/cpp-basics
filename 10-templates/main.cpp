#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename MatrixDataType>
MatrixDataType** ReadMatrix(string, unsigned short&);

template <typename MatrixDataType>
void PrintMatrix(MatrixDataType**, unsigned short);

template <typename MatrixDataType>
bool SumNonNegativeCols(MatrixDataType**, unsigned short, MatrixDataType&);

template <typename MatrixDataType>
MatrixDataType MinSecondaryDiagonalsSum(MatrixDataType**, unsigned short);

template <typename MatrixDataType>
short OperateMatrix(string);

int main() {
    string matrix_data_type;
data_type_entry:
    cout << "The data type of matrix (0 - integer, 1 - float, 2 - double): ";
    cin >> matrix_data_type;
    if (matrix_data_type == "0") {
        OperateMatrix<int>("intMatrix.txt");
    }
    else if (matrix_data_type == "1") {
        OperateMatrix<float>("floatMatrix.txt");
    }
    else if (matrix_data_type == "2") {
        OperateMatrix<double>("doubleMatrix.txt");
    }
    else {
        cout << "Please, enter the correct data type of matrix!\n\n";
        goto data_type_entry;
    }

    return 0;
}

template <typename MatrixDataType>
short OperateMatrix(string file_name) {
    unsigned short order;
    MatrixDataType** matrix = ReadMatrix<MatrixDataType>(file_name, order);
    if (!matrix) return 1;

    cout << "Matrix:\n";
    PrintMatrix(matrix, order);

    cout << "The sum of elements of non-negative matrix columns is: ";
    MatrixDataType total_sum;
    if (SumNonNegativeCols(matrix, order, total_sum))
        cout << total_sum << endl;
    else
        cout << "\nNo non-negative columns were found.\n";

    cout << "\nThe minimum among the sums of modules of elements of the\n";
    cout << "diagonals parallel to the secondary diagonal of the matrix: ";
    cout << MinSecondaryDiagonalsSum(matrix, order) << endl;

    for (unsigned short i = 0; i < order; i++) delete[] matrix[i];
    delete[] matrix;

    return 0;
}

template <typename MatrixDataType>
MatrixDataType** ReadMatrix(string file_name, unsigned short& order) {
    ifstream fin(file_name);
    if (!fin.is_open()) {
        cout << "\nCan't open file " << file_name << "!\n";
        return nullptr;
    }

    fin >> order;
    MatrixDataType** matrix = new MatrixDataType*[order];
    for (unsigned short i = 0; i < order; i++) {
        matrix[i] = new MatrixDataType[order];
        for (unsigned short j = 0; j < order; j++)
            fin >> matrix[i][j];
    }
    fin.close();
    return matrix;
}

template <typename MatrixDataType>
void PrintMatrix(MatrixDataType** matrix, unsigned short order) {
    for (unsigned short i = 0; i < order; i++) {
        for (unsigned short j = 0; j < order; j++)
            cout << "\t" << matrix[i][j];
        cout << "\n\n";
    }
}

template <typename MatrixDataType>
bool SumNonNegativeCols(MatrixDataType** matrix, unsigned short order,
    MatrixDataType& total_sum) {

    total_sum = 0;
    bool non_negative_col_found = false;
    for (unsigned short j = 0; j < order; j++) {
        MatrixDataType col_sum = 0;
        for (unsigned short i = 0; i < order; i++) {
            if (matrix[i][j] < 0) {
                col_sum = 0;
                break;
            }
            else {
                col_sum += matrix[i][j];
            }

            if (i == order - 1)
                non_negative_col_found = true;
        }
        total_sum += col_sum;
    }

    return non_negative_col_found;
}

template <typename MatrixDataType>
MatrixDataType MinSecondaryDiagonalsSum(MatrixDataType** matrix, unsigned short order) {
    MatrixDataType minimum = abs(matrix[0][0]);
    for (short i = 1; i < order - 1; i++) {
        MatrixDataType diag_sum = 0;
        for (short j = 0; j <= i; j++)
            diag_sum += abs(matrix[j][i - j]);

        if (diag_sum < minimum)
            minimum = diag_sum;
    }

    for (short i = 1; i < order; i++) {
        MatrixDataType diag_sum = 0;
        for (short j = 0; j < (order - i); j++)
            diag_sum += abs(matrix[i + j][order - 1 - j]);

        if (diag_sum < minimum)
            minimum = diag_sum;
    }
    return minimum;
}