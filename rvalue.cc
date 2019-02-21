#include <iostream>

int &foo()
{
	static int i;
	return i;
}

int main()
{
	foo() = 4;
	int *b = &foo();
	std::cout << *b << std::endl;
}