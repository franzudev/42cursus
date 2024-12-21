#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *p_str = &str;
	std::string& r_str = str;

	std::cout << *p_str << std::endl << r_str << std::endl;
}