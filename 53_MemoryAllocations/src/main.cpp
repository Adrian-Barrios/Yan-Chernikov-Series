#include <iostream>
#include <memory>

// Tracking Memory Allocations

struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;
	uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size)
{
	std::cout << "Allocating " << size << " bytes\n";
	s_AllocationMetrics.TotalAllocated += 1;
	std::cout << "Current usage: " << s_AllocationMetrics.CurrentUsage() << " allocations\n";
	return malloc(size);
}

void operator delete(void* memory)
{
	std::cout << "Freed memory" << '\n';
	s_AllocationMetrics.TotalFreed += 1;
	std::cout << "Current usage: " << s_AllocationMetrics.CurrentUsage() << " allocations\n";
	free(memory);
}

struct Object
{
	int x, y, z;
};

int main()
{
	Object* object = new Object;
	{
		std::unique_ptr<Object> obj = std::make_unique<Object>();
	}
	delete object;
}