#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void Log(const char* message);

int main()
{
	Log("Running test");
	cin.get();
	return 0;
}

// The preprocessor opens iostream, reads the file, and copies its content into this file.