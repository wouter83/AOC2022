#pragma once
#include <Generic.h>


class IntProc
{
	enum OppCode
	{
		Nop = 0,
		Add = 1,
		Multiply = 2,
		Halt = 99,
	};
public:
	explicit IntProc(const std::string& input);
	void ExpandVector(uint regO);
	void Run();
	void Run(uint noun, uint verb);
	std::vector<uint>& Memory() { return mMemory; }
	uint returnPosZero() { return mMemory.at(0); }
private:
	std::vector<uint> mMemory;
};

