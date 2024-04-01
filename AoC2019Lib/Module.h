#pragma once

#include <Generic.h>
class Module
{
public:
	explicit Module(uint mass);
	~Module() = default;
	uint FuelRequired();
	uint TotalFuelRequired();
	uint GetMass() const { return mMass; }
	void SetId(size_t id) { mId = id; }

private:
	int calculateFuel(uint mass) const;
	uint calculateTotalFuel(uint mass);

	uint mId = 0;
	uint mMass = 0;
};

