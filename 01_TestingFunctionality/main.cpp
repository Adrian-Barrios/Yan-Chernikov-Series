#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void Log(const char* message)
{
	cout << message << endl;
}

int main()
{
	Log("Running test");
	cin.get();
	return 0;
}