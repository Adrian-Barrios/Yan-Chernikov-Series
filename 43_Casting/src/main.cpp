#include <iostream>

int main()
{
	// C-Style Cast
	double value = 5.25;
	int a = (int)value + 5;
	std::cout << a << std::endl; // 10, not 10.25

	// C++ Cast
	double s = static_cast<int>(value) + 5.3; // Compile time check.


}

/*

Different cast types:

1. Static_cast: Compile-time conversion between related types (e.g. int <-> float, base <-> derived pointers). No runtime safety check.

2. Dynamic_cast: Runtime-checked conversion, mainly for polymorphic base <-> derived pointers/references. Returns nullptr (or throws for references) if the cast is invalid. Requires at least one virtual function (RTTI).

3. Reinterpret_cast: Reinterprets the raw bits of one type as another (e.g. pointer <-> integer, unrelated pointer types). No safety checks, essentially type punning.

4. Const_cast: Adds or removes const (or volatile) qualification from a variable. Doesn't change the underlying type.

*/