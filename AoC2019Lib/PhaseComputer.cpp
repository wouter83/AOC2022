#include "pch.h"
#include "PhaseComputer.h"

void PhaseComputer::sequence(const std::vector<int>& sequence)
{
	mResult = 0;

	for (auto val : sequence)
	{
		InpOutp io;
		IntProc ip(mProgram);
		io.Input.push_back(val);
		io.Input.push_back(mResult);
		ip.Run(io);
		if (io.Output.size() == 1)
		{
			mResult = io.Output.back();
		}		
	}
}

void PhaseComputer::sequenceLoopback(const std::vector<int>& sequence)
{
	mResult = 0;

	std::vector<IntProc> procs;

	// create all the IntProcs
	for (auto s : sequence)
	{
		procs.emplace_back(mProgram);
		auto& p = procs.back();
		p.AddInput(s);
	}
	
	bool finished = false;

	size_t result = 0;

	while (!finished)
	{
		for (auto& proc : procs)
		{
			proc.AddInput(result);
			finished = proc.Run();
			result = proc.GetOutput();
		}
	}
	mResult = result;
	
}

size_t PhaseComputer::getGreatest()
{
	size_t greatest = 0;
	std::vector<int> answer;
	auto vect = Generic::generateAllUniquePermutations(0, 4);
	for (const auto& v : vect)
	{
		sequence(v);
		auto val = getResult();
		if (val >= greatest)
		{
			greatest = val;
			answer = v;
		}
	}
	return greatest;
}

size_t PhaseComputer::getGreatestLoopback()
{
	size_t greatest = 0;
	std::vector<int> answer;
	auto vect = Generic::generateAllUniquePermutations(5, 9);
	for (const auto& v : vect)
	{
		sequenceLoopback(v);
		auto val = getResult();
		if (val >= greatest)
		{
			greatest = val;
			answer = v;
		}
	}
	return greatest;
}