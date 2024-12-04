#pragma once
#include <Generic.h>
#include <list>

struct InpOutp
{
	std::list<size_t> Input;
	std::list<size_t> Output;
};

class IntProc
{
	enum OppCode
	{
		Nop = 0,
		Add = 1,
		Multiply = 2,
		Input = 3,
		Output = 4,
		JmpTrue = 5,
		JmpFalse = 6,
		LessThan = 7,
		Equals = 8,
		Halt = 99,
	};
public:
	explicit IntProc(const std::string& input);
	bool Run();
	bool Run(InpOutp& io);
	bool Run(int noun, int verb);
	bool Run(int noun, int verb, std::list<size_t>& input, std::list<size_t>& output);
	std::vector<int>& Memory() { return mMemory; }
	uint returnPosZero() { return mMemory.at(0); }
	void AddInput(size_t val);
	size_t GetOutput();
private:
	std::vector<int> mMemory;
	int ip = 0;
	std::list<size_t> input;
	std::list<size_t> output;
};

