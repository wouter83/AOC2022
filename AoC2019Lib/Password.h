#pragma once
#include <string>
class Password
{
public:
	bool Verify(const std::string& str);
private:
	bool boundarycheck(int number);
};

