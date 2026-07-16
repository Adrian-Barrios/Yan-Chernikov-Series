// Introduced in C++20
#include <span>
#include <iostream>
#include <array>
// A span is a view into a container.

void PrintArray(std::span<int> arr)
{
	if (arr.extent == std::dynamic_extent)
	{
		std::cout << "dynamic extent" << std::endl;
	}
	else
	{
		std::cout << "static extent" << std::endl;
	}
	for (auto& elem : arr)
	{
		std::cout << elem << ", ";
	}
}

int main()
{
	std::array<int, 10> a = { 1,2,3,4,5,6,7,8,9,10 };
	PrintArray(a);
	std::cout << '\n';
	std::span mySpan{a};
	std::cout << "Span extent: " << mySpan.extent <<  std::endl;

	std::cout << "====== Setting an extent of 3 for the span =====" << std::endl;
	PrintArray(std::span(a.begin(), 3));


}