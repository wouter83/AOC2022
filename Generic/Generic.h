#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>


using uint = size_t;

namespace Generic
{
	static std::vector<std::string> splitString(const std::string& str, const std::string& seperator)
	{
		std::vector<std::string> ret;
		size_t pos = 0;// std::string::npos;
		while (1)
		{
			size_t seppPos = str.substr(pos).find(seperator);
			std::string substr = str.substr(pos, seppPos);
			if (!substr.empty())
			{
				ret.push_back(substr);
			}
			if (seppPos == std::string::npos)
			{
				break;
			}
			pos += seppPos + seperator.size();
		}
		return ret;
	}

	static bool hasChar(const std::string& inp, char kar)
	{
		for (auto c : inp)
		{
			if (c == kar)
				return true;
		}
		return false;
	}

	static bool hasChars(const std::string& inp, std::string kars)
	{
		bool ret = true;
		for (auto c : kars)
		{
			ret &= hasChar(inp, c);
		}
		return ret;
	}

	// note: exp must be non-negative
	static std::int_fast64_t pow(int base, int exp)
	{
		std::int_fast64_t result{ 1 };
		while (exp)
		{
			if (exp & 1)
				result *= base;
			exp >>= 1;
			base *= base;
		}
		return result;
	}
	
	inline static int StringToInt(const std::string& str)
	{
		return std::strtol(str.c_str(), nullptr, 0);
	}

	static std::vector<std::vector<int>> generateAllUniquePermutations(int min, int max) {
		std::vector<int> nums;
		for (int i = min; i <= max; ++i) {
			nums.push_back(i);
		}

		std::vector<std::vector<int>> result;
		do {
			result.push_back(nums);
		} while (std::next_permutation(nums.begin(), nums.end()));

		return result;
	}

	static bool ReadFile(const std::string& filename, std::vector<std::string>& outp)
	{
		std::string line;
		std::ifstream infile(filename);
		if (!infile)
			return false;
		
		while (std::getline(infile, line))
		{
			outp.push_back(line);
		}
		return true;
	}
};
