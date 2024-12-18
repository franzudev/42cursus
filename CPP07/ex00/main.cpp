#include "whatever.hpp"

/*int main() {
	int a[2] = {1, 2};
	int minimum = min<int>(a[0], a[1]);
	int maximum = max<int>(a[0], a[1]);

	swap<int>(&a[0], &a[1]);
	std::cout << a[0] << " " << a[1] << std::endl;
	std::cout << minimum << std::endl;
	std::cout << maximum << std::endl;
}*/


int main( void )
{
	int a = 2;
	int b = 3;
	TestClass aw1 = TestClass(10);
	TestClass aw2 = TestClass(25);

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	return 0;
}
