#include "pch.h"
#include "OrbitMap.h"


OrbitMap::OrbitMap(const std::string& str)
{
	auto orbitsPairs = Generic::splitString(str, "\n");


	for (const auto& orbit : orbitsPairs)
	{
		const auto& bodies = Generic::splitString(orbit, ")");
		
		std::string ownName = bodies[1];
		std::string orbitName = bodies[0];

		Planet* pOwn = nullptr;
		Planet* pOrbit = nullptr;

		for (Planet* planet : mPLanets)
		{
			if (planet->name == ownName)
			{
				pOwn = planet;
			}
			if (planet->name == orbitName)
			{
				pOrbit = planet;
			}
		}


		if (!pOrbit)
		{
			pOrbit = new Planet();
			pOrbit->name = orbitName;
			mPLanets.push_back(pOrbit);
		}

		if (!pOwn)
		{
			pOwn = new Planet();
			pOwn->name = ownName;
			mPLanets.push_back(pOwn);
		}

		pOwn->orbit = pOrbit;
	}
}

OrbitMap::~OrbitMap()
{
	for (Planet* planet : mPLanets)
	{
		delete planet;
	}
}

uint OrbitMap::GetOrbit()
{
	uint count = 0;
	for (Planet* planet : mPLanets)
	{
		count += planet->GetOrbits();
	}
	return count;
}

uint OrbitMap::GetShortest()
{
	Planet* pYou;
	Planet* pSan;
	for (Planet* planet : mPLanets)
	{
		if (planet->name == "YOU")
			pYou = planet;
		if (planet->name == "SAN")
			pSan = planet;
	}



	return uint();
}

uint Planet::GetOrbits()
{
	uint count = 0;
	if (orbit)
	{
		count++;
		count += orbit->GetOrbits();
	}
	return count;
}
