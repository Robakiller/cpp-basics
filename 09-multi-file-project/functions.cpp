#include "functions.h"

double FindMaxElement(double* array, const unsigned short kArraySize) {
	double max_element = array[0];

	for (unsigned short i = 0; i < kArraySize; i++)
		if (array[i] > max_element)
			max_element = array[i];

	return max_element;
}


void WriteSumBeforeLastPositive(double* array, const unsigned short kArraySize) {
	double final_positive = -1.0, sum = 0.0;

	for (unsigned short i = 0; i < kArraySize; i++)
		if (array[i] > 0)
			final_positive = i;

	if (final_positive != -1) {
		if (final_positive != 0) {
			for (unsigned short i = 0; i < final_positive; i++)
				sum += array[i];
			cout << "\nSum of numbers before last positive one is " << sum << endl;
		}
		else {
			cout << "\nLast positive element is the first one!" << endl;
		}
	}
	else {
		cout << "\nThere are not the positive numbers!" << endl;
	}
}

void WriteElementsOfFinishArray(double* array, const unsigned short kArraySize, double min, double max) {
	int kept_numbers = kArraySize;

	for (unsigned short i = 0; i < kept_numbers;) {
		if ((array[i] >= min) && (array[i] <= max)) {
			kept_numbers--;
			for (unsigned short j = i; j < kept_numbers; j++)
				array[j] = array[j + 1];
			array[kept_numbers] = 0.0;
		}
		else {
			i++;
		}
	}

	cout << endl;

	for (unsigned short i = 0; i < kArraySize; i++) {
		cout << "The element " << i + 1
			<< " of compressed array: " << array[i] << endl;
	}
}