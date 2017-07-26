#pragma once

class BlockState
{
public:
	enum class BlockStates : int;
		
	int state_i1; // 0
	int state_i2; // 4
	bool initialized; // 8
		
	BlockState();
	bool getBool(unsigned char const&) const;
	bool isInitialized() const;
	void* initState(unsigned int&, unsigned int);
	unsigned int getMask() const;
};
