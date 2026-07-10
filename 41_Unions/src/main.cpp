#include <iostream>

int main()
{
	struct Union
	{
	union
	{
		float a;
		int b;
	};

	};

	Union u;

	u.a = 2.0f;
	std::cout << u.a << ", " << u.b << std::endl;
	std::cin.get();

}

/*
Members of a union share the same memory.
A union with 100 integers is still only 4 bytes large.
*/