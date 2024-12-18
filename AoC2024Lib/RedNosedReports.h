#pragma once

#include <string>
#include <vector>

class RedNosedReports
{
public:
	void ParseInput(const std::string& str);
	int ReturnSafeCount() const;

private:
	std::vector<std::vector<int>> map;
};

