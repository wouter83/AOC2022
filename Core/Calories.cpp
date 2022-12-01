#include "pch.h"
#include "Calories.h"
#include "../Generic/Generic.h"

int Calories::getTotalCalories()
{
    int ret = 0;
    for (int val : carried)
    {
        ret += val;
    }
    return ret;
}

bool Calorie_Counting::parseInput(const std::string& str)
{
    std::vector<std::string> parsed = Generic::splitString(str, "\n\n");
    for (auto p : parsed)
    {
        Generic::splitString(p, "\n");
    }
    return false;
}

bool Calorie_Counting::parse(int i)
{
    return i == 1;
}
