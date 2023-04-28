
#include <iostream>

int main(int argc, char** argv)
{
	const int NUM_NUMBERS = 5;
	int numbers[NUM_NUMBERS] = { 10, 20, 30, 40, 50 };
	int input = 0;
	std::cout << " press one normal and 2 for reverse" << std::endl;
	std::cin >> input;

	if (input == 1)
	{
		std::cout << "normal order" << std::endl;

		for (int i = 0; i < NUM_NUMBERS; i++)
		{

			std::cout << numbers[i] << "," << std::endl;

		}
	}
	if (input == 2)
	{
		std::cout << "reverse order" << std::endl;
		for (int i = NUM_NUMBERS - 1; i > 0 - 1; i--)
		{

			std::cout << numbers[i] << "," << std::endl;

		}
	}




}
