#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	/*Array<int> numbers = Array<int>(30);
	Array<int> mirror(numbers);
	std::cout << numbers[3] << std::endl;
	for (int i = 0; i < 30; i++) {
		numbers[i] = i;
		mirror[i] = i;
	}
	std::cout << "Numbers: " << numbers[10] << " | Mirror: " << mirror[10] << std::endl;
	numbers[10] = 52;
	std::cout << "Numbers: " << numbers[10] << " | Mirror: " << mirror[10] << std::endl;
	mirror[10] = 23;
	std::cout << "Numbers: " << numbers[10] << " | Mirror: " << mirror[10] << std::endl;*/
	Array<int> test;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;
}
