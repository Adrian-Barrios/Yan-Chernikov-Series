#include <vector>
#include <iostream>

struct Vertex
{
	float x, y, z;
public:
	Vertex(float x, float y, float z) :x(x), y(y), z(z) {};
	Vertex(const Vertex& other)
		:x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Copied!" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

void Funct(const std::vector<Vertex>& vertices)
{

}

int main()
{
	std::vector<Vertex> vertices;
	vertices.push_back(Vertex(1.0f,2.0f,3.0f)); // Temporary copy, altough compilers usually optimize this.
	vertices.emplace_back(1.0f,2.0f,3.0f); // Better, avoids temporary copy.


	for (const Vertex& v : vertices) // Prevent copying vertices
	{
		std::cout << v << std::endl;
	}

	vertices.erase(vertices.begin() + 1); // Erase the second element.
	vertices.clear(); // Clear the list of vertices.

	// Lower Level Optimizations
	std::cout << "Look at how many copies! 6 copies." << std::endl;
	std::vector<Vertex> vertices_2;
	vertices_2.push_back(Vertex(1.2f,2.2f,3.3f));
	vertices_2.push_back(Vertex(1.2f, 2.2f, 3.3f));
	vertices_2.push_back(Vertex(1.2f, 2.2f, 3.3f));

	std::cout << "Now look at how many copies! Not a single one! " << std::endl;
	std::vector<Vertex> vertices_3;
	vertices_3.reserve(3); // Ensures no resizing before 3 elements are inserted.
	vertices_3.emplace_back(1,2,3);
	vertices_3.emplace_back(4,5,6);
	vertices_3.emplace_back(7,8,9);

}

// vectors can resize. You can initialize it with a set size, but you can choose not to.

// Dynamic arrays store data contiguously. Same cache lines.

