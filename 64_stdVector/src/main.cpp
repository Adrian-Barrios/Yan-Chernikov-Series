#include <iostream>
#include <vector> // Dynamic array. Heap allocated.

int main()
{
	std::vector<int> v;
	std::cout << "Size of the empty vector: " << v.size() * sizeof(int)  << " bytes on the heap" << '\n';

	v.push_back(2);
	std::cout << "Size of the vector after 1 element insertion: " << v.size() * sizeof(int) << " bytes on the heap" << '\n';

	for (int i{}; i < 10; i++)
		v.push_back(i);

	std::cout << "Size of vector after 10 new elements (11 elements total): " <<  v.size() * sizeof(int) << " bytes on the heap" << '\n';

	std::vector<int> shrinkable;
	shrinkable.reserve(10);
	shrinkable.push_back(10);

	shrinkable.shrink_to_fit();
	std::cout << "Shrinkable original 10. After shrink to fit: " << shrinkable.capacity();
	std::cout << std::endl;

	// Class argument template deduction (CTAD) introduced in C++17
	std::vector fv{ 1.2f,3.2f,5.5f };

	fv.erase(fv.end() - 1); // Will delete 5.5
	for (auto elem : fv)
	{
		std::cout << elem << std::endl;
	}

	for (std::vector<float>::iterator it = fv.begin(); it != fv.end(); it++)
	{
		std::cout << *it << std::endl;
	}


}