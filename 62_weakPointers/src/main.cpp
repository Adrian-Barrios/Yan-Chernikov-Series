#include <iostream>
#include <memory>

struct Object
{
	~Object() { std::cout << "Deleted object\n"; }
};

struct Manager
{
	std::weak_ptr<Object> Obj;

	void Func()
	{
		if (auto obj = Obj.lock())
		{
			// obj->
		}
	}
};

Manager manager;

int main()
{
	{
		std::weak_ptr<Object> obj = std::make_shared<Object>();
		manager.Obj = obj;
	}
}

// Weak pointers have a weak reference, meaning they wont keep the object alive, but will not point to it if deleted.