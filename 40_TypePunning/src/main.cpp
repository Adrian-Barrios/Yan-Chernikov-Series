#include <iostream>

struct Entity
{
	int x, y;
};

int main()
{
	int a = 50; // Representation in memory (reversed):  32 00 00 00
	double b = a;  // Implicit conversion. Representation in memory (reversed): 00 00 00 00 00 00 49 40 
	double c = (double)a; // Explicit conversion. 
	std::cout << b << std::endl;

	// Type punning
	double d = *(double*)&a; // Memory address of 'a' casted into a double ptr and then dereferenced. d is now 32 00 00 00 cc cc cc cc
	std::cout << d << std::endl; // Problematic, this will not be 50.

	// Creating an array from a struct
	Entity e( 5, 8 );
	int* position = (int*)&e;

	int y = *(int*)((char*)&e +4); // Raw memory operations.no
	
	std::cout << position[0] << "," << position[1] << std::endl;

	std::cout << "y: " << y << std::endl;

	std::cin.get();
}