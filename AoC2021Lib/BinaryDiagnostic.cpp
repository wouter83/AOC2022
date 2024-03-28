#include "pch.h"
#include "BinaryDiagnostic.h"

bool parseForOne(std::string& line, uint32_t index)
{
	return line[index] == '1';
}

void parse(std::vector<std::string>& input, std::vector<uint32_t>& ones, std::vector<uint32_t>& zeroes)
{
	for (auto line : input)
	{
		for (int i = 0; i < line.size(); ++i)
		{
			if (zeroes.size() <= i)
			{
				zeroes.push_back(0);
				ones.push_back(0);
			}
			if (parseForOne(line, i))
			{
				++ones[i];
			}
			else
			{
				++zeroes[i];
			}
		}
	}
}

uint32_t parseForGamma(std::vector<std::string>& input, uint32_t& mask)
{
	std::vector<uint32_t> ones;
	std::vector<uint32_t> zeroes;

	parse(input, ones, zeroes);

	uint32_t gamma = 0;

	for (int i = 0; i < ones.size(); ++i)
	{
		mask += 1 << i;
		if (ones[i] > zeroes[i])
		{
			gamma += 1 << (zeroes.size() - 1 - i);
		}
	}
	return gamma;
}

uint32_t parseForOxygen(std::vector<std::string>& input, bool normal)
{
	std::vector<uint32_t> ones;
	std::vector<uint32_t> zeroes;

	std::vector<std::string> intermediate;
	std::vector<std::string> output = input;
	uint32_t index = 0;

	do {
		ones.clear();
		zeroes.clear();
		intermediate.clear();
		parse(output, ones, zeroes);
		bool one = false;

		if (normal)
		{
			if (ones[index] >= zeroes[index])
			{
				one = normal;
			}
		}
		else
		{
			if (zeroes[index] > ones[index])
			{
				one = !normal;
			}
		}

		for (auto line : output)
		{
			if (parseForOne(line, index) && one)
			{
				intermediate.push_back(line);
			}
			if (!parseForOne(line, index) && !one)
			{
				intermediate.push_back(line);
			}
		}
		++index;
		output.clear();
		output = intermediate;


	} while (output.size() != 1);

	std::string oxygenStr = output[0];
	uint32_t oxygen = 0;
	for (int i = 0; i < oxygenStr.size(); ++i)
	{
		if (parseForOne(oxygenStr, i))
		{
			oxygen += 1 << (oxygenStr.size() - 1 - i);
		}
	}
	return oxygen;
}

void BinaryDiagnostic::input(std::vector<std::string>& input)
{
	uint32_t mask = 0;
	mGamma = parseForGamma(input, mask);
	mEpsilon = mask & ~mGamma;

	mOxygen = parseForOxygen(input, true);
	mCO2 = parseForOxygen(input, false);
}

int BinaryDiagnostic::powerConsumption()
{
	return mGamma * mEpsilon;
}

int BinaryDiagnostic::lifeSupportRating()
{
	return mOxygen * mCO2;
}