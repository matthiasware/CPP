#include <iostream>

int countBits(int a)
{
	int count = 0;
	while(a)
	{
		count++;
		a &= (a-1);
	}
}
int main()
{
	std::cout << countBits(0b111) << std::endl;
}