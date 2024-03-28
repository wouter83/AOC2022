#include "pch.h"
#include "Lanternfish.h"

void makeNewVector(std::vector<size_t>& vec)
{
	for (int i = 0; i <= 8; ++i)
	{
		vec.push_back(0);
	}
}

void LanternfishSwarm::input(std::vector<size_t>& input)
{
	 makeNewVector(AllTheFish);
	
	for (auto age : input)
	{
		for (size_t i = 0; i < AllTheFish.size();++i)
		{
			if (age == i)
			{
				++AllTheFish[i];
			}
		}
	}
}

size_t fishCount(std::vector<size_t>& fishes)
{
	size_t ret = 0;
	for (auto fish : fishes)
	{
		ret += fish;
	}
	return ret;
}

size_t LanternfishSwarm::parse(int days)
{
	
	for (int i = 1; i <= days; ++i)
	{
		std::vector<size_t> newList;
		makeNewVector(newList);

		for (size_t i=0;i < AllTheFish.size(); ++i)
		{
			if (i == 0)
			{
				newList[8] += AllTheFish[i];
				newList[6] += AllTheFish[i];
			}
			else
			{
				newList[i -1] += AllTheFish[i];
			}
		}
		AllTheFish = newList;
	}
	size_t count = fishCount(AllTheFish);
	return count;

}
