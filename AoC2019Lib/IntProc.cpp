#include "pch.h"
#include "IntProc.h"
#include <iostream>

IntProc::IntProc(const std::string& str)
{
	std::vector<std::string> parsed = Generic::splitString(str, ",");

	for (const auto& val : parsed)
	{
		mMemory.push_back(Generic::StringToInt(val));
	}
}

void IntProc::ExpandVector(uint regO)
{
	regO++;
	if (regO > mMemory.size())
	{
		// expand vector
		int toAdd = (int)(regO - mMemory.size());
		for (int i = 0; i < toAdd; ++i)
		{
			//std::cout << "Warning: expanding vector" << std::endl;
			mMemory.push_back(IntProc::Nop);
		}
	}
}

void IntProc::Run()
{
	Run(mMemory.at(1), mMemory.at(2));
}

void IntProc::Run(uint noun, uint verb)
{
	if (mMemory.size() < 4) return;

	mMemory.at(1) = noun;
	mMemory.at(2) = verb;

	uint ip = 0;
	uint regA = 0, regB = 0, regO = 0;
	bool error = false;
	while (!error)
	{
		OppCode oppCode = static_cast<OppCode>(mMemory.at(ip++));
		switch (oppCode)
		{
		case IntProc::Add:
			regA = mMemory.at(ip++);
			regB = mMemory.at(ip++);
			regO = mMemory.at(ip++);
			mMemory.at(regO) = mMemory.at(regA) + mMemory.at(regB);
			break;
		case IntProc::Multiply:
			regA = mMemory.at(ip++);
			regB = mMemory.at(ip++);
			regO = mMemory.at(ip++);
			mMemory.at(regO) = mMemory.at(regA) * mMemory.at(regB);
			break;
		case IntProc::Halt:
			return;
			break;
		default:
			break;
		}
	}
}
