#include "pch.h"
#include "SupplyStacks.h"
#include "../Generic/Generic.h"


Move::Move(const std::string& str)
{
	// move 1 from 2 to 1
	auto strs = Generic::splitString(str, " ");
	count = Generic::StringToInt(strs[1]);
	from = Generic::StringToInt(strs[3]) - 1;
	to = Generic::StringToInt(strs[5]) - 1;
}

SupplyStacks::SupplyStacks(const std::string& input)
{
	auto inputs = Generic::splitString(input, "\n\n");
	std::string moves = inputs[1];
	for (auto move : Generic::splitString(moves, "\n"))
	{
		MovesList.push_back(Move(move));
	}

	for (auto line : Generic::splitString(inputs[0], "\n"))
	{
		size_t offset = 0;
		int counter = 0;
		do
		{
			auto box = line.substr(offset, 3);
			insertBox(box, counter);
			++counter;
			offset += 4;

		} while (offset < line.size());
	}

}

std::string SupplyStacks::GetBoxesAfterRearranging(bool singleOrder)
{
	std::string str;

	for (auto move : MovesList)
	{
		for (int i = 0; i < move.count; ++i)
		{
			int offset_from = getOffset(move.from - 1); // we want the beginning

			auto it_toget = stacks.begin();
			std::advance(it_toget, offset_from);
			char kar = *it_toget;
			stacks.erase(it_toget);

			auto it_stackSizes = stacksSizes.begin();
			std::advance(it_stackSizes, move.from);
			--(*it_stackSizes);

			int offset_to = getOffset(move.to - 1); // we want the beginning
			auto it_toput = stacks.begin();
			std::advance(it_toput, offset_to);
			stacks.insert(it_toput, kar);

			it_stackSizes = stacksSizes.begin();
			std::advance(it_stackSizes, move.to);
			++(*it_stackSizes);
		}
	}

	// get the top of each stack
	// the begin of the offset is the first of the stack
	auto it = stacks.begin();
	for (auto it_stackSizes : stacksSizes)
	{
		str.push_back(*it);
		std::advance(it, it_stackSizes);
	}

	return str;
}

std::string SupplyStacks::GetBoxesAfterRearrangingBack(bool singleOrder)
{
	std::string str;

	for (auto move : MovesList)
	{
		std::string tempstr;
		for (int i = 0; i < move.count; ++i)
		{
			int offset_from = getOffset(move.from - 1); // we want the beginning

			auto it_toget = stacks.begin();
			std::advance(it_toget, offset_from);
			char kar = *it_toget;
			stacks.erase(it_toget);

			auto it_stackSizes = stacksSizes.begin();
			std::advance(it_stackSizes, move.from);
			--(*it_stackSizes);

			tempstr.insert(0, 1, kar);
		}

		for (auto a : tempstr)
		{
			int offset_to = getOffset(move.to - 1); // we want the beginning
			auto it_toput = stacks.begin();
			std::advance(it_toput, offset_to);
			stacks.insert(it_toput, a);

			auto it_stackSizes = stacksSizes.begin();
			std::advance(it_stackSizes, move.to);
			++(*it_stackSizes);
		}
	}

	// get the top of each stack
	// the begin of the offset is the first of the stack
	auto it = stacks.begin();
	for (auto it_stackSizes : stacksSizes)
	{
		str.push_back(*it);
		std::advance(it, it_stackSizes);
	}

	return str;
}
int SupplyStacks::getOffset(int stacknr)
{
	int ret = 0;

	if (stacknr > stacksSizes.size())
		return 0;

	for (int i = 0; i <= stacknr; ++i)
	{
		auto it = stacksSizes.begin();
		std::advance(it, i);
		ret += *it;
	}
	return ret;
}

void SupplyStacks::insertBox(const std::string& str, int stacknr)
{
	if (stacknr >= stacksSizes.size())
		stacksSizes.push_back(0);

	auto it_stackSizes = stacksSizes.begin();
	std::advance(it_stackSizes, stacknr);


	if (Generic::hasChar(str, '[') && Generic::hasChar(str, ']'))
	{
		char kar = str[1];
		auto it_stacks = stacks.begin();
		std::advance(it_stacks, getOffset(stacknr));
		stacks.insert(it_stacks, kar);
		(*it_stackSizes)++;
	}
}

