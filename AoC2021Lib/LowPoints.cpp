#include "pch.h"
#include "LowPoints.h"

void LowPoints::input(std::vector<std::string>& inp)
{

	if (inp.size())
	{
		lengthOfPoints = inp[0].size();
	}
	for (auto& line : inp)
	{
		for (auto c : line)
		{
			inpV.push_back(Points(c - 0x30,false));
		}
	}
}
 
// val is value to check(index) in input string
// return value is the index that is lower than the index value
size_t LowPoints::checkLowest(size_t index)
{
	size_t indexTocheck = 0;
	size_t row = (index + lengthOfPoints) / lengthOfPoints;
	size_t boundaryIndex = (row * lengthOfPoints) -1;
	bool neighbourSame = true;
	
	// first check index left
	if (index != 0)
	{
		indexTocheck = index - 1;

		neighbourSame &= inpV[index].first == inpV[indexTocheck].first;
		if (inpV[index].first > inpV[indexTocheck].first)
		{
			return checkLowest(indexTocheck);
		}
	}
	
	// check above
	if (index > lengthOfPoints)
	{
		indexTocheck = index - lengthOfPoints;
		neighbourSame &= inpV[index].first == inpV[indexTocheck].first;
		if (inpV[index].first > inpV[indexTocheck].first)
		{
			return checkLowest(indexTocheck);
		}
	}
	
	// check right
	if (index < boundaryIndex)
	{
		indexTocheck = index + 1;
		neighbourSame &= inpV[index].first == inpV[indexTocheck].first;
		if (inpV[index].first > inpV[indexTocheck].first)
		{
			return checkLowest(indexTocheck);
		}
	}
	
	// check under
	indexTocheck = index + lengthOfPoints;
	if (indexTocheck < inpV.size())
	{
		neighbourSame &= inpV[index].first == inpV[indexTocheck].first;
		if (inpV[index].first > inpV[indexTocheck].first)
		{
			return checkLowest(indexTocheck);
		}
	}

	// we have another corner case
	// what if we end up here because all surrounding are the same?
	if (!neighbourSame)
		inpV[index].second = true;
	return index;
}

size_t LowPoints::riskPoints()
{
	size_t ret = 0;
	for (int i = 0; i < inpV.size(); ++i)
	{
		if (!inpV[i].second)
		{
			checkLowest(i);
		}
	}

	for (auto& i : inpV)
	{
		if (i.second)
		{
			ret += i.first + 1;
		}
	}
	return ret;
}

void LowPoints::checkBassins(size_t index, std::list<size_t>& foundIndex)
{
	//size_t indexTocheck = 0;
	size_t row = (index + lengthOfPoints) / lengthOfPoints;
	size_t boundaryIndex = (row * lengthOfPoints) - 1;
	std::vector<size_t> indexToCheck;

	// first check index left
	if (index != 0)
	{
		indexToCheck.push_back(index - 1);
	}
	// check above
	if (index > lengthOfPoints)
	{
		indexToCheck.push_back(index - lengthOfPoints);
	}
	// check right
	if (index < boundaryIndex)
	{
		indexToCheck.push_back(index + 1);
	}

	//check under
	if (index + lengthOfPoints < inpV.size())
	{
		indexToCheck.push_back(index + lengthOfPoints);		
	}
	for (size_t i : indexToCheck)
	{
		if (inpV[index].first < inpV[i].first && inpV[i].first != 9)
		{
			checkBassins(i,foundIndex);
		}
	}

	foundIndex.push_back(index);
}


size_t LowPoints::bassins()
{
	size_t ret = 1;
	std::vector<size_t> pointsToCheck;
	for (int i = 0; i < inpV.size(); ++i)
	{
		if (inpV[i].second)
		{
			pointsToCheck.push_back(i);
		}
	}
	std::list<size_t> answers;
	for (auto i : pointsToCheck)
	{
		// this wil update the booleans!
		std::list<size_t> foundIndex;
		checkBassins(i, foundIndex);
		foundIndex.sort();
		foundIndex.unique();
		answers.push_back(foundIndex.size());
	}
	answers.sort();
	for (int i = 3; i > 0; --i)
	{
		ret *= answers.back();
		answers.pop_back();
	}

	return ret;
}