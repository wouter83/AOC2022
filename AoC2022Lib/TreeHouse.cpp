#include "pch.h"
#include "TreeHouse.h"

#include "../Generic/Generic.h"
#include <algorithm>

TreeHouse::TreeHouse(const std::string& input)
{
	auto treelines = Generic::splitString(input, "\n");
	lengthOfPoints = treelines[0].size();
	for (auto treeline : treelines)
	{
		for (auto tree : treeline)
		{

			Forrest.push_back(tree - 0x30);
		}
	}
}

int TreeHouse::GetVisibleCount()
{
	int ret = 0;

	for (int i = 0; i < (Forrest.size() ); ++i)
	{
		int height = Forrest[i];

		// go up
		bool ok = true;
		for (int j = i - lengthOfPoints; j > 0;)
		{

			if (height > Forrest[j])
			{
				// we go again
				j -= lengthOfPoints;
			}
			else
			{
				//breakout
				ok = false;
				break;
			}
		}
		if (ok)
		{
			ret++;
			continue; // is visible from one side so no more checking
		}
		ok = true;

		// go left
		for (size_t j = i + 1; j < (((i / lengthOfPoints) * lengthOfPoints) + lengthOfPoints) ;)
		{
			if (height > Forrest[j])
			{
				// we go again
				++j;
			}
			else
			{
				//breakout
				ok = false;
				break;
			}
		}
		if (ok)
		{
			ret++;
			continue; // is visible from one side so no more checking
		}
		ok = true;

		//go down
		for (size_t j = i + lengthOfPoints; j < lengthOfPoints * lengthOfPoints;)
		{
			if (height > Forrest[j])
			{
				// we go again
				j += lengthOfPoints;
			}
			else
			{
				//breakout
				ok = false;
				break;
			}
		}
		if (ok)
		{
			ret++;
			continue; // is visible from one side so no more checking
		}
		ok = true;

		// go right
		for (size_t j = i - 1; j > ((i / lengthOfPoints) * lengthOfPoints) -1;)
		{
			if (height > Forrest[j])
			{
				// we go again
				--j;
			}
			else
			{
				//breakout
				ok = false;
				break;
			}
		}

		if (ok)
		{
			ret++;
			continue; // is visible from one side so no more checking
		}
	}

	return ret;
}


int TreeHouse::GetScenicCount()
{
	int ret = 0;
	for (int i = 0; i < (Forrest.size()); ++i)
	{
		int height = Forrest[i];
		int counts[4] = {};

		// go up
		bool ok = true;
		for (int j = i - lengthOfPoints; j > 0;)
		{
			if (height > Forrest[j])
			{
				// we go again
				j -= lengthOfPoints;
				counts[0]++;
			}
			else
			{
				counts[0]++;
				break;
			}
		}

		// go right
		for (size_t j = i + 1; j < (((i / lengthOfPoints) * lengthOfPoints) + lengthOfPoints);)
		{
			if (height > Forrest[j])
			{
				// we go again
				++j;
				counts[1]++;

			}
			else
			{
				counts[1]++;
				break;
			}
			
		}

		//go down
		for (size_t j = i + lengthOfPoints; j < lengthOfPoints * lengthOfPoints;)
		{
			if (height > Forrest[j])
			{
				// we go again
				j += lengthOfPoints;
				counts[2]++;

			}
			else
			{
				counts[2]++;
				break;
			}
		}

		// go left
		for (size_t j = i - 1; j > ((i / lengthOfPoints) * lengthOfPoints) - 1;)
		{
			if (height > Forrest[j])
			{
				// we go again
				--j;
				counts[3]++;
			}
			else
			{
				counts[3]++;
				break;
			}
		}
		ret = std::max(ret, counts[0] * counts[1] * counts[2] * counts[3]);

	}

	return ret;
}