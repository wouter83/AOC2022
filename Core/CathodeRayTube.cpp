#include "pch.h"
#include "CathodeRayTube.h"
#include "../Generic/Generic.h"
#include <iostream>

CathodeRayTube::CathodeRayTube(const std::string& inp)
{
	Steps.push_back(CpuStep(Operation::noop, 0));

	for (auto steps : Generic::splitString(inp, "\n"))
	{
		auto step = Generic::splitString(steps, " ");

		if (step.size() == 1)
		{
			// noop,
			if (step[0] == "noop")
				Steps.push_back(CpuStep(Operation::noop, 0));
		}
		if (step.size() == 2)
		{
			// addx
			if (step[0] ==  "addx")
			{
				Steps.push_back(CpuStep(Operation::noop, 0));
				Steps.push_back(CpuStep(Operation::addx, Generic::StringToInt(step[1])));
			}
		}
	}
}

int CathodeRayTube::RunCpu()
{
	int x = 1;
	std::vector<int> retVector;
	for (int cycle = 0; cycle < Steps.size(); ++cycle)
	{
		if (cycle != 0 && (cycle % 40 == 20) || cycle == 20)
		{
			retVector.push_back(x * cycle);
		}
		switch (Steps[cycle].Operation)
		{
		case Operation::noop:
		{
			break;
		}
		case Operation::addx:
		{
			x += Steps[cycle].value;
			break;
		}
		default:
			break;
		}
	}
	
	int ret{};
	for (auto i : retVector)
		ret += i;
	return ret;
}

void drawPixel(int i, int spritePos, std::vector<char>& crtLine)
{
	int modulo = i % crtLine.size();
	
	if (spritePos - 1 == modulo || spritePos == modulo || spritePos + 1 == modulo)
	{
		if (modulo >= 0 && modulo < crtLine.size())
			crtLine[modulo] = '#';
	}
}

void printLine(std::vector<char>& crtLine)
{
	for (auto c : crtLine)
	{
		std::cout << c;
	}
	std::cout << std::endl;
}

std::vector<std::string> CathodeRayTube::RunCRT()
{
	int x = 1;
	std::vector<std::string> ret;
	std::vector<char> crtLine(40,'.');
	for (int cycle = 1; cycle < Steps.size(); ++cycle)
	{
		drawPixel(cycle-1, x, crtLine);
		if (cycle != 0 && cycle % 40 == 0)
		{
			printLine(crtLine);
			ret.push_back(std::string(crtLine.begin(), crtLine.end()));
			crtLine.clear();
			crtLine.assign(40,'.');

		}
		switch (Steps[cycle].Operation)
		{
		case Operation::noop:
		{
			break;
		}
		case Operation::addx:
		{
			x += Steps[cycle].value;
			break;
		}
		default:
			break;
		}
	}
	return ret;
}
