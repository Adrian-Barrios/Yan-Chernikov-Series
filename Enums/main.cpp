#include <iostream>

enum Levels
{
	first = 1,
	second,
	third
};

int main()
{
	int result = Levels::first + Levels::second;
	std::cout << result << std::endl;

}