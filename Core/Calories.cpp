#include "pch.h"
#include "Calories.h"
#include "../Generic/Generic.h"
#include <algorithm>

int Elf::getTotalCalories()
{
    int ret = 0;
    for (int val : mCaloriesCarried)
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
        Elf elf;
        std::vector<std::string> vals = Generic::splitString(p, "\n");
        for (auto v : vals)
        {
            elf.mCaloriesCarried.push_back(Generic::StringToInt(v));
        }
        cal.push_back(elf);
    }
    return false;
}

int Calorie_Counting::GetMostCalories()
{
    int max = 0;
    for (auto c : cal)
    {
        max = std::max(c.getTotalCalories(), max);
    }
    return max;
}

int Calorie_Counting::GetTopThreeTotal()
{
    std::vector<int> values;
    for (auto c : cal)
    {
        values.push_back(c.getTotalCalories());
    }
    std::sort(values.begin(), values.end(), std::greater<int>());

    if (values.size() >= 3)
    {
        return values[0] + values[1] + values[2];
    }
}

