#pragma once
#include <string>
#include <list>
#include <vector>

struct Move
{
	Move(const std::string& str);
	int count = 0;
	int from = 0;
	int to = 0;
};

class SupplyStacks
{
public:
	SupplyStacks(const std::string& input);
	std::string GetBoxesAfterRearranging(bool singleOrder = true);
	std::string GetBoxesAfterRearrangingBack(bool singleOrder = true);
protected:
	void insertBox(const std::string& str, int stacknr);
	int getOffset(int stacknr);

private:
	std::list<char> stacks;
	std::list<int> stacksSizes;
	std::vector<Move> MovesList;

};

