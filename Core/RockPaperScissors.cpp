#include "pch.h"
#include "RockPaperScissors.h"
#include "../Generic/Generic.h"
#include <utility>

void RockPaperScissors::parseInput(const std::string& str)
{
	std::vector<std::string> turns = Generic::splitString(str, "\n");
	for (auto turn : turns)
	{
		std::vector<std::string> chars = Generic::splitString(turn, " ");
		char opponent = chars[0].c_str()[0] - 0x40, me = chars[1].c_str()[0] - 0x57;

		part1.push_back(std::make_pair((RPC)(opponent), (RPC)(me)));

		// do part 2 in other vector
		std::pair<RPC, RPC> pair;
		switch (me)
		{
		case 1:
			// loss
			pair.first = (RPC)(opponent);
			pair.second = (RPC)(opponent - 1);
			break;
		case 2:
			// draw
			pair.first = (RPC)(opponent);
			pair.second = (RPC)(opponent);
			break;
		case 3:
			//win
			pair.first = (RPC)(opponent);
			pair.second = (RPC)(opponent + 1);
			break;
		default:
			break;
		}

		// lazy fixup
		if ((int)pair.second == 4)
		{
			pair.second = RPC::Rock;
		}
		if ((int)pair.second == 0)
		{
			pair.second = RPC::Scissors;
		}
		part2.push_back(pair);
	}
}

int RockPaperScissors::calculateScore(std::pair<RPC, RPC>& pair)
{
	int ret = 0;
	if (pair.first == pair.second)
	{
		// draw
		ret += 3;
	}
	else if (pair.second == RPC::Rock && pair.first == RPC::Scissors ||
		pair.second == RPC::Scissors && pair.first == RPC::Paper ||
		pair.second == RPC::Paper && pair.first == RPC::Rock)
	{
		// win
		ret += 6;
	}
	else
	{
		// loss
	}
	return ret += (int)pair.second;

}

int RockPaperScissors::GetTotalScorePart1()
{
	int score = 0;
	for (auto play : part1)
	{
		score += calculateScore(play);
	}
	return score;
}

int RockPaperScissors::GetTotalScorePart2()
{
	int score = 0;
	for (auto play : part2)
	{
		score += calculateScore(play);
	}
	return score;
}

