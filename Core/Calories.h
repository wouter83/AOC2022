#pragma once
#include <vector>
#include <string>


class Calories
{
public:
	int getTotalCalories();

private:
	std::vector<int> carried;
};

class Calorie_Counting
{
public:
	bool parseInput(const std::string& str);
	bool parse(int i);
private:
	std::vector<Calories> cal;

};