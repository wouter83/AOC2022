#pragma once
#include <string>
#include <vector>

class BinaryDiagnostic
{
public:
	void input(std::vector<std::string>& input);

	int powerConsumption();
	int lifeSupportRating();

private:
	uint32_t mGamma = 0;
	uint32_t mEpsilon = 0;
	uint32_t mOxygen= 0;
	uint32_t mCO2 = 0;

};

