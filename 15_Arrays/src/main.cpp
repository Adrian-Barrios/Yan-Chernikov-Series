#include <iostream>

int main()
{
	int example[5]; 
	int* ptr = example;
	example[0] = 10;
	example[2] = 5;

	// Array size
	int count = sizeof(example) / sizeof(int);

	std::cout << example[0] << std::endl;
	std::cout << *ptr << std::endl;
	*(ptr + 2) = 6;

	std::cout << example[2] << std::endl;

	// "====== Heap Allocated array ======

	int* another = new int[10];
	for (size_t i{ 0 }; i < 10; ++i)
	{
		another[i] = 2;
	}

	delete[] another;
}

// Size must be known at compile time.

// Garbage values if we only initialize.

// An array is just a pointer to a block of memory.

// We can use pointer arithmetic to access the elements in an array.

// The biggest use of allocating using 'new' is the life time. You pick how long it leaves for.

// std::array were included in C++11: Advantage is that it keeps track of our array and performs bounds checking.

// to get the size we can do something like: int count = sizeof(array) / sizeof(element_type)