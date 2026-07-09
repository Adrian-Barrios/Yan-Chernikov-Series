#include <iostream>

int main()
{
	// Stack allocation
	int value = 5; 
	int array[5];

	// Heap allocation
	int* hvalue = new int;
	*hvalue = 5;
	int* harray = new int[5];

	delete hvalue;
	delete[] harray;

}

/*
The stack is usually 2MB in size for a process.
It grows backwards, meaning that memory allocated first will be at a higher memory address
than subsequent allocations.
Stack allocations are extremely fast (one CPU instruction). All you do is move the stack 
pointer and return the address.

The 'new' keyword essentially calls malloc, which in turn performs a system call to the OS.
*/