#include <iostream>

class Parent
{
public:
	Parent() { std::cout << "Constructed" << std::endl; };
	virtual ~Parent() { std::cout << "Destructedd" << std::endl; };
};

class Child : public Parent
{
public:
	Child() { m_array = new int[50]; std::cout << "Child Constructed" << std::endl; };
	~Child() override { delete[] m_array; std::cout << "Child Destructed" << std::endl; }; // Doesn't replace the base destructor, but ensures this destructor is called as well.
private:
	int* m_array;
};

int main()
{
	Parent* parent = new Parent();
	delete parent;
	std::cout << "------------------------" << std::endl;
	Parent* poly = new Child();
	delete poly;
}

// Making a parent class destructor virtual ensures that the child class destructor also gets called to prevent memory leaks.