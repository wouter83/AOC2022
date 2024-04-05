#pragma once
#include <Generic.h>

class Planet
{
public:
	std::string name;
	Planet* orbit = nullptr;
	bool operator ==(const Planet& other)
	{
		return name == other.name;
	}
	void GetOrbits(std::vector<Planet*>& planets);
};

class OrbitMap
{
public:
	explicit OrbitMap(const std::string& str);
	~OrbitMap();
	uint GetOrbit();
	uint GetShortest();
private:
	std::vector<Planet*> mPLanets;
};

