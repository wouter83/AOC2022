#pragma once
#include <vector>
#include <string>
#include <list>


typedef std::pair<size_t, bool> Points;

class LowPoints
{
public:
	void input(std::vector<std::string>& inp);
	size_t riskPoints();
	size_t bassins();
	
private:
	size_t checkLowest(size_t index);
	void checkBassins(size_t index, std::list<size_t>& foundIndex);
	
	size_t lengthOfPoints = 0;
	std::vector<Points> inpV;
};

