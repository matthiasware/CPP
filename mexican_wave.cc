#include<string>
#include<vector>
#include<iostream>

template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
	os << "(";
	for(auto e : v)
		os << e << ", ";
	os << ")";
	return os;
}

std::vector<std::string> wave(std::string crowd)
{
	std::vector<std::string> res;
	std::string head{""};
	std::string tail{crowd};
	for(auto current : crowd)
	{
		tail.erase(0, 1);
		if(current != ' ')
			res.push_back(head + (char) (current - 32) + tail);
		head.push_back(current);
	}
	return res;
}


int main()
{
	std::string crowd{"ab cde"};
	std::vector<std::string> waves = wave(crowd);
	std::cout << waves << std::endl;
}