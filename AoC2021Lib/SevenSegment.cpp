#include "pch.h"
#include "SevenSegment.h"
#include "Generic.h"
#include <list>
#include <algorithm>
#include <assert.h>

void SevenSegment::input(std::vector<std::string>& inp)
{
	for (auto str : inp)
	{
		std::vector<std::string> inpLine = Generic::splitString(str, "|");

		if (inpLine.size() != 2)
			continue;
		splitInputValues.push_back(std::make_pair(inpLine[0], inpLine[1]));
	}
}

size_t SevenSegment::OneFourSevenEight()
{
	size_t ret = 0;
	for (auto inp : splitInputValues)
	{
		for (auto val : Generic::splitString(inp.second, " "))
		{
			switch (val.size())
			{
			case 2:
			case 3:
			case 4:
			case 7:
				ret += 1;
				break;
			default:
				break;
			}
		}
	}
	return ret;
}

size_t SevenSegment::OutputTotal()
{
	size_t ret = 0;
	for (auto inp : splitInputValues)
	{
		std::list<std::string> inputlist;
		for (auto val : Generic::splitString(inp.first, " "))
		{
			std::sort(val.begin(), val.end());
			inputlist.push_back(val);
		}
		assert(inputlist.size() == 10);

		std::map<int, std::string> numbers;
		for (auto val : inputlist)
		{
			if (val.size() == 2)
				numbers.insert(std::pair<int, std::string>(1, val));
			if (val.size() == 3)
				numbers.insert(std::pair<int, std::string>(7, val));
			if (val.size() == 4)
				numbers.insert(std::pair<int, std::string>(4, val));
			if (val.size() == 7)
				numbers.insert(std::pair<int, std::string>(8, val));
		}
		inputlist.remove(numbers.at(1));
		inputlist.remove(numbers.at(7));
		inputlist.remove(numbers.at(4));
		inputlist.remove(numbers.at(8));

		for (auto val : inputlist)
		{
			if (val.size() == 5 && Generic::hasChars(val, numbers.at(1)))
			{
				numbers.insert(std::pair<int, std::string>(3, val));
			}
		}
		inputlist.remove(numbers.at(3));

		for (auto val : inputlist)
		{
			if (val.size() == 6 && !Generic::hasChars(val, numbers.at(1)))
			{
				numbers.insert(std::pair<int, std::string>(6, val));
			}
		}
		inputlist.remove(numbers.at(6));

		for (auto val : inputlist)
		{
			if (val.size() == 6 && Generic::hasChars(val, numbers.at(3)))
			{
				numbers.insert(std::pair<int, std::string>(9, val));
			}
		}
		inputlist.remove(numbers.at(9));

		for (auto val : inputlist)
		{
			if (val.size() == 6 && !Generic::hasChars(val, numbers.at(6)) && !Generic::hasChars(val, numbers.at(9)))
			{
				numbers.insert(std::pair<int, std::string>(0, val));
			}
		}
		inputlist.remove(numbers.at(0));

		for (auto val : inputlist)
		{
			if (val.size() == 5 && Generic::hasChars(numbers.at(9), val))
			{
				numbers.insert(std::pair<int, std::string>(5, val));
			}
		}
		inputlist.remove(numbers.at(5));

		if (inputlist.size() == 1)
			numbers.insert(std::pair<int, std::string>(2, *inputlist.begin()));

		assert(numbers.size() == 10);

		// get the outp list
		std::vector<std::string> outputlist;
		for (auto val : Generic::splitString(inp.second, " "))
		{
			std::sort(val.begin(), val.end());
			outputlist.push_back(val);
		}
		assert(outputlist.size() == 4);

		int i = 3;
		for (auto outp : outputlist)
		{
			for (auto number : numbers)
			{
				if (number.second == outp)
				{
					ret += number.first * Generic::pow(10, i);
				}
			}
			--i;
		}
	}

	return ret;
}