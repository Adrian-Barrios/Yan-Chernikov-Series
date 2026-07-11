#include <iostream>

int GetValue()
{
	return 1;
}
int& GetLvalueRef()
{
	static int value = 10;
	return value;
}

void SetLValueRef(const int& val)
{

}

void PrintName(const std::string& s)
{
	std::cout << s << std::endl;
}

void PrintNameRValue(std::string&& s)
{
	std::cout << s << std::endl;
}

int main()
{
	int i = GetValue(); // rvalue to lvalue
	int i = 10; // rvalue to lvalue
	int a = i; // lvalue to lvalue
	const int& b = 10;
	GetLvalueRef() = 5; // Works
	SetLValueRef(10); // Only works because the function takes a const reference
	
	std::string firstName = "Adrian";
	std::string lastName = "Barrios";

	PrintName(firstName + lastName); // would not work if function did not receive a const reference.

	PrintNameRValue(firstName); // Does not work, only takes rvalue
	PrintNameRValue(firstName + lastName); // Works. firstName + lastName make a temporary rvalue

}

/*
An lvalue is a variable with a location in memory.
An rvalue has no storage or location until it is assigned to an lvalue.

You can't assign something to an rvalue. 10 = 20;

*/