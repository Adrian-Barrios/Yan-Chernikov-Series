#include <iostream>
#include <string>

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0;
public:
	const std::string& GetName() const {
		m_DebugCount++;
		return m_Name;
	}
	
};


int main()
{
	const Entity e;
	e.GetName();

	int x = 8;
	auto f = [=]() mutable
		{
			x++;
			std::cout << x << std::endl;
		};
	f();
}

/* 

First use of mutable (most common) : With const class methods->Allows class members to be changed by const class methods.

Second use of mutable: With lambdas. Variables passed by values can be changed.

In  the code above, if the lambda was not mutable, then we would have to do something like int y = ++x;
 
Sidenote: Always try to pass integers by value. Passing by reference has the following effects.
An extra indirection (pointer dereference)
Potential memory access instead of register access
No meaningful reduction in cost (since there’s nothing expensive to avoid copying)
 */