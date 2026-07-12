#include <iostream>
#include <string>

int main()
{
	int a = 5; // 0101
	a <<= 1; // Shifting bits one place to the left, so 1010, or 10. So a bit shift left doubles the number.
	std::cout << a << '\n';
	int b = 6;
	b >>= 1; // A bit shift right halves the number. So 6->3. So dividing by 2^n
	std::cout << b << '\n';

	int c = 5 & 3; // 0101 & 0011 = 0001 -> 1. AND: bit is set only if both bits are set.
	std::cout << c << '\n';

	int d = 5 | 3; // 0101 | 0011 = 0111 -> 7. OR: bit is set if either bit is set.
	std::cout << d << '\n';

	int e = 5 ^ 3; // 0101 ^ 0011 = 0110 -> 6. XOR: bit is set if exactly one bit is set.
	std::cout << e << '\n';

	int f = ~5; // ~00000101 = 11111010 -> -6. NOT: flips every bit (inverts all 0s and 1s).
	std::cout << f << '\n';
}

/*
Main:
<<
>>
&
|
^
~
*/