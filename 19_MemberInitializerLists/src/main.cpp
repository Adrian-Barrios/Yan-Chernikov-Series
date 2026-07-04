#include <iostream>
#include <string>

class Entity
{
private:
	std::string m_Name;
	int m_Score;
public:
	Entity()
		:m_Name("Unkown"), m_Score(0)
	{}
	Entity(const std::string& name)
		:m_Name(name)
	{}
	const std::string& GetName() const { return m_Name; }
};

int main()
{
	Entity e("Adrian"); // Carefull, if it takes no arguments, we can have the most vexing parse issue.

	std::cout << e.GetName() << std::endl;
}

/*

There is actually an advantage to MemberInitializerLists, prevents creating multiple copies:

Entity()
{
m_Name = "Unkown"; // This is bad, because m_Name is created twice.
}

*/