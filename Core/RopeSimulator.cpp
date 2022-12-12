#include "pch.h"
#include "RopeSimulator.h"
#include "../Generic/Generic.h"
#include <cmath>
#include <unordered_set>
#include <list>

RopeSimulator::RopeSimulator(const std::string& input)
{
	for (auto str : Generic::splitString(input, "\n"))
	{
		auto step_raw = Generic::splitString(str, " ");
		Step step(step_raw[0].c_str()[0], Generic::StringToInt(step_raw[1]));
		steps.push_back(step);
	}
}

RopeSimulator::~RopeSimulator()
{
}

struct cord
{
	cord(int x, int y) :x(x), y(y) {};
	int x{};
	int y{};

	inline bool operator ==(const cord other) const
	{
		return other.x == x && other.y == y;
	}
};

namespace std {
	template<>
	struct hash<cord> {
		const size_t operator()(const cord& c) const
		{
			return std::hash<int>()(c.x) ^ std::hash<int>()(c.y);
		}
	};
}
int RopeSimulator::Run()
{
	int x{};
	std::unordered_set<cord> tail;
	int HeadPosX{}, HeadPosY{}, TailPosX{}, TailPosY{};
	tail.insert(cord(0,0));

	int dir_step{};

	for (auto step : steps)
	{
		for (int i = 0; i < step.count; ++i)
		{
			switch (step.directon)
			{
			case 'U':
				++HeadPosY;
				dir_step = 1;
				break;
			case 'D':
				--HeadPosY;
				dir_step = -1;
				break;
			case 'L':
				--HeadPosX;
				dir_step = -1;
				break;
			case 'R':
				++HeadPosX;
				dir_step = 1;
				break;
			default:
				break;
			}


			if (std::abs(HeadPosX - TailPosX) > 1)
			{
				if (HeadPosY != TailPosY)
				{
					if (HeadPosX > TailPosX)
						TailPosX++;
					else
						TailPosX--;
					if (HeadPosY > TailPosY)
						TailPosY++;
					else
						TailPosY--;
				}
				else
					TailPosX+=dir_step;
			}
			if (std::abs(HeadPosY - TailPosY) > 1)
			{
				if (HeadPosX != TailPosX)
				{
					if (HeadPosX > TailPosX)
						TailPosX++;
					else
						TailPosX--;
					if (HeadPosY > TailPosY)
						TailPosY++;
					else
						TailPosY--;
				}
				else
					TailPosY+=dir_step;
			}
			tail.insert(cord(TailPosX, TailPosY));
		}
	}
	return tail.size();
}
