#include <iostream>
#include "Log.h"

static int Multiply(int a, int b)
{
	Log("Multiply");
	return a * b;
}

int main()
{
	std::cout << Multiply(2, 3) << std::endl;
}

/*

 CTRL + F7 only compiles, does not link.
 CTRL + F5 both compiles and links, and also executes.
 Static means that the function is only declared for this translation unit. Meaning we are not using it elsewhere other
 than this file

 */