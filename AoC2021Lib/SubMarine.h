#pragma once
#include <vector>
#include <string>
enum class Direction
{
	none,
	up,
	down,
	forward,
	backward,
};

typedef std::pair<Direction, unsigned int> DiveStep;

class SubMarine
{
public:
	void input(std::vector<std::string>& input);
	int HorDepth();
	int HorDepthAim();

private:
	std::vector<DiveStep> mSteps;
};


