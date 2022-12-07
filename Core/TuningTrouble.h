#pragma once
#include <string>

class TuningTrouble
{
public:
	static int StartOf(const std::string& input, int size);
	static int StartOfPacket(const std::string& input);
	static int StartOfMessage(const std::string& input);
};

