//
// Created by Federico François on 20/05/21.
//

#include <iostream>

void memoryLeak()
{
	std::string panther = "String panther";
	std::cout << panther << std::endl;
}

int main()
{
	memoryLeak();
	return 0;
}