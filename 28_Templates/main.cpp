#include <iostream>
#include <string>

template<typename T>
void Print(T val)
{
	std::cout << val << std::endl;
}

template<int N, typename T>
class Array
{
	T m_Array[N];
public:
	int GetSize() const { return N; }
};

int main()
{
	std::cout << "Templated function calls: " << std::endl;
	Print(10);
	Print("String");
	Print<float>(3.3f);

	std::cout << "Templated class: " << std::endl;
	Array<5, int> array;
	std::cout << array.GetSize() << std::endl;
}
/*

Basically the compiler writes code for you. Templates are evaluated at compile time.
A templated function ONLY GETS CREATED when we call it.

That means that if there is something wrong within the function (i.e a syntax error) the program will still compile 
as long as the function is not called.

A C++ template is a tool for creating generic classes or functions.This allows us to write code that
works for any data type without rewriting it for each type.

Avoid code duplication by allowing one function or class to work with multiple data types, mainly 
allowing generic functions and classes.

Provides type safety unlike void* pointers or macros, and can be specialized for specific data types when needed.
Form the basis of STL containers and algorithms like vector, map, and sort.

*/