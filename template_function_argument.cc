#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <chrono>

template<typename T,
		     typename U,
		     void sorter(U u1, U u2)>
void call_sort(std::vector<T> v) {
   sorter(v.begin(), v.end());
}


int main()
{
	std::vector<int> v1(10'000'000);
	std::vector<int> v2(10'000'000);

	std::transform(v1.begin(), v1.end(), v1.begin(), [](auto _ ){return rand();});
	std::transform(v2.begin(), v2.end(), v2.begin(), [](auto _ ){return rand();});

    auto start = std::chrono::high_resolution_clock::now();
		call_sort<int, std::vector<int>::iterator, std::sort>(v1);
	auto diff = std::chrono::high_resolution_clock::now() - start;
	std::cout << diff.count() << std::endl;

	start = std::chrono::high_resolution_clock::now();
		std::sort(v2.begin(), v2.end());
	diff = std::chrono::high_resolution_clock::now() - start;
	std::cout << diff.count() << std::endl;
}