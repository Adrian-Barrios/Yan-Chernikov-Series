#include <iostream>
#include <string>

class Base
{
private:

public:
	virtual void PrintName() {};
};

class Player : public Base
{
private:

public:

};

class Enemy : public Base
{
private:

public:

};

int main()
{
	Enemy e;
	Base* actuallyPlayer = new Player(); // Already has 2 types, Base and Player
	Base* actuallyEnemy = new Enemy();

	Player* p = dynamic_cast<Player*>(actuallyEnemy); // Parent class will need a virtual function to be a polymorphic type. Will give null.

	Player* p1 = dynamic_cast<Player*>(actuallyPlayer);
	
}

/*
Dynamic cast ensures our cast is valid. It is evaluated at runtime. There is runtime cost.
Mostly used for casts along the inheritance hierarchy, mostly casting from parent to derived.

The compiler is in charge of Run-Time Type Information (RTTI), which powers dynamic_cast and typeid.
For each polymorphic class, the compiler emits a std::type_info object. This is a static, per-type record identifying the class and
describing its place int inheritance graph.

RTTI can be manually deactivated in the project properties.
*/