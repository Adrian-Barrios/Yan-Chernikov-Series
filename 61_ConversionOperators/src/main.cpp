#include <iostream>
#include <memory>

template<typename T>
class ScopedPtr
{
public:
	ScopedPtr() = default;
	ScopedPtr(T* ptr) : m_Ptr(ptr) {}
	~ScopedPtr() {delete m_Ptr}
	
	T* Get() { return m_Ptr; }
	const T* Get() const { return m_Ptr; }
private:
	T* m_Ptr = nullptr;
	operator bool() const { return m_Ptr != nullptr; }
};

struct Orange
{
	operator float() { return 5.5f; }
};

struct Entity
{
	float X = 0.0f, Y = 0.0f;
};

void ProcessEntity(Entity* e)
{
	if (e) 
	{
		// ... 
	}
}

int main()
{
	Orange orange;
	float f = orange;

	ScopedPtr<Entity> e = new Entity();
	Entity* entity = new Entity();

	if (entity)

	std::cout << (float)orange << std::endl;

}