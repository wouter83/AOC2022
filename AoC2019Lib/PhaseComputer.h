#pragma once

#include "IntProc.h"
#include <Generic.h>

class PhaseComputer
{
public:
	PhaseComputer(const std::string& inp) : mProgram(inp) {};
	void sequence(const std::string& sequence);
	size_t getResult();
private:
	std::string mProgram;
	std::vector<IntProc> mPC;
	int mResult = 0;
};

