struct Padding
{
	int age; // 4 bytes used, 4 bytes padding
	double salary; // 8 bytes used, 0 bytes padding
	short int ID; // 2 bytes used, 6 bytes padding
};

struct IdealPadding
{
	double age; // 8 bytes, 0 padding
	int age; // 4 bytes, 4 padding
	short int ID; // 2 bytes, included in the same 
};

/*

The size of the structure is **24 bytes**, because the compiler inserts **padding** to satisfy the alignment requirements of the data members.

Memory layout:

* `int age`: 4 bytes
* Padding: 4 bytes (so that `double salary` begins on an 8-byte boundary)
* `double salary`: 8 bytes
* `short int id`: 2 bytes
* Trailing padding: 6 bytes (so that the total size of the structure is a multiple of the largest alignment requirement, which is 8 bytes)

This gives a total size of:

* Data: 4 + 8 + 2 = **14 bytes**
* Padding: 4 + 6 = **10 bytes**
* **Total: 24 bytes**

Padding is inserted by the **compiler**, not the operating system. On most 64-bit systems, data types have alignment requirements (`int` is typically aligned to 4 bytes, `double` to 8 bytes, and `short int` to 2 bytes). The compiler adds padding so that each member begins at a correctly aligned memory address, allowing the CPU to access memory more efficiently.


*/