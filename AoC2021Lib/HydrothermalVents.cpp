#include "pch.h"
#include "HydrothermalVents.h"
#include <Generic.h>

void HydrothermalVents::input(std::vector<std::string>& input, bool diagonal)
{
	std::vector<Point> lines;
	for (auto line : input)
	{
		std::vector<std::string> points = Generic::splitString(line, " -> ");
		// we have 2 points
		if (points.size() != 2)
			continue;
		std::vector<std::string> start = Generic::splitString(points[0], ",");
		std::vector<std::string> end = Generic::splitString(points[1], ",");
		if (start.size() != 2 || end.size() != 2)
			continue;

		Point one(std::strtol(start[0].c_str(), nullptr, 0), std::strtol(start[1].c_str(), nullptr, 0));
		Point two(std::strtol(end[0].c_str(), nullptr, 0), std::strtol(end[1].c_str(), nullptr, 0));

		// add points
		if (one.x == two.x)
		{
			//count the y
			int count = std::abs(one.y - two.y) +1;
			for (int i = 0; i < count; ++i)
			{
				Point p(one.x, i + std::min(one.y, two.y));
				lines.push_back(p);
			}
		}
		else if (one.y == two.y)
		{
			//count the x
			int count = std::abs(one.x - two.x)+1;
			for (int i = 0; i < count; ++i)
			{
				Point p(i + std::min(one.x, two.x), one.y);
				lines.push_back(p);
			}
		}
		else if (diagonal)
		{
			//count the x and y
			//get the direction
			int count = std::abs(one.x - two.x) + 1;
			bool LeftRight = false;
			bool UpDown = false;
			if (one.x < two.x)
			{
				// left to right
				LeftRight = true;
			}
			if (one.y < two.y)
			{
				// left to right
				UpDown = true;
			}
			for (int i = 0; i < count; ++i)
			{
				if (LeftRight && UpDown)
				{
					Point p(i + one.x, i + one.y);
					lines.push_back(p);
				}
				else if (LeftRight && !UpDown)
				{
					Point p(i + one.x, one.y - i);
					lines.push_back(p);
				}
				else if (!LeftRight && UpDown)
				{
					Point p(one.x - i, i + one.y);
					lines.push_back(p);
				}
				else
				{
					Point p(one.x -i, one.y -i);
					lines.push_back(p);
				}
			}
		}
	}
	
	//put in a map to count the duplicates
	for (auto point : lines)
	{
		auto result = countMap.insert(std::pair<Point, int>(point, 1));
		if (result.second == false)
		{
			result.first->second++;
		}
	}
}

int HydrothermalVents::overlap(int amount)
{
	int ret = 0;
	for (auto point : countMap)
	{
		if (point.second >= amount)
			++ret;
	}
	return ret;
}