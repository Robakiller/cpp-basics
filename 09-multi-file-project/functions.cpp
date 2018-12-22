#include "functions.h"

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