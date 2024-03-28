#pragma once
#include <vector>
#include <map>

class Crabs
{
public:
	void input(std::vector<size_t>& inp);
	size_t moveToPosition(size_t pos, bool linear = false);
	size_t getBestFuelCalc(bool linear = false);

private:
	std::map<size_t, size_t> crabs;
};

