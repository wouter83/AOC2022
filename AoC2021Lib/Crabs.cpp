#include "pch.h"
#include "Crabs.h"
#include <iostream>

void Crabs::input(std::vector<size_t>& inp)
{
	for (auto i : inp)
	{
		auto ret = crabs.insert(std::pair<size_t,size_t>(i, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}
}

size_t Crabs::moveToPosition(size_t pos, bool linear)
{
	size_t ret = 0;
	for (auto crab : crabs)
	{
		if (crab.first != pos)
		{
			long long steps = crab.first - pos;
			steps = std::abs(steps);
			if (linear)
			{
				steps = steps * (1 + steps) / 2;
			}
			ret += crab.second * steps;
		}
	}

	return ret;
}

size_t Crabs::getBestFuelCalc(bool linear)
{
	size_t amountToCalc = crabs.rbegin()->first;
	size_t ret = ULLONG_MAX;
	for (int i = 0; i < +amountToCalc; ++i)
	{
		size_t val = moveToPosition(i, linear);
		if (val < ret)
			ret = val;
	}
	
	return ret;
}