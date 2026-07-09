#include <iostream>



void C()
{
	std::cout << "Function C" << std::endl;
}

void B()
{
	C();
	std::cout << "Function B" << std::endl;
}
void A()
{
	B();
	std::cout << "Function A" << std::endl;
}
void D()
{
	std::cout << "Function D" << std::endl;
}

int main()
{
	A();
	D();
}