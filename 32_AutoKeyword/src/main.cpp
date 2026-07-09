#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<std::string> strings;
	strings.push_back("First");
	strings.push_back("Second");

	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	for (auto it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	for (const auto& string : strings)
	{
		std::cout << string << std::endl;
	}
}