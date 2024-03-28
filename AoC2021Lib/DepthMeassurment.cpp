#include "pch.h"
#include "DepthMeassurment.h"

void DepthMeassurment::input(std::vector<unsigned int>& input)
{
	unsigned int count = 0;

	depthMeasurement = input;
	for (unsigned int val : input)
	{
		if (count + 2 >= input.size())
		{
			continue;
		}
		threeSlideMeasurement.push_back(input[count] + input[count + 1] + input[count + 2]);
		count++;
	}
}

unsigned int DepthMeassurment::increaseCount()
{
	return parse(depthMeasurement);
}

unsigned int DepthMeassurment::threeSlideCount()
{
	return parse(threeSlideMeasurement);
}

unsigned int DepthMeassurment::parse(std::vector<unsigned int>& input)
{
	unsigned int previous = UINT_MAX;
	unsigned int ret = 0;
	for (unsigned int val : input)
	{
		if (val > previous)
		{
			++ret;
		}
		previous = val;
	}
	return ret;
}
