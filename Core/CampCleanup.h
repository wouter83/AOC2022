#pragma once
#include <string>

struct Assignments
{
	Assignments(int min, int max) : Min(min), Max(max) {};
	bool fullyContains(const Assignments& other);
	bool hasOverlap(const Assignments& other);
	int Min;
	int Max;

};

class CampCleanup
{
public:
	CampCleanup(const std::string& input);
	int GetTotalFully();
	int GetTotalOverlap();
private:
	std::vector< std::pair<Assignments, Assignments>> AssignmentPairs;

};

