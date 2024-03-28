#pragma once
#include <string>
#include <vector>


class TreeHouse
{
public:
	TreeHouse(const std::string& input);
	int GetVisibleCount();
	int GetScenicCount();
private:
	size_t lengthOfPoints = 0;
	std::vector<int> Forrest;

};

