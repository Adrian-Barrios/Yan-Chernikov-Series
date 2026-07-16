#include <deque> // pronounced deck
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <iterator>

/*
Elements of a deque are not stored contiguously
Insertion and removal at the ends is O(1) and O(n) for those not at the ends (requires traversal).
Fixed sized arrays.
*/

void printDeque(const std::deque<int>& data)
{
	std::for_each(std::begin(data), std::end(data), [](const int& n) {std::puts(std::to_string(n).c_str());});
}

int main()
{
	std::cout << "=======Deque Pop Front =======" << '\n';
	std::deque<int> d{1,2,3,4,5,6};
	for (auto elem : d)
	{
		std::cout << elem << ", ";
	}
	d.pop_front();
	std::cout << '\n';
	for (auto elem : d)
	{
		std::cout << elem << ", ";
	}
	std::cout << '\n';
	std::cout << "======= Access =======" << '\n';
	std::cout << '\n';
	std::cout << "Element at position 2: " << d[2];

	std::cout << '\n';
	
	std::cout << "======= Empty Check =======" << '\n';

	bool isEmpty;
	if (d.empty())
	{
		std::cout << "Deque is empty" << '\n';
	}
	else
	{
		std::cout << "Dequeue is not empty." << '\n';
	}

	std::cout << "======= Insert =======" << '\n';

	auto it = d.begin() + 1;
	d.insert(it, 20);
	std::cout << *(d.begin() + 1) << std::endl;

	std::cout << "======= Advancing the Iterator =======" << '\n';

	auto it2 = d.begin();
	auto distance = std::distance(it2, d.end());
	std::advance(it2, distance-1); // Advance until the end. Should be 6
	std::cout << "Last value on the deque after using std::advance: " << *it2;



	return 0;
}