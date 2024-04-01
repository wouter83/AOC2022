#pragma once
#include <vector>

class LanternfishSwarm
{
public:
	void input(std::vector<size_t>& input);
	size_t parse(int days);

private:
	std::vector<size_t> AllTheFish;
};
