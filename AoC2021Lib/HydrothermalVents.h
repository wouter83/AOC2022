#pragma once

#include <vector>
#include <string>
#include <map>

struct Point
{
	Point(int valX, int valY) : x(valX), y(valY) {}
	constexpr bool operator==(const Point& p) const
	{
		return (x == p.x && y == p.y);
	}
	constexpr bool operator<(const Point& p) const
	{
		return std::tie(x, y) < std::tie(p.x, p.y);
	}
	int  x = 0;
	int  y = 0;
};

class HydrothermalVents
{
public:
	void input(std::vector<std::string>& input, bool diagonal = false);
	int overlap(int amount);

private:
	std::map<Point, int> countMap;
};

