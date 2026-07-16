// Sets only take unique elements
#include <set> // Implemented as a self balancing red-black tree
#include <iostream>

int main()
{
	std::set<int> s;
	s.insert(1);

	for (auto elem : s)
	{
		std::cout << elem << '\n';
	}

	s.insert({ 1,2,3, -4}); // 1 will not be duplicate, and -4 will go the front.
	for (auto elem : s)
	{
		std::cout << elem << '\n';
	}

	std::cout << "====== Check if a value is present ====== " << std::endl;
	if (s.contains(-4))
	{
		std::cout << "The set contains -4" << std::endl;
	}
	else
	{
		std::cout << "The set does not contain -4" << std::endl;
	}
	std::cout << "====== Check if a value is present using iterator ====== " << std::endl;

	auto found = s.find(-4);
	if (found != s.end())
	{
		std::cout << "The set contains -4" << std::endl;
	}
	else
	{
		std::cout << "The set does not contain -4" << std::endl;
	}
	std::cout << "====== Erasing ====== " << std::endl;
	s.erase(-4);
	for (auto elem : s)
	{
		std::cout << elem << ", ";
	}
	std::cout << '\n';
	std::cout << "-4 has been removed" << '\n';
	
	
}