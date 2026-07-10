#include "pch.h"

int main()
{
	 
}

/* 

Check the main.i file.

pch = Pre Compiled Header

Precompiled headers are vital for large projects.

If you make a change to a file, it needs to be recompiled.
If you are using code from the standard library, that code wont change, so why parse and recompile every time?

No need to read the header files every time.

A precompiled header file is in binary format, easier to use by the compiler. 

DO NOT PUT FREQUENTLY CHANGING FILES INTO THE PRE COMPILED HEADER

*/