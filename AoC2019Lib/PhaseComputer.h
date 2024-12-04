#pragma once

#include "IntProc.h"
#include <Generic.h>

class PhaseComputer
{
public:
	explicit PhaseComputer(const std::string& inp) : mProgram(inp) {};

	size_t getGreatest();
	size_t getGreatestLoopback();
private:

	void sequence(const std::vector<int>& sequence);
	void sequenceLoopback(const std::vector<int>& sequence);
	inline size_t getResult() { return mResult; }


	std::string mProgram;
	std::vector<IntProc> mPC;
	size_t mResult = 0;
};

