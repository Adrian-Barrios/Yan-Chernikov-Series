#define INTEGER int

#if 1
int Multiply(INTEGER a, INTEGER b)
{
	INTEGER result = a * b;
	return result;
#include "EndBrace.h"
#endif
// This will compile successfully, because all the compiler is doing is opening EndBrace.h and copy pasting its contents.

// define simply looks for word A and substitutes with word B

// #if will run code depending on its value