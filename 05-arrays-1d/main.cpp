#include <iostream>
using namespace std;

void PrintArray(double*, const unsigned short);
double FindMaxElement(double*, const unsigned short);
short FindLastPositive(double*, const unsigned short);
void PrintSumBeforeLastPositive(double*, const unsigned short);
void CompressArray(double*, const unsigned short, double, double);

int main() {
    const unsigned short kArraySize = 10;
    cout << "The number of arr elements: " << kArraySize << endl;
    double arr[kArraySize] = { 3, .2, 0, .1, -6, .5, 1, -.2, -1, -4 };
    PrintArray(arr, kArraySize);

    cout << "\nMaximum is " << FindMaxElement(arr, kArraySize) << endl;

    PrintSumBeforeLastPositive(arr, kArraySize);

    double min, max;
    do {
        cout << "\nDelete the elements on an interval [a,b]";
        cout << "\nEnter the number a: ";
        cin >> min;
        cout << "Enter the number b (b >= a): ";
        cin >> max;
    } while (max < min);

    cout << "\nCompressed array:\n";
    CompressArray(arr, kArraySize, min, max);
    PrintArray(arr, kArraySize);

    return 0;
}

void PrintArray(double* arr, const unsigned short kArraySize) {
    for (unsigned short i = 0; i < kArraySize; i++)
        cout << "The element " << i + 1
        << " of array: " << arr[i] << endl;
}

double FindMaxElement(double* arr, const unsigned short kArraySize) {
    double max_element = arr[0];

    for (unsigned short i = 1; i < kArraySize; i++)
        if (arr[i] > max_element)
            max_element = arr[i];

    return max_element;
}

short FindLastPositive(double* arr, const unsigned short kArraySize) {
    for (short i = kArraySize - 1; i >= 0; i--)
        if (arr[i] > 0)
            return i;
    return -1;
}

void PrintSumBeforeLastPositive(double* arr, const unsigned short kArraySize) {
    cout << "\nSum of numbers before the last positive is: ";
    short last_positive = FindLastPositive(arr, kArraySize);
    if (last_positive != -1) {
        if (last_positive != 0) {
            double sum = 0.0;
            for (unsigned short i = 0; i < last_positive; i++)
                sum += arr[i];
            cout << sum << endl;
        }
        else {
            cout << "\nLast positive element is the first one!\n";
        }
    }
    else {
        cout << "\nThere are no positive numbers!\n";
    }
}

void CompressArray(double* arr, const unsigned short kArraySize, double min, double max) {
    int kept_numbers = kArraySize;

    for (unsigned short i = 0; i < kept_numbers;) {
        if ((arr[i] >= min) && (arr[i] <= max)) {
            kept_numbers--;
            for (unsigned short j = i; j < kept_numbers; j++)
                arr[j] = arr[j + 1];
            arr[kept_numbers] = 0.0;
        }
        else {
            i++;
        }
    }
}