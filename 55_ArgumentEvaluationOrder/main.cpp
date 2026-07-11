#include <iostream>

void Function(int a, int b, int c) 
{
	std::cout << a << " + " << b << " + " << c << " = " << (a + b + c) << std::endl;
}



int main()
{
	int value = 0;
	Function(value++, value++, value++); // Undefined behavior up until C++17 . The compiler can evaluate these in parallel, which creates problems.


}