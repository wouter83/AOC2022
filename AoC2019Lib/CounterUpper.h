#pragma once
#include <vector>
#include "Module.h"
#include <string>
#include <Generic.h>

class CounterUpper
{
public:
	explicit CounterUpper(const std::string& input);
	~CounterUpper() = default;
	void AddModule(uint val);
	uint GetFuel() const;
	uint GetTotalFuel() const;
	uint GetTotalMass();

private:
	std::vector<Module> mModules;
};

