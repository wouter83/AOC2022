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

bool IntProc::Run()
{
	return Run(mMemory.at(1), mMemory.at(2));
}

bool IntProc::Run(InpOutp& io)
{
	return Run(mMemory.at(1), mMemory.at(2), io.Input, io.Output);
}

bool IntProc::Run(int noun, int verb)
{
	std::list<int> input;
	std::list<int> output;
	return Run(noun, verb, input, output);
}

bool IntProc::Run(int noun, int verb, std::list<int>& input, std::list<int>& output)
{
	if (mMemory.size() < 4) return false;

	mMemory.at(1) = noun;
	mMemory.at(2) = verb;

	int ip = 0;
	int regA = 0, regB = 0, regO = 0;
	bool modeA = false, modeB = false, modeC = false;
	bool error = false;
	while (!error)
	{
		modeA = modeB = modeC = false;
		///opcode etc parser
		int test = mMemory.at(ip) / 100;
		OppCode oppCode = static_cast<OppCode>(mMemory.at(ip) - (test * 100));
		if (test > 0)
		{
			modeA = test / 100;
			modeB = (test - (modeA * 100)) / 10;
			modeC = (test - ((modeA * 100) + (modeB * 10)));
		}
		ip++;

		switch (oppCode)
		{
		case IntProc::Add:
			regA = mMemory.at(ip++);
			regB = mMemory.at(ip++);
			regO = mMemory.at(ip++);
			mMemory.at(regO) = (modeC ? regA : mMemory.at(regA)) + (modeB ? regB : mMemory.at(regB));
			break;
		case IntProc::Multiply:
			regA = mMemory.at(ip++);
			regB = mMemory.at(ip++);
			regO = mMemory.at(ip++);
			
			mMemory.at(regO) = (modeC ? regA : mMemory.at(regA)) * (modeB ? regB : mMemory.at(regB));
			break;
		case IntProc::Input:
			regO = mMemory.at(ip++);
			mMemory.at(regO) = input.front();
			input.pop_front();
			break;
		case IntProc::Output:
			regO = mMemory.at(ip++);
			output.push_back(modeC ? regO : mMemory.at(regO));
			break;
		case IntProc::JmpTrue:
			regA = mMemory.at(ip++);
			regB = mMemory.at(ip++);
			if (modeC ? regA : mMemory.at(regA) != 0)
			{
				ip = modeB ? regB : mMemory.at(regB);
			}
			break;
		case IntProc::JmpFalse:
		{
			regA = mMemory.at(ip++);
			regB = mMemory.at(ip++);
			if ((modeC ? regA : mMemory.at(regA)) == 0)
			{
				ip = modeB ? regB : mMemory.at(regB);
			}
		}
			break;
		case IntProc::LessThan:
		{
			regA = mMemory.at(ip++);
			regB = mMemory.at(ip++);
			regO = mMemory.at(ip++);
			int ret = 0;
			if ((modeC ? regA : mMemory.at(regA)) < (modeB ? regB : mMemory.at(regB)))
			{
				ret = 1;
			}
			mMemory.at(regO) = ret;
		}
			break;
		case IntProc::Equals:
		{
			regA = mMemory.at(ip++);
			regB = mMemory.at(ip++);
			regO = mMemory.at(ip++);
			int ret = 0;
			if ((modeC ? regA : mMemory.at(regA)) == (modeB ? regB : mMemory.at(regB)))
			{
				ret = 1;
			}
			mMemory.at(regO) = ret;
		}
			break;

		case IntProc::Halt:
			return true;
			break;
		default:
			return false;
			break;
		}
	}
	return false;
}
