#include <iostream>

class Singleton
{
public:
	static Singleton& Get() 
	{
		static Singleton s_Instance;
		return s_Instance; 
	}
};

void Function()
{
	static int i = 0; // On subsequent calls to Function, we dont create a new i.
	i++;
	std::cout << i << std::endl;
}

struct Singleton
{

};

int main()
{
	Function(); //1
	Function();	//2
	Function();	//3
	Function();	//4
}				
/*

*/