#pragma once
#include <string>
#include <vector>

class HillClimbingAlgorithm
{
public:
	HillClimbingAlgorithm(const std::string& input);
	size_t Climb(size_t x, size_t y);
private:
	std::vector<std::vector<char>> Hills;
	size_t startX{}, startY{};
	size_t stopX{}, stopY{};
	size_t maxX{}, maxY{};
};

