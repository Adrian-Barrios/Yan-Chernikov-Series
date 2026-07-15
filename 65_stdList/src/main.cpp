#include <iostream>
#include <list> // Implemented as a doubly-linked list. Fast random access not supported.
// Insertions can be costly (except for fron and back)

void printList(const std::list<int>& l)
{ 
	std::cout << "List Elements: ";
	for (auto it = l.begin(); it != l.end(); it++)
		std::cout << *it << ", ";
}

int main()
{
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	std::cout << l.front(); // 1
	std::cout << '\n';
	std::cout << l.back(); // 4
	std::cout << '\n';

	printList(l);

	// Insert
	l.insert(begin(l), 20); // 20, 1, 2, 3, 4,

	auto it = cbegin(l);
	it = std::next(it, l.size() / 2);
	l.insert(it, 80);
	l.sort();
	l.remove_if([](int n) {return n <= 1;});
	printList(l);

	printList(l);

	l.clear();
	std::cout << '\n';
	std::cout << "Cleared list: " << std::endl;
	printList(l);
}