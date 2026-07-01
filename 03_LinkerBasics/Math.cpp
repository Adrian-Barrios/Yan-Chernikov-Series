#include <iostream>
#include "Log.h"

static int r = 10;

int main()
{
	int a = 8;
	a++;
	const char* string = "Hello";

	for (int i = 0; i < 5; ++i)
	{
		const char c = string[i];
		std::cout << c << std::endl;
	}

	Log("Debugging");
	std::cin.get();
}

/*
F9 sets a breakpoint in the line you are currently on.
 */ 