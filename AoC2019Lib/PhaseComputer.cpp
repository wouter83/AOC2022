#include "pch.h"
#include "PhaseComputer.h"

void PhaseComputer::sequence(const std::string& sequence)
{
	auto vals = Generic::splitString(sequence, ",");
	for (auto val : vals)
	{
		InpOutp io;
		io.Input.push_back(Generic::StringToInt(val));
		io.Input.push_back(mResult);
		IntProc ip(mProgram);
		ip.Run(io);
		if (io.Output.size() == 1)
		{
			mResult = io.Output.back();
		}
		else
		{
			__debugbreak;
		}
	}
}

size_t PhaseComputer::getResult()
{
	return mResult;
}
