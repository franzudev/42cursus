#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> nums = Array<int>(30);
	Array<int> mir(nums);
	for (int i = 0; i < 30; i++) {
		nums[i] = i;
		mir[i] = i;
	}
	std::cout << "Numbers: " << nums[10] << " | Mirror: " << mir[10] << std::endl;
	nums[10] = 52;
	std::cout << "Numbers: " << nums[10] << " | Mirror: " << mir[10] << std::endl;
	mir[10] = 23;
	std::cout << "Numbers: " << nums[10] << " | Mirror: " << mir[10] << std::endl << std::endl;
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
