#include "pch.h"
#include "HillClimbingAlgorithm.h"
#include "../Generic/Generic.h"
#include <algorithm>

HillClimbingAlgorithm::HillClimbingAlgorithm(const std::string& input)
{
	for (auto inp : Generic::splitString(input, "\n"))
	{
		std::vector<char> HillLine;
		for (auto c : inp)
		{
			if (c == 'S')
			{
				startX = Hills.size();
				startY = HillLine.size();
				c = 'a' - 1;
			}
			if (c == 'E')
			{
				stopX = Hills.size();
				stopY = HillLine.size();
				c = 'z' + 1;
			}
			HillLine.push_back(c);

		}
		Hills.push_back(HillLine);
		maxY = HillLine.size();
	}
	maxX = Hills.size();
	Climb(startX, startY);

}

size_t HillClimbingAlgorithm::Climb(size_t x, size_t y)
{
	size_t ret = 1;
	char thisChar = Hills[y][x];

	// get around us
	// above
	if (y != 0 && ((Hills[y-1][x] - 0x40) - (thisChar - 0x40)) == 1)
	{
		ret += Climb(x, y-1);
	}
	// right
	if (x != maxX && ((Hills[y][x+1] - 0x40) - (thisChar - 0x40)) == 1)
	{
		ret += Climb(x + 1, y);
	}
	// below
	if (y != maxY && ((Hills[y+1][x] - 0x40) - (thisChar - 0x40)) == 1)
	{
		ret += Climb(x, y + 1);
	}
	// left
	if (x != 0 && ((Hills[y][x-1] - 0x40) - (thisChar - 0x40)) == 1)
	{
		ret += Climb(x - 1, y);
	}
	return ret;
}
