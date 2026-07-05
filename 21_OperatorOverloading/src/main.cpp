#include <iostream>

struct Entity
{
	float x, y;
	Entity(float x, float y) : x(x), y(y) {};
	Entity Add(const Entity& other) const
	{
		return Entity(x + other.x, y + other.y);
	}
	Entity operator+(const Entity& other) const
	{
		return Add(other);
	}
};

std::ostream& operator<<(std::ostream& stream, const Entity& other)
{
	stream << other.x << ", " << other.y;
	return stream;
}

int main()
{
	Entity e(2.3f, 2.4f);
	Entity f(3.4f, 9.0f);

	Entity result = e + f;

}