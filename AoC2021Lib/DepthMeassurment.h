#pragma once
#include <vector>
class DepthMeassurment
{
public:
	void input(std::vector<unsigned int>& input);
	unsigned int increaseCount();
	unsigned int threeSlideCount();

protected:
	unsigned int parse(std::vector<unsigned int>& input);

private:
	unsigned int mIncCount = 0;
	std::vector<unsigned int> threeSlideMeasurement;
	std::vector<unsigned int> depthMeasurement;
};

