#include <iostream>
#include <variant>

int main()
{
	std::variant<std::string, int> data;

	std::cout << sizeof(data) << "\n"; // 28 (string) + 4 (int) = 32 bytes
	data = "Cherno";
	data.index(); // 0
	data = 2; 
	data.index(); // 1

	auto value = std::get_if<std::string>(&data);

	std::cout << std::get<std::string>(data);
	std::cout << std::get<int>(data);

	std::cin.get();

}

/*

std::variant allows us to not worry about the exact data type that we are dealing with.
We can worry about it later, first we simply list the datatypes that the variable could be.

*/