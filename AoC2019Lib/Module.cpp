#include "pch.h"
#include "Module.h"

Module::Module(uint mass)
	: mMass(mass)
{
}

int Module::calculateFuel(uint mass) const
{
	 return (int)((mass / 3) - 2);
}

uint Module::calculateTotalFuel(uint mass)
{
	int fuel = calculateFuel(mass);
	if (fuel > 0) {
		return fuel + calculateTotalFuel(fuel);
	} else {
		return 0;
	}
}

uint Module::FuelRequired()
{
	return calculateFuel(mMass);
}

uint Module::TotalFuelRequired()
{
	return calculateTotalFuel(mMass);
}
