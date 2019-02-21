#include <iostream>

void foo(int&& x)
{
	int i = x;
}

int main()
{
	foo(5);
	int x{2};
	foo(x);
}