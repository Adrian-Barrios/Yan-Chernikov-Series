#include <iostream>

class Entity
{
private:
	int x, y;
	void Print(){}
protected:
public:
	Entity(int x, int y)
		: x(x), y(y)
	{
		Print();
	}
};

class Player : public Entity
{
public:
	Player(){}

};

int main()
{

}

// Default visibility in classes is private, public in structs

// A friend of a class can access private members

// Protected means that the class and all classes that inherit from it can access those variables and methods.