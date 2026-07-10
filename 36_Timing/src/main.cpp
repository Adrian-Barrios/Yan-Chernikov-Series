#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		std::cout << "Timer took " << duration.count() << "s " << std::endl;
	}
};

using namespace std::literals::chrono_literals;

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	for (int i{0}; i<10; i++)
	{
		std::cout << "Running thread: " << std::this_thread::get_id() << std::endl;
		std::cout << "Working..." << std::endl;
		std::this_thread::sleep_for(1s);
	}
	std::cout << "Finished" << std::endl;
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> result = end - start;
	std::cout << "Execution time: " << result.count() << "s " << std::endl;
	

}