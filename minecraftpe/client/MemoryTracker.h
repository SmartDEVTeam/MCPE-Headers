#pragma once

#include <string>

class MemoryTracker
{
public:
	//void** vtable;	// 0

public:
	MemoryTracker(const std::string &, MemoryTracker *);
	virtual ~MemoryTracker();
	virtual void memoryStats() = 0;
};
