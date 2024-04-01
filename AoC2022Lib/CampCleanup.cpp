#include "pch.h"
#include "../Generic/Generic.h"
#include "CampCleanup.h"

bool Assignments::fullyContains(const Assignments& other)
{
	if (other.Min >= Min && other.Max <= Max)
		return true;
	return false;
}

bool Assignments::hasOverlap(const Assignments& other)
{
	if (other.Min > Max)
		return false;
	if (other.Max < Min)
		return false;
	
	if (other.Max >= Min)
		return true;
	if (other.Min >= Min)
		return true;
	return false;
}

CampCleanup::CampCleanup(const std::string& input)
{
	for (auto line : Generic::splitString(input, "\n"))
	{
		int min = 0, max = 0;
		auto minmax = Generic::splitString(line, ",");

		auto chars1 = Generic::splitString(minmax[0], "-");
		auto chars2 = Generic::splitString(minmax[1], "-");

		AssignmentPairs.push_back(std::make_pair(Assignments(Generic::StringToInt(chars1[0]), Generic::StringToInt(chars1[1])), Assignments(Generic::StringToInt(chars2[0]), Generic::StringToInt(chars2[1]))));
	}
}
int CampCleanup::GetTotalFully()
{
	int value = 0;
	for (auto pair : AssignmentPairs)
	{
		if (pair.first.fullyContains(pair.second) || pair.second.fullyContains(pair.first))
		{
			value++;
		}
	}

	return value;
}

int CampCleanup::GetTotalOverlap()
{
	int value = 0;
	for (auto pair : AssignmentPairs)
	{
		if (pair.first.hasOverlap(pair.second))
			value++;

	}
	return value;
}