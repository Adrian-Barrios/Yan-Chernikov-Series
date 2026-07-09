#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{
	for (int value : values)
	{
		func(value);
	}
}


int main()
{
	std::vector<int> values = { 1,5,6,7,8 };
	auto it = std::find_if(values.begin(), values.end(), [](int value) {return value > 3;});
	std::cout << *it << std::endl;
	int a = 10;
	auto lambda = [=](int value) mutable {a = 5; std:: cout << value << std::endl;};
	ForEach(values, lambda);

}

/*
Disposable/anonymous functions.
*/