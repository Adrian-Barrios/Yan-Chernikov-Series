#include <iostream>
#include <string>

using namespace std::string_literals;

class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	Entity(const std::string& name):m_Name(name), m_Age(-1){ }
	Entity(int age) :m_Name("Unknown"), m_Age(age){ }
};

class ExplicitEntity
{
private:
	std::string m_Name;
	int m_Age;
public:
	explicit ExplicitEntity(const std::string& name) :m_Name(name), m_Age(-1) {}
	explicit ExplicitEntity(int age) :m_Name("Unknown"), m_Age(age) {}
};


void PrintEntity(const Entity& entity)
{

}

int main()
{
	PrintEntity(22);
	PrintEntity(std::string("Adrian"));
	Entity a = "Adrian"s; // Converting std::string("Adrian") into an Entity. Implicit Conversion
	Entity b(22);

	ExplicitEntity e = ExplicitEntity("Adrian");
	ExplicitEntity f = ExplicitEntity(22);

	std::cin.get();
}