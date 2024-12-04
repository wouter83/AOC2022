#include <iostream>
#include "inputs.hpp"

#include <CounterUpper.h>
#include <IntProc.h>
#include <CrossedWires.h>
#include <Password.h>
#include <OrbitMap.h>
#include <PhaseComputer.h>
#include <SpaceImageFormat.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	{
		CounterUpper upper(day1Input);

		std::cout << "--- Day 01 ---" << std::endl;
		std::cout << "Answer 1: " << upper.GetFuel() << std::endl;
		std::cout << "Answer 2: " << upper.GetTotalFuel() << std::endl;
	}

	{
		IntProc proc(day2Input);
		proc.Run(12, 2);
		std::cout << "--- Day 02 ---" << std::endl;
		std::cout << "Answer 1: " << proc.returnPosZero() << std::endl;

		int noun, verb;
		bool found = false;

		for (noun = 0; noun < 100; ++noun)
		{
			for (verb = 0; verb < 100; ++verb)
			{
				IntProc proc_2(day2Input);
				proc_2.Run(noun, verb);
				if (proc_2.returnPosZero() == 19690720)
				{
					found = true;
					break;
				}
			}
			if (found) break;
		}
		std::cout << "Answer 2: " << 100 * noun + verb << std::endl;
	}

	{
		auto wires = Generic::splitString(day3Input, "\n");
		CrossedWires wire;
		wire.LoadWires(wires[0], wires[1]);
		int closedCross = 0;
		int shortestCross = 0;
		wire.RunWires(closedCross, shortestCross);

		std::cout << "--- Day 03 ---" << std::endl;
		std::cout << "Answer 1: " << closedCross << std::endl;
		std::cout << "Answer 2: " << shortestCross << std::endl;
	}

	{
		auto boundary = Generic::splitString(day4Input, "-");
		uint lowBoundary = Generic::StringToInt(boundary[0]);
		uint highBoundary = Generic::StringToInt(boundary[1]);
		uint count = 0;
		for (uint i = lowBoundary; i <= highBoundary; ++i)
		{
			Password p;
			if (p.Verify(std::to_string(i)))
				count++;
		}


		std::cout << "--- Day 04 ---" << std::endl;
		std::cout << "Answer 1: " << count << std::endl;
		std::cout << "Answer 2: " << count << std::endl;
	}

	{

		std::cout << "--- Day 05 ---" << std::endl;
		{
			IntProc proc(day5Input);
			InpOutp io;
			io.Input.push_back(1);
			proc.Run(io);
			std::cout << "Answer 1: " << io.Output.back() << std::endl;
		}
		{
			IntProc proc(day5Input);
			InpOutp io;
			io.Input.push_back(5);
			proc.Run(io);
			std::cout << "Answer 2: " << io.Output.back() << std::endl;
		}
	}
	{
		OrbitMap map(day6Input);
		std::cout << "--- Day 06 ---" << std::endl;
		std::cout << "Answer 1: " << map.GetOrbit() << std::endl;
		std::cout << "Answer 2: " << map.GetShortest() << std::endl;
	}

	{
		PhaseComputer pc(day7Input);
		

		std::cout << "--- Day 07 ---" << std::endl;
		std::cout << "Answer 1: " << pc.getGreatest() << std::endl;
		std::cout << "Answer 2: " << pc.getGreatestLoopback() << std::endl;
	}

	{
		SpaceImageFormat sif(day8Input, 25,6);


		std::cout << "--- Day 08 ---" << std::endl;
		std::cout << "Answer 1: " << sif.FewestInLayer(0) << std::endl;
		std::string a2 = sif.GetImage();
		
		std::cout << "Answer 2: " << a2 << std::endl;
	}
}