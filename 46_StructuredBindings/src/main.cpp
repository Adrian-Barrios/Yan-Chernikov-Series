#include <iostream>
#include <tuple>

std::pair<std::string, int> CreatePerson()
{
	return { "adrian", 22 };
}

int main()
{
	auto person = CreatePerson();
	auto& name = std::get<0>(person);

	std::string my_name;
	int age;
	std::tie(my_name, age) = CreatePerson();

	// Structured bindings: C++17
	std::string structBindedName;
	int structBindedAge;
	auto [structBindedName, structBindedAge] = CreatePerson();


}