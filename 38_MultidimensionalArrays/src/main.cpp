#include <iostream>

int main()
{
	int* array = new int[50];

	int** a2d = new int* [50]; 

	for (int i = 0; i < 50; i++)
	{
		a2d[i] = new int[50]; // Allocating 50 arrays (in random places in memory), and the location of each of their first elements is in a2d.
	}

	a2d[0][0] = 10;

	for (int i = 0; i < 50; i++)
	{
		delete[] a2d[i];
	}

	delete[] a2d;

	std::cin.get();
}

// Cons: Cache misses since the allocated arrays are in random places in memory (not likely in the same address block.