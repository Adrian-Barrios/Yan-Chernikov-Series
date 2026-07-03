#include <iostream>

int s_Variable = 10; // Using extern means we must use the definition outisde this translation unit, and the other s_variable
// should not be static.

void Function()
{

}

int main()
{
	std::cout << s_Variable << std::endl;
}