#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int** ReadMatrix(string, unsigned short&);
void PrintMatrix(int**, unsigned short);
bool SumNonNegativeCols(int**, unsigned short, unsigned long long&);
unsigned long long MinSecondaryDiagonalsSum(int**, unsigned short);

int main() {
    unsigned short order;
    int** matrix = ReadMatrix("Matrix.txt", order);
    if (!matrix) return 1;

    cout << "Matrix:\n";
    PrintMatrix(matrix, order);

    cout << "The sum of elements of non-negative matrix columns is: ";
    unsigned long long total_sum;
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

int** ReadMatrix(string file_name, unsigned short& order) {
    ifstream fin(file_name);
    if (!fin.is_open()) {
        cout << "\nCan't open file " << file_name << "!\n";
        return nullptr;
    }

    fin >> order;
    int** matrix = new int*[order];
    for (unsigned short i = 0; i < order; i++) {
        matrix[i] = new int[order];
        for (unsigned short j = 0; j < order; j++)
            fin >> matrix[i][j];
    }
    fin.close();
    return matrix;
}

void PrintMatrix(int** matrix, unsigned short order) {
    for (unsigned short i = 0; i < order; i++) {
        for (unsigned short j = 0; j < order; j++)
            cout << "\t" << matrix[i][j];
        cout << "\n\n";
    }
}

bool SumNonNegativeCols(int** matrix, unsigned short order,
    unsigned long long& total_sum) {

    total_sum = 0;
    bool non_negative_col_found = false;
    for (unsigned short j = 0; j < order; j++) {
        unsigned long long col_sum = 0;
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

unsigned long long MinSecondaryDiagonalsSum(int** matrix, unsigned short order) {
    unsigned long long minimum = abs(matrix[0][0]);
    for (short i = 1; i < order - 1; i++) {
        unsigned long long diag_sum = 0;
        for (short j = 0; j <= i; j++)
            diag_sum += abs(matrix[j][i - j]);

        if (diag_sum < minimum)
            minimum = diag_sum;
    }

    for (short i = 1; i < order; i++) {
        unsigned long long diag_sum = 0;
        for (short j = 0; j < (order - i); j++)
            diag_sum += abs(matrix[i + j][order - 1 - j]);

        if (diag_sum < minimum)
            minimum = diag_sum;
    }
    return minimum;
}