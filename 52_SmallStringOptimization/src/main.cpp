#include <iostream>
#include <string>

void* operator new(size_t size)
{
	std::cout << "Allocated: " << size << " bytes.\n";
	return malloc(size);
}

int main()
{
	std::string name = "Adrian"; // Will just be stored in a statically allocated buffer (in release mode).

	std::cin.get();
}


/*
Strings tend to allocate memory.
What is considered as a 'small string' is not fixed. In Visual Studio 2019, it is 15 characters (so 15 bytes).
*/