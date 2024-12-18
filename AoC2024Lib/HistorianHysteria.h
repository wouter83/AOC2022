#pragma once

#include <string>
#include <vector>

class HistorianHysteria
{
public:
	void ParseInput(const std::string& str);
	int TotalDistance();
	int SimilarityScore();

private:

	std::vector<int> left;
	std::vector<int> right;

};

