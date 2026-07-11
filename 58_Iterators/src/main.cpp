#include <iostream>
#include <vector>

#include <unordered_map>

int main()
{
	std::vector<int> values = { 1,2,3,4,5,6 };

	for (int i = 0; i < values.size(); i++)
		std::cout << values[i] << '\n';

	for (int value : values)
		std::cout << value << '\n';

	
	for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
		std::cout << *it << '\n';

	using ScoreMap = std::unordered_map<std::string, int>;
	ScoreMap map; // For maps, you are sort of forced to use iterators.
	map["Adrian"] = 22;
	map["C++"] = 5;

	for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++)
	{
		auto& key = it->first;
		auto& value = it->second;
		std::cout << "Key: " << key << ", " << "Value: " << value << '\n';
	}

	std::cout << std::endl;

	for (auto kv : map)
	{
		auto& key = kv.first;
		auto& value = kv.second;
	}

	std::cout << std::endl;

	// Using structured bindings: C++17
	for (auto [key, value] : map)
	{
		std::cout << "Key: " << key << ", " << "Value: " << value << '\n';
	}




	std::cin.get();
}

/*
Iterators allow you to 'iterate' over a collection of elements.

Nowadays, you would simply use range based for loops:  for(Type value : values)

*/