#include <iostream>

void Increment(int value)
{
	value++;
	std::cout << "Value inside function: " << value << std::endl;
}

void IncrementByReference(int& value)
{
	value++;
	std::cout << "Value inside function: " << value << std::endl;
}


int main()
{
	int a = 10;
	int& b = a;
	b = 2;
	std::cout << "=====Pass by Value=====" << std::endl;
	std::cout << "Value outside: " << a << std::endl;
	Increment(a);
	std::cout << "Value outside: " << a << std::endl;

	std::cout << "=====Pass by Reference====" << std::endl;
	std::cout << "Value outside: " << a << std::endl;
	IncrementByReference(a);
	std::cout << "Value outside: " << a << std::endl;

	return 0;
}

// Also known as an alias. It is not really a variable, it just exists in our source code. Only 'a' exists.

// b is a, so if we change b, then a is also changed.