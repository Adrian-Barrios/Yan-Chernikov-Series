#include <iostream>
#include <optional> // C++17
#include <fstream>
#include <string>

std::optional<std::string> ReadFileAsString(const std::string& filepath, bool& outSuccess)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		
		std::string result;
		// read file
		stream.close();
		outSuccess = true;
		return result;
	}
	return std::string();
}

int main()
{
	bool fileOpenedSuccessfully;
	std::optional<std::string> data = ReadFileAsString("data.txt", fileOpenedSuccessfully);

	std::string value = data.value_or("Not present.");
	if (data.has_value())
	{
		std::cout << "File read successfully!\n";
		std::cout << value << std::endl;
	}
	else
	{
		std::cout << "File could not be opened!\n";
	}
}















/*

Dealing with data that may or may not be there. To prevent unwanted behavior (missing or unreadable data) we use optional.

*/