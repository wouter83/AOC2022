#pragma once
#include <vector>
#include <string>


class Elf
{
public:
	int getTotalCalories();

	std::vector<int> mCaloriesCarried;
};

class Calorie_Counting
{
public:
	bool parseInput(const std::string& str);
	int GetMostCalories();
	int GetTopThreeTotal();
	
private:
	std::vector<Elf> cal;

};