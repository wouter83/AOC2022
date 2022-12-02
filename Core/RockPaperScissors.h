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
	bool parseInput(const std::string& str);
	int GetTotalScore();

private:
	std::vector<std::pair<RPC, RPC>> part1;

};

