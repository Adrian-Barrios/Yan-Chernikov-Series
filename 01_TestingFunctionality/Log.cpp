#include <iostream>

void Log(const char* message)
{
	std::cout << message << std::endl;
}

// Every C++ file results in a obj.
// A translation unit results in an object file.
// Headers have a lot of stuff in them, and can make your files larger than necessary.