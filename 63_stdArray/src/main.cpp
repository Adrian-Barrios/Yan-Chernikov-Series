#include <array> // C++11
#include <iostream>
#include <algorithm>

// When passed into functions, c style arrays decay into pointers. Not std::arrays

void PrintElements(std::array<int, 2> params) // Size has to match
{
	std::cout << params[0] << ", " << params[1];
}

void legacyCCodebase(int*, int size)
{ }

int main() {
	std::array<int, 2> arr = { 1,2 };
	for (int i{}; i < arr.size(); ++i)
	{
		std::cout << arr[i] << '\n';
	}
	//std::cout << arr[2]; // Will access memory outside of capcity unless in debug mode.
	//std::cout << arr.at(2);  // Bounds checked

	PrintElements(arr);

	for (auto elem : arr)
	{
		std::cout << elem << '\n';
	}

	// Sorting
	std::array<int, 5> arr2 = { 10,2,12,32,1 };
	std::sort(arr2.begin(),arr2.end());
	std::cout << '\n';

	std::cout << "Sorted: ";
	for (auto elem : arr2)
	{
		std::cout << elem << ", ";
	}

	legacyCCodebase(arr.data(), arr.size()); // .data() if the function takes a pointer


}