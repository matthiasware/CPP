#include <iostream>
int main()
{
	int a = 2;
	int b = (a >> 31) * -1 * a;
	std::cout << a << " -> " << b << std::endl;
}