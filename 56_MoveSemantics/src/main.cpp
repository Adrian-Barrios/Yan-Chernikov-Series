#include <iostream>

class String
{
public:
	String() = default;
	String(const char* string)
	{
		printf("Created\n");
		m_Size = strlen(string) + 1;
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);

	}
	String(const String& other)
	{
		printf("Copied\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String&& other) noexcept// Move constructor. Takes rvalue reference (temp)
	{
		printf("Moved\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data; // Assigning the pointer rather than allocating new memory. We still need to handle the previous owner of the data.

		// Turn the previous owner into a 'hollow object'
		other.m_Size = 0;
		other.m_Data = nullptr;


	}

	~String()
	{
		delete m_Data;
	}

	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++)
		{
			printf("%c", m_Data[i]);
		}
		printf("\n");
	}
private:
	uint32_t m_Size;
	char* m_Data;;
};

class Entity
{
public:
	Entity(const String& string)
		: m_Name(string)
	{
	}
	Entity(String&& string) // Also need one here.
		: m_Name((String&&)string) // We need to explicitly cast the argument into a temporary rvalue reference for it to use the move constructor of String. Or use std::move()
	{
	}
	void PrintName()
	{
		m_Name.Print();
	}
private:
	String m_Name;
};

int main()
{
	Entity entity(String("Adrian"));
	entity.PrintName();
}

/*
Move semantics allows us to move objects around (introduced in C++11, which introduced rvalue reference).
Sometimes we don't want to copy one place to another, but simply change ownership.
*/