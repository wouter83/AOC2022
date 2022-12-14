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
	void Dijkstra(size_t x, size_t y);
	void checkVortex(size_t j, size_t i, char startChar, Vertex* start, std::unordered_set<Vertex*>& VertexEvaluated);
	inline size_t GetLeasStepsToEnd() { return verticis[stopY][stopX]->dist; }

private:
	std::vector<std::vector<char>> Hills;
	std::vector<std::vector<Vertex*>> verticis;

	size_t stopX{}, stopY{};
	size_t maxX{}, maxY{};
};
