#pragma once
#include <string>
#include <vector>

struct Step
{
	Step(char dir, int cnt) : directon(dir), count(cnt) {};
	char directon;
	int count;

};

class RopeSimulator
{
public:
	RopeSimulator(const std::string& input);
	~RopeSimulator();
	int Run();

private:
	std::vector<Step> steps;
};

