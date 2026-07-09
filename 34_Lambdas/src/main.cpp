#include <iostream>
#include <vector>
#include <algorithm>

void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
	{
		func(value);
	}
}


int main()
{
	std::vector<int> values = { 1,5,6,7,8 };
	auto lambda = [](int value) {std::cout << value << std::endl;}f;
	ForEach(values, lambda);

}

/*
Disposable/anonymous functions.
*/