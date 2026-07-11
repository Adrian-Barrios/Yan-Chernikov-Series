#include <iostream>
#include <string>

// String view came in C++17 (basically a const char* to existing text)

static uint32_t s_AllocCount = 0;

void* operator new(size_t size) 
{
	s_AllocCount++;
	std::cout << "Allocating: " << size << " bytes\n";
	return malloc(size);
}

void PrintName(const std::string& s)
{
	std::cout << s << std::endl;
}

void PrintViewName(std::string_view s)
{
	std::cout << s << std::endl;
}

int main()
{
#if 0 
	std::string name = "Adrian Barrios"; // 1 allocation in debug mode
	std::string firstName = name.substr(0, 6); // 2nd allocation
	std::string lastName = name.substr(7, 14); // 3rd allocation
	std::cout << s_AllocCount << " allocations" << std::endl;

#else 
	const char* nameForView = "Adrian Barrios"; // We use this for string views. No allocation
	std::string_view firstNameView(nameForView, 6); // no allocation
	std::string_view lastNameView(nameForView + 7, 14); // no allocation
	std::cout << s_AllocCount << " allocations" << std::endl;

#endif

	

	std::cin.get();
}