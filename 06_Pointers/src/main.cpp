#include <iostream>

int main()
{
	int var = 8;
	void* ptr = &var;
	std::cout << ptr << std::endl;
}

// A pointer is just an integer that holds a memory address. Types are completely meaningless.

// 0 is an invalid memory address. This means that this pointer is not valid.

// = NULL is also an option, it is a #define.