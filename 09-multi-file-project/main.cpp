#include "functions.h"

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