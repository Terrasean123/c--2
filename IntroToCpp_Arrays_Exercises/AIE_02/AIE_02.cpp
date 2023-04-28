
#include <iostream>

int MinValue(const int* arr, int count);
int MaxValue(const int* arr, int count);
int CountOccurrencesOfValue(const int* arr, int count, int search);


int main(int argc, char** argv)
{
	const int NUM_NUMBERS = 10;
	int numbers[NUM_NUMBERS] = { 10, 20, 30, 40, 50, 10, 20, 30, 40, 50 };

	// In C++, an array is simply a pointer to the first value
	// when passing an array through a function parameter, we loose the length information
	// therefore we need to pass the array size in as well

	// implement the above methods
	// so that the expected output is printed to the console

	std::cout << "Expected: 10 - Got: " << MinValue(numbers, NUM_NUMBERS) << std::endl;
	std::cout << "Expected: 50 - Got: " << MaxValue(numbers, NUM_NUMBERS) << std::endl;
	std::cout << "Expected: 2 - Got: " << CountOccurrencesOfValue(numbers, NUM_NUMBERS, 10) << std::endl;
	std::cout << "Expected: 0 - Got: " << CountOccurrencesOfValue(numbers, NUM_NUMBERS, 8) << std::endl;

	return 0;
}


int MinValue(const int* arr, int count)
{
	int smallestValue;
	smallestValue = arr[0];

	for (int i = 0; i < count; i++)
	{
		if (smallestValue > arr[i])
		{
			smallestValue = arr[i];
		}
	}
	// TODO: loop through the array, return the smallest value
	return smallestValue;
}

int MaxValue(const int* arr, int count)
{
	int biggestValue;
	biggestValue = arr[0];

	for (int i = 0; i < count; i++)
	{
		if (biggestValue < arr[i])
		{
			biggestValue = arr[i];
		}
	}
	// TODO: loop through the array, return the largest value
	return biggestValue;
}

int CountOccurrencesOfValue(const int* arr, int count, int search)
{
	int valueOccurance = 0;

	for (int i = 0; i < count; i++)
	{
		if (arr[i]==search)
		{
			valueOccurance++;

		}

	}
	// TODO: loop through the array, return the number of times the search value occurs 
	return valueOccurance;
}

