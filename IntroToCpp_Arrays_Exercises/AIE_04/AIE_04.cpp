

#include <iostream>

void swap(int first, int second);
void SortArray(int* arr, int count);
bool IsArraySorted(const int* arr, int count);

int main(int argc, char** argv)
{
	const int NUM_ITEMS = 8;
	int numbers[NUM_ITEMS] = { 13, 1, 7, 5, 11, 9, 15, 3 };

	SortArray(numbers, NUM_ITEMS);

	// Test: all values should be sorted in ascending order
	if (IsArraySorted(numbers, NUM_ITEMS)) std::cout << "Pass: the array is sorted" << std::endl;
	else std::cout << "Fail: the array is not sorted" << std::endl;

	return 0;
}

bool IsArraySorted(const int* arr, int count)
{
	for (int i = 0; i < count - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}

void swap(int first, int second)
{
	int temp = 0;
	temp = second;
	second = first;
	first = temp;

}


void SortArray(int* arr, int count)
{

	for (int i = 0; i < count - 1; i++)
	{

		if (arr[i + 1] < arr[i])
		{

		}


	}
	for (int i = 0; i < count; i++)
	{
		std::cout << arr[i] << std::endl;

	}
	// TODO: 
	// modify the values in the array so that when this method returns
	// all values are sorted in ascending order
}
