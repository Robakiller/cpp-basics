#include "functions.h"

int main() {
	const unsigned short kArraySize = 10;

	cout << "The number of array elements: " << kArraySize << endl;

	double min, max,
		array[kArraySize] = { 3.0, 2.0, 0.0, 12.0, -6.0, 5.0, 1.0, -2.0, -1.0, -4.0 };

	for (unsigned short i = 0; i < kArraySize; i++)
		cout << "The element " << i + 1
				<< " of array: " << array[i] << endl;

	cout << "\nMaximum is " << FindMaxElement(array, kArraySize) << endl;

	WriteSumBeforeLastPositive(array, kArraySize);

	do {
		cout << "\nDelete the elements on an interval [a,b]";
		cout << "\nEnter the number a: ";
		cin >> min;
		cout << "Enter the number b (b >= a): ";
		cin >> max;
	} while (max < min);

	WriteElementsOfFinishArray(array, kArraySize, min, max);

	return 0;
}