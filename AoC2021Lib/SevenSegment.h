#pragma once
#include <vector>
#include <string>
#include <map>

class SevenSegment
{
public:
	void input(std::vector<std::string>& inp);
	size_t OneFourSevenEight();
	size_t OutputTotal();


private:
	std::map<std::string, size_t> outputVals;
	std::vector< std::pair<std::string, std::string>> splitInputValues;
};

