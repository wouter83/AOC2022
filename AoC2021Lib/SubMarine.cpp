#include "pch.h"
#include "SubMarine.h"
#include "Generic.h"

void SubMarine::input(std::vector<std::string>& input)
{
	for (auto line : input)
	{
		std::vector<std::string> lineV = Generic::splitString(line, " ");
		Direction dir = Direction::none;

		if (lineV[0] == "forward")
		{
			dir = Direction::forward;
		}
		else if (lineV[0] == "backward")
		{
			dir = Direction::backward;
		}
		else if (lineV[0] == "up")
		{
			dir = Direction::up;
		}
		else if (lineV[0] == "down")
		{
			dir = Direction::down;
		}

		DiveStep step;
		step.first = dir;
		step.second = std::strtol(lineV[1].c_str(), nullptr,0);
		mSteps.push_back(step);
	}
}

int SubMarine::HorDepth()
{
	int horizontal = 0;
	int depth = 0;

	for (auto& step : mSteps)
	{
		switch (step.first)
		{
		case Direction::forward:
			horizontal += step.second;
			break;
		case Direction::backward:
			horizontal -= step.second;
			break;
		case Direction::up:
			depth -= step.second;
			break;
		case Direction::down:
			depth += step.second;
			break;
		default:
			break;
		}
	}
	return horizontal * depth;
	
}

int SubMarine::HorDepthAim()
{
	int horizontal = 0;
	int depth = 0;
	int aim = 0;

	for (auto& step : mSteps)
	{
		switch (step.first)
		{
		case Direction::forward:
			depth += step.second * aim;
			horizontal += step.second;
			break;
		case Direction::backward:
			horizontal -= step.second;
			break;
		case Direction::up:
			aim -= step.second;
			break;
		case Direction::down:
			aim += step.second;
			break;
		default:
			break;
		}
	}
	return horizontal * depth;

}
