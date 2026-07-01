#include <iostream>

#define LOG(x) std::cout << x << std::endl;

int main()

{	

	char* buffer = new char[8]; //8 bytes of memory. Pointer to the beginning of that block.
	memset(buffer, 0, 8); //(pointer, value_to_fill, size_in_bytes)

	char** ptr_to_ptr = &buffer;
	
	delete[] buffer;

	int var = 8;
	int* ptr = NULL;
	ptr = &var;
	LOG(*ptr);
	
	
}

// std::cout << *ptr << std::endl; would not work if it was a void*