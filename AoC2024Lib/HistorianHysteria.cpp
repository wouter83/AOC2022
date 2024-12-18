#include "pch.h"
#include "HistorianHysteria.h"
#include "../Generic/Generic.h"

void HistorianHysteria::ParseInput(const std::string& str)
{

	auto lines = Generic::splitString(str, "\n");
	for (auto line : lines)
	{
		auto split = Generic::splitString(line, "   ");
		left.push_back(Generic::StringToInt(split[0]));
		right.push_back(Generic::StringToInt(split[1]));
	}
}

int HistorianHysteria::TotalDistance()
{
	if (left.size() != right.size())
		return int();

	std::vector<int> sortedLeft = left;
	std::vector<int> sortedRight = right;

	std::sort(sortedLeft.begin(), sortedLeft.end());
	std::sort(sortedRight.begin(), sortedRight.end());

	int val = 0;
	for (size_t i = 0; i < sortedLeft.size(); ++i)
	{
		val += std::abs(sortedLeft[i] - sortedRight[i]);
	}
	return val;
}

int HistorianHysteria::SimilarityScore()
{
	int val = 0;
	for (int i : left)
	{
		size_t cnt = std::count(right.begin(), right.end(), i);
		val += cnt * i;
	}
	return val;
}
