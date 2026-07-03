#include <iostream>
#include <string>

class Parent
{
public:
	virtual std::string GetName() const { return "Parent"; }
};

void PrintName(Parent* p) {};

class Child : public Parent
{
private:
	std::string m_Name;
public:
	Child(const std::string& name) :m_Name(name) {};
	std::string GetName() const { return "Child"; }
};

int main()
{
	Parent* p = new Parent();
	std::cout << p->GetName() << std::endl;

	Child* c = new Child("Adrian");
	std::cout << c->GetName() << std::endl;

	Parent* f = c; 
	std::cout << f->GetName() << std::endl;
}
