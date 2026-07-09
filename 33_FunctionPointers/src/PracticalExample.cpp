#include <iostream>
#include <vector>

void Print(int x)
{
	std::cout << x << std::endl;
}

void Func(const std::vector<int>& vec, void(*do_something)(int))
{
	for (int value : vec)
	{
		do_something(value);
	}
}

int main()
{
	std::vector<int> vec = { 1,2,3,4,5,6 };
	Func(vec, Print);
}