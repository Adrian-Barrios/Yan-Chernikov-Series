#include <iostream>
#include <string>

class Printables
{
public:
	virtual std::string GetClassName() = 0;
};

class Parent : public Printables
{
public:
	virtual std::string GetName() = 0;
	std::string GetClassName() override { return "Parent"; }
};

void PrintName(Parent* p) {};

class Child : public Parent
{
private:
	std::string m_Name;
public:
	Child(const std::string& name) :m_Name(name) {};
	std::string GetName() { return "Child"; }
	std::string GetClassName() override { return "Child"; }
};

void Print(Printables* obj)
{
	std::cout << obj->GetClassName() << std::endl;
}

int main()
{
	Child* c = new Child("Adrian");
	std::cout << c->GetName() << std::endl;

	Print(c);
}

// You cannot create objects of a class that contains pure virtual functions.
