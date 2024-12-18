#include "pch.h"
#include "RedNosedReports.h"
#include "../Generic/Generic.h"

void RedNosedReports::ParseInput(const std::string& str)
{
	for (auto line : Generic::splitString(str, "\n"))
	{
		std::vector<int> lineVector;
		for (auto kar : Generic::splitString(line, " "))
		{
			lineVector.push_back(Generic::StringToInt(kar));
		}
		map.push_back(lineVector);
	}
}

bool isSafe(const std::vector<int>& line)
{
	if (line.size() < 2) 
		return true;

	bool increase = (line[0] - line[1]) < 0;
	for (int i = 1; i < line.size(); ++i)
	{
		int diff = line[i] - line[i - 1];
		if (abs(diff) > 3) 
			return false;
		if (diff > 0 && increase)
			return false;
	}
	return true;
}

int RedNosedReports::ReturnSafeCount() const
{
	int val = 0;
	for (const auto& line : map)
	{
		if (isSafe(line))
			val++;
	}
	return val;
}
