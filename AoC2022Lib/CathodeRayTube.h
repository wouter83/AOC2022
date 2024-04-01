#pragma once
#include <string>
#include <vector>

enum class Operation
{
	noop,
	addx
};

struct CpuStep
{
	CpuStep(Operation O, int v) :Operation(O), value(v) {}
	Operation Operation;
	int value;
};

class CathodeRayTube
{
public:
	CathodeRayTube(const std::string& inp);
	int RunCpu();
	std::vector<std::string> RunCRT();
private:
	std::vector<CpuStep> Steps;

};

