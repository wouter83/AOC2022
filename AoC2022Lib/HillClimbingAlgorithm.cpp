#include "pch.h"
#include "HillClimbingAlgorithm.h"
#include "../Generic/Generic.h"
#include <algorithm>

HillClimbingAlgorithm::HillClimbingAlgorithm(const std::string& input)
{
	for (auto inp : Generic::splitString(input, "\n"))
	{
		std::vector<char> HillLine;
		for (auto c : inp)
		{
			if (c == 'S')
			{
				startCord.y = Hills.size();
				startCord.x = HillLine.size();
				c = 'a';
			}
			if (c == 'E')
			{
				stopY = Hills.size();
				stopX = HillLine.size();
				c = 'z';
			}
			if (c == 'a')
			{
				aCords.push_back(Cord(HillLine.size(), Hills.size()));
			}
			HillLine.push_back(c);

		}
		Hills.push_back(HillLine);
		maxX = HillLine.size();
	}
	maxY = Hills.size();

}

HillClimbingAlgorithm::~HillClimbingAlgorithm()
{
	
	for (auto h : Hills)
	{
		h.clear();
	}
}

void HillClimbingAlgorithm::Dijkstra(Cord cord, std::vector<std::vector<Vertex*>>& verticis)
{
	/*
	A.	Geef de beginknoop voorlopig afstand 0 (dat noemen we de huidige knoop) en alle andere knopen voorlopige afstand ? (die noemen we niet-bezochte knopen).

	B.	Bekijk alle directe buren van de huidige knoop. Voor elk van die knopen kun je twee afstanden vinden:
	1.  de voorlopige afstand die er al bij staat
	2.  de voorlopige afstand van de huidige knoop plus de lengte van de verbindingslijn vanaf de huidige knoop naar deze

	Kies de kortste afstand van beiden. Dat wordt de nieuwe voorlopige afstand van deze knoop.

	C.	Als je alle buurknopen hebt gehad wordt de huidige knoop nu een bezochte knoop.
	Kies als nieuwe huidige knoop de knoop met de kleinste voorlopige afstand.
	Ga weer naar stap B.
	*/


// A
	size_t x = cord.x;
	size_t y = cord.y;
	Vertex* start = verticis[y][x];
	start->dist = 0;
	std::unordered_set<Vertex*> VertexEvaluated;
	start->cord = Cord(x, y);
//B

	do
	{
		if (VertexEvaluated.size() > 0)
		{
			start = nullptr;
			for (auto p : VertexEvaluated)
			{
				if (!start)
					start = p;
				if (start && start->dist > p->dist)
				{
					start = p;
				}
			}
			VertexEvaluated.erase(start);
		}
		if (start)
		{
			start->visited = true;

			size_t x = start->cord.x;
			size_t y = start->cord.y;
			char startChar = Hills[y][x];

			if (y != 0)
			{//eval vortex above
				size_t i = x;
				size_t j = y - 1;
				checkVortex(j, i, startChar, start, VertexEvaluated, verticis);
			}
			if (x + 1 < maxX)
			{//eval vortex right
				size_t i = x + 1;
				size_t j = y;
				checkVortex(j, i, startChar, start, VertexEvaluated, verticis);
			}

			if (y + 1 < maxY)
			{//eval vortex under
				size_t i = x;
				size_t j = y + 1;
				checkVortex(j, i, startChar, start, VertexEvaluated, verticis);
			}
			if (x != 0)
			{//eval vortex left
				size_t i = x - 1;
				size_t j = y;
				checkVortex(j, i, startChar, start, VertexEvaluated, verticis);
			}
		}

// C repeat
	} while (VertexEvaluated.size() > 0);
}

void HillClimbingAlgorithm::checkVortex(size_t j, size_t i, char startChar, Vertex* start, std::unordered_set<Vertex*>& VertexEvaluated, std::vector<std::vector<Vertex*>>& verticis)
{
	Vertex* evalVortex = verticis[j][i];
	if (!evalVortex->visited && Hills[j][i] - 1 <= startChar)
	{
		evalVortex->dist = start->dist + 1;
		evalVortex->cord = Cord(i, j);
		if (!evalVortex->visited)
			VertexEvaluated.insert(evalVortex);
	}
}

void HillClimbingAlgorithm::makeVerticis(std::vector<std::vector<Vertex*>>& verticis)
{
	for (auto& h : Hills)
	{
		std::vector<Vertex*> vertexLine;
		for (auto hh : h)
		{
			vertexLine.push_back(new Vertex());
		}
		verticis.push_back(vertexLine);
	}
}

size_t HillClimbingAlgorithm::GetLeasStepsToEnd()
{
	std::vector<std::vector<Vertex*>> verticis;
	makeVerticis(verticis);

	Dijkstra(startCord, verticis);
	
	size_t ret = verticis[stopY][stopX]->dist;
	ClearVerticis(verticis);

	return ret;
}

size_t HillClimbingAlgorithm::GetLeasStepsToEndNonScenic()
{
	size_t ret = ULLONG_MAX;
	for (Cord a : aCords)
	{
		std::vector<std::vector<Vertex*>> verticis;
		makeVerticis(verticis);

		Dijkstra(a, verticis);

		size_t steps = verticis[stopY][stopX]->dist;
		ret = std::min(steps, ret);
		ClearVerticis(verticis);
	}
	return ret;
}

void HillClimbingAlgorithm::ClearVerticis(std::vector<std::vector<Vertex*>>& verticis)
{
	for (auto& p : verticis)
	{
		for (auto pp : p)
		{
			delete pp;
		}
		p.clear();
	}
}