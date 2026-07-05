#include <iostream>

struct Vector2
{
	float x, y;

};

class String
{

private:
	char* m_Buffer;
	size_t m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size+1];
		memcpy(m_Buffer, string, m_Size+1);
		m_Buffer[m_Size] = 0;
	}

	String(const String& other)
		:m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~String()
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);

};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

int main()
{
	Vector2 a = { 2,3 };
	Vector2 b = a;

	Vector2* c = new Vector2();
	Vector2* d = c;

	d++; // Only affecting pointer d
	d->x = 10; // Affecting memory that both c and d point to.

	int x = 2;
	int y = x;

	// String Demonstration

	String string = "Adrian";
	String second = string; // Without a copy constructor: shallow copy, copied the pointer m_Buffer and you get a crash because of double destroying.

	second[2] = 'd'; // Both string and second become Addian if we dont have a copy constructor.
	std::cout << string << std::endl;
	std::cout << second << std::endl;
}