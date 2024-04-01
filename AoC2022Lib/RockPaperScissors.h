#pragma once
#include <string>
#include <vector>

class RockPaperScissors
{
	enum class RPC
	{
		Rock = 1,
		Paper,
		Scissors
	};
public:
	void parseInput(const std::string& str);
	int GetTotalScorePart1();
	int GetTotalScorePart2();

private:
	int calculateScore(std::pair<RPC, RPC>& pair);

	std::vector<std::pair<RPC, RPC>> part1;
	std::vector<std::pair<RPC, RPC>> part2;
};

