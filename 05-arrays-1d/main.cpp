#include <iostream>

using namespace std;

int main()
{
	const unsigned short kArraySize = 10;

	cout << "The number of array elements: " << kArraySize << endl;

	double max_element, sum = 0.0, min, max, final_positive = -1.0,
		array[kArraySize] = {7.0, 0.0, 4.0, 3.0, -2.0, 9.0, 0.0, 2.0, -1.0, -3.0};

	for (unsigned short i = 0; i < kArraySize; i++)
	{
		cout << "The element " << i + 1 
			<< " of array: " << array[i] << endl;
	}

	max_element = array[0];

	for (unsigned short i = 0; i < kArraySize; i++)
		if (array[i] > max_element)
			max_element = array[i];

	cout << "\nMaximum is " << max_element << endl;

	for (unsigned short i = 0; i < kArraySize; i++)
		if (array[i] > 0)
			final_positive = i;

	if (final_positive != -1)
	{
		if (final_positive != 0)
		{
			for (unsigned short i = 0; i < final_positive; i++)
				sum += array[i];
			cout << "\nSum of numbers before last positive one is " << sum << endl;
		}
		else
			cout << "\nLast positive element is the first one!" << endl;
	}
	else
		cout << "There are not the positive numbers!" << endl;

	do
	{
		cout << "\nDelete the elements on an interval [a,b]";
		cout << "\nEnter the number a: ";
		cin >> min;
		cout << "Enter the number b (b >= a): ";
		cin >> max;
	} while (max < min);

	int kept_numbers = kArraySize;

	for (unsigned short i = 0; i < kept_numbers;)
	{
		if ((array[i] >= min) && (array[i] <= max))
		{
			kept_numbers--;
			for (unsigned short j = i; j < kept_numbers; j++)
				array[j] = array[j + 1];
			array[kept_numbers] = 0.0;
		}
		else 
			i++;
	}

	for (unsigned short i = 0; i < kArraySize; i++)
	{
		
		cout << "The element " << i + 1
				<< " of compressed array: " << array[i] << endl;
	}

	return 0;
}