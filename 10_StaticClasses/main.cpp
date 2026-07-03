#include <iostream>

struct Entity
{
	static int x, y;
};

int Entity::x; // Must be declared outside, here.
int Entity::y;


int main()
{
	Entity e;
	e.x = 2;
	e.y = 3;
	
	Entity f;
	f.x = 5; // Pointing to the same memory as e.x
	f.y = 8;
	Entity::y = 8; // We can also refer to them like this, since they are the same across all Entity instances.

	std::cout << e.x << std::endl;
	std::cout << e.y << std::endl;
	std::cout << f.x << std::endl;
	std::cout << f.y << std::endl;
}

// Static methods cannot access non-static member variables