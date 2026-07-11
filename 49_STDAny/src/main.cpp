#include <iostream>
#include <any> // C++17

int main()
{
	// any type
	std::any data;
	data = 1;
	std::cout << data.type().name() << '\n';
	data = 3.3f;
	std::cout << data.type().name() << '\n';
	data = true;
	std::cout << data.type().name() << '\n';

	// bad cast
	try
	{
		data = 1;
		std::cout << std::any_cast<float>(data) << '\n';
	}
	catch (const std::bad_any_cast& e)
	{
		std::cout << e.what() << '\n';
	}

	// has value
	data = 2;
	if (data.has_value())
	{
		std::cout << data.type().name() << ": " << std::any_cast<int>(data) << '\n';
	}

	// reset
	data.reset();
	if (!data.has_value())
	{
		std::cout << "no value" << '\n';
	}
}

/*
std::variant is generally faster with larger data and type safe, since you need to declare which types the variable can take

std::variant will also not dynamically allocate memory

std::any will cause additional memory allocation if the data is greater than 32 bytes

std::any_cast tells the compiler what is inside the variable so it can generate real code.
The compiler needs to know the type of the variable so it can pick the correct operator.
*/