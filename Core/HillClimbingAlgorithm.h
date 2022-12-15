#pragma once
#include <string>
#include <vector>
#include <unordered_set>

struct Cord
{
	Cord() {};
	Cord(size_t x, size_t y) :x(x), y(y) {}
	size_t x{};
	size_t y{};
};

struct Vertex
{
	Vertex() {};
	size_t dist = ULLONG_MAX;
	Vertex* prev = nullptr;
	bool visited = false;
	Cord cord;
};

class HillClimbingAlgorithm
{
public:
	HillClimbingAlgorithm(const std::string& input);
	~HillClimbingAlgorithm();
	void Dijkstra(Cord cord, std::vector<std::vector<Vertex*>>& verticis);
	void checkVortex(size_t j, size_t i, char startChar, Vertex* start, std::unordered_set<Vertex*>& VertexEvaluated, std::vector<std::vector<Vertex*>>& verticis);
	size_t GetLeasStepsToEnd();
	size_t GetLeasStepsToEndNonScenic();
	void ClearVerticis(std::vector<std::vector<Vertex*>>& verticis);
	void makeVerticis(std::vector<std::vector<Vertex*>>& verticis);

private:
	std::vector<std::vector<char>> Hills;
	std::vector<Cord> aCords;
	Cord startCord;
	size_t stopX{}, stopY{};
	size_t maxX{}, maxY{};
};
