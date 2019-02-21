#include <iostream>
#include "quicksort.h"
#include <vector>
#include <iterator>


template<typename T>
std::ostream &operator <<(std::ostream &os, const std::vector<T> &v) {
   os << "(";
   for(auto &e: v) os << e << ",";
   os << ")";
   return os;
}

int main()
{
	std::vector<int> v{1, 9, 8, 3, 4, 7, 2, 6, 5};
	std::cout << v << std::endl;
}
