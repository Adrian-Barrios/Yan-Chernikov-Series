#include <iostream>

class Singleton
{
public:

	Singleton(const Singleton&) = delete;
	static Singleton& Get()
	{
		return s_Instance;
	}

	void Function() {}

private:
	Singleton() {};
	static Singleton s_Instance;
};

Singleton Singleton::s_Instance;

int main()
{
	Singleton::Get().Function();
	auto& instance = Singleton::Get();
}
/*

A singleton is a single instance of a class.
A class where you intend to only have one isntance of it.

Singletons can work as namespaces.

*/