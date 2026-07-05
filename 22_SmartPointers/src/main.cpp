#include <memory>
#include <iostream>

class Entity
{
public:
	Entity() {
		std::cout << "Created Entity!" << std::endl;
	}
	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
	void func() {};
};

int main()
{
	// Unique pointers
	{
		std::unique_ptr<Entity> entity(new Entity()); // No implict conversion for unique_ptrs
		std::unique_ptr<Entity> entity2 = std::make_unique<Entity>(); // Exception safe, better.

		std::unique_ptr<Entity> e0 = entity; // No copy constructor.

		entity->func();
	}

	// Shared pointers, reference counting
	std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
	std::shared_ptr<Entity> sharedEntity2 = sharedEntity;

	// Weak Pointer
	std::weak_ptr<Entity> weakEntity = sharedEntity; 
}

/*

You can't copy a unique pointer, because you get double deletion.

A shared pointer has to allocate another block of memory (called the control block) to keep the reference count.

Weak pointers do not increase the reference count.

*/