#include <iostream>

using namespace std;

int main()
{
	int number = 0;
	cout << "Number: ";
	cin >> number;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	char line[256];
	cout << "Line: ";
	cin.getline(line, 256);

	cout << "Number: " << number;
	cout << endl;
	cout << "Line: " << line;

}