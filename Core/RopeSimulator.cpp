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
	cord(){};
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
int RopeSimulator::Run(size_t knotCount)
{
	int x{};
	std::vector<std::unordered_set<cord>> tail(knotCount);
	cord HeadPos;
	std::vector<cord> TailPos(knotCount,cord());
	
	std::vector<int> TailKnots;
	tail[0].insert(cord(0, 0));

	int dir_step{};

	for (auto step : steps)
	{
		for (int i = 0; i < step.count; ++i)
		{
			switch (step.directon)
			{
			case 'U':
				++HeadPos.y;
				dir_step = 1;
				break;
			case 'D':
				--HeadPos.y;
				dir_step = -1;
				break;
			case 'L':
				--HeadPos.x;
				dir_step = -1;
				break;
			case 'R':
				++HeadPos.x;
				dir_step = 1;
				break;
			default:
				break;
			}

			// calculate for each knot
			for (int j = 0; j < knotCount; ++j) 
			{
				cord head;
				if (j == 0)
				{
					head = HeadPos;
				}
				if (std::abs(head.x - TailPos[j].x) > 1)
				{
					if (head.y != TailPos[j].y)
					{
						if (head.x > TailPos[j].x)
							TailPos[j].x++;
						else
							TailPos[j].x--;
						if (head.y > TailPos[j].y)
							TailPos[j].y++;
						else
							TailPos[j].y--;
					}
					else
						TailPos[j].x += dir_step;
				}
				if (std::abs(head.y - TailPos[j].y) > 1)
				{
					if (head.x != TailPos[j].x)
					{
						if (head.x > TailPos[j].x)
							TailPos[j].x++;
						else
							TailPos[j].x--;
						if (head.y > TailPos[j].y)
							TailPos[j].y++;
						else
							TailPos[j].y--;
					}
					else
						TailPos[j].y += dir_step;
				}
				
				tail[j].insert(cord(TailPos[j].x, TailPos[j].y));

				// the new head is the old tail
				head = TailPos[j];
			}
		}
	}
	return tail[knotCount-1].size();
}
