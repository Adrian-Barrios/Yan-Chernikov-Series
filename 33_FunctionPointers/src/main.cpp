#include <iostream>

void Func(int x)
{
	std::cout << "Value: " << x << std::endl;
}

int main()
{
	// Using 'auto'
	auto FUNCTION_VARIABLE = Func; // Wee are not calling here. We are getting the function pointer.
	FUNCTION_VARIABLE(10);

	// Using the actual type
	void(*function)(int) = Func;

	function(20);

	// Using typedef
	typedef void(*PrintFunction)(int);
	PrintFunction typedef_function = Func;
	typedef_function(30);
}



/*

Function pointers are a way to assign a function to a variable.

Functions are CPU instructions. So a function pointer is the address of those instructions.

*/