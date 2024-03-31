#include "pch.h"
#include "CounterUpper.h"

CounterUpper::CounterUpper(const std::string& input)
{
	auto vals = Generic::splitString(input, "\n");
	for (auto val : vals)
	{
		AddModule(Generic::StringToInt(val));
	}
}

void CounterUpper::AddModule(uint val)
{
	Module mod(val);
	mod.SetId( mModules.size());
	mModules.push_back(mod);
}

uint CounterUpper::GetFuel() const
{
	uint totalFuel = 0;
	for (auto mod : mModules)
	{
		totalFuel += mod.FuelRequired();
	}
	return totalFuel;
}

uint CounterUpper::GetTotalFuel() const
{
	uint totalFuel = 0;
	for (auto mod : mModules)
	{
		totalFuel += mod.TotalFuelRequired();
	}
	return totalFuel;
}

uint CounterUpper::GetTotalMass()
{
	uint totalMass = 0;
	for (auto mod : mModules)
	{
		totalMass += mod.GetMass();
	}
	return totalMass;
}
