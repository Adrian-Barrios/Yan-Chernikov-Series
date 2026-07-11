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

	String(String&& other) noexcept
	{
		printf("Moved\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data; 


		other.m_Size = 0;
		other.m_Data = nullptr;
	}
	String& operator=(String&& other) noexcept // We must make sure that the object we are assigning to is not the same object we are assigning from.
	{
		if (this != &other) // prevents things like dest = dest; 
		{
			printf("Move assigned\n");

			delete[] m_Data; // Delete current data, so we can move the new data into it.

			m_Size = other.m_Size;
			m_Data = other.m_Data;


			other.m_Size = 0;
			other.m_Data = nullptr;
		}
		return *this;
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
	Entity(String&& string) 
		: m_Name(std::move(string)) 
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

	String string = "Hello";
	String string2 = "Bye";
	String dest((String&&)string); // Trigger the move constructor. Not the most elegant way however.
	String dest2(std::move(string2)); // 'Correct' way. Triggers move constructor.

	// Move assignment operator.

	std::cout << "===============Testing move assignment operator.===============\n";
	String string3 = "Adrian";
	String dest3;

	std::cout << "Original:\n";
	string3.Print(); // Adrian
	std::cout << "Destination:\n";
	dest3.Print(); // Nothing

	dest3 = std::move(string3); // Move assignment operator

	std::cout << "Original:\n";
	string3.Print(); // Adrian
	std::cout << "Destination:\n";
	dest3.Print(); // Nothing
}

/*
std::move
*/