#include <iostream>
#include <string>

using namespace std::string_literals; // for things like "string"s, which turns a cstyle string into a std::string

int main()
{
	// GENERAL IDEA

	std::string MY_STRING = std::string("SOME STRING ") + "Plus Something else";
	std::string MY_OTHER_STRING = "SOME OTHER STRING "s + "Plus Something else";
	bool contains = MY_STRING.find("Something") != std::string::npos;

	const char* MULTI_LINE_STRING = R"(line 1
line 2
line 3
line 4)";

	MY_STRING[0] = 'T';
	int string_size = MY_STRING.size();

	std::cout << MY_STRING << std::endl;

	// UNDERLYING CHARACTERS (BUILDING BLOCKS OF STRINGS)

	char MY_CHAR = 'c';
	MY_CHAR = 'i';

	std::cout << MY_CHAR << std::endl;

	// C-Style String

	const char* MY_NAME = "ADRIAN"; // no need to call delete
	MY_NAME = "SOMETHING ELSE"; // I can change it entirely, but not the specific chars

	std::cout << MY_NAME << std::endl;

	// Array Representation

	char MY_NAME_2[6] = { 'H', 'e', 'l', 'l', 'o', '\0'}; // We need this null terminator explicitly declared if we do things this way.
	std::cout << strlen(MY_NAME_2) << std::endl; // Will be 5, length is not the same as size.
	std::cout << MY_NAME_2 << std::endl;
}