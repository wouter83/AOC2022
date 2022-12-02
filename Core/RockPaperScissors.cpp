#include "pch.h"
#include "RockPaperScissors.h"
#include "../Generic/Generic.h"
#include <utility>

#include <iostream>


bool RockPaperScissors::parseInput(const std::string& str)
{
    std::vector<std::string> turns = Generic::splitString(str, "\n");
    for (auto turn : turns)
    {
        std::vector<std::string> chars = Generic::splitString(turn, " ");

        part1.push_back(std::make_pair((RPC)(chars[0].c_str()[0] - 0x40), (RPC)(chars[1].c_str()[0] - 0x57)));
    }

    return false;
}

int RockPaperScissors::GetTotalScore()
{
    int score = 0;
    for (auto play : part1)
    {
        if (play.first == play.second)
        {
            // draw
            score += 3;
        }
        else if (play.second == RPC::Rock && play.first == RPC::Scissors ||
                 play.second == RPC::Scissors && play.first == RPC::Paper ||
                 play.second == RPC::Paper && play.first == RPC::Rock)
        {
            // win
            score += 6;
        }
        else
        {
            // loss
        }
        score += (int)play.second;

    }
    return score;
}
