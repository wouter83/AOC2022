#include "pch.h"
#include "../Generic/Generic.h"
#include "RuckSacks.h"
#include <vector>

int RuckSacks::ParseForPriorityPerLine(const std::string& input)
{
	int value = 0;

	for (auto s : Generic::splitString(input, "\n")) {
		size_t strsize = s.length();
		std::string one = s.substr(0, strsize / 2);
		std::string two = s.substr(strsize / 2);

		for (auto kar : one) {
			if (two.find(kar) != std::string::npos) {
				if (kar >= 'a' && kar <= 'z') {
					value += (int)(kar - 0x60);
				}
				else {
					value += (int)(kar - 0x40) + 26;
				}
				break;
			}
		}
	}
	return value;
}

int findCharCount(std::string& str, char c)
{
	int count = 0;
	size_t strRet = 0;

	do
	{
		strRet = str.find(c, strRet);
		if (strRet != std::string::npos)
		{
			count++;
			strRet++;

		}

	} while (strRet != std::string::npos);
	return count;
}

int RuckSacks::ParseForPriorityPerGroup(const std::string& input)
{
	int value = 0;
	std::vector<std::string> inputVect = Generic::splitString(input, "\n");
	for (int i = 0; i < inputVect.size();) {
		// find char in i+1 && i+2
		for (char c : inputVect[i])
		{
			int str1Count = findCharCount(inputVect[i + 1], c);
			int str2Count = findCharCount(inputVect[i + 2], c);
					
			if (str1Count != 0 && str2Count != 0)
			{
				int charVlaue = 0;
				if (c >= 'a' && c <= 'z') {
					charVlaue += (int)(c - 0x60);
				}
				else {
					charVlaue += (int)(c - 0x40) + 26;
				}
				value += charVlaue;
				break;
			}
		}

		i += 3;
	}
	return value;
}
