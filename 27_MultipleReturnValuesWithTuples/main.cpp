#include <iostream>
#include <functional> // Contains the tuple container
#include <utility> // Used to make the tuple
#include <string>
#include <array>

// Option 1: Have a struct
struct TEST_STRUCT
{
	std::string STRUCT_STRING;
	int STRUCT_INT;
};

TEST_STRUCT StructReturnFunction()
{
	std::string TEST_STRING = "Struct Test String";
	int TEST_INT = 100;
	return {TEST_STRING, TEST_INT};
}

// Option 2: Array
std::array<std::string, 2> ArrayReturnFunction()
{
	std::string TEST_STRING_1 = "One";
	std::string TEST_STRING_2 = "Two";
	std::array<std::string, 2> RESULTS = { TEST_STRING_1, TEST_STRING_2 };
	return RESULTS;
}

// Option 3: Tuple. Requires the std::get<index>(tuple_name) to access elements
std::tuple<std::string, std::string> TupleReturnFunction()
{
	std::string TEST_STRING_1 = "Tuple String";
	std::string TEST_STRING_2 = "Tuple String 2";
	return std::make_pair(TEST_STRING_1, TEST_STRING_2);
}

// Option 4: Pair. Can access using .first and .second.
std::pair<std::string, std::string> PairReturnFunction()
{
	std::string TEST_STRING_1 = "Pair String";
	std::string TEST_STRING_2 = "Pair String 2";
	return std::make_pair(TEST_STRING_1, TEST_STRING_2);
}
 
int main()
{
	// Tuple
	std::tuple<std::string, std::string> tuple_example = TupleReturnFunction();
	std::cout << std::get<0>(tuple_example) << std::endl; 

	// Pair
	auto pair_example = PairReturnFunction();
	std::cout << pair_example.first << std::endl;

	// Struct
	auto struct_example = StructReturnFunction();
	std::cout << struct_example.STRUCT_INT << std::endl;


	return 0;
}