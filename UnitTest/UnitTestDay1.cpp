#include "pch.h"
#include "../Generic/Generic.h"
//#include <string>
//#include <vector>
#include "../Core/Calories.h"

TEST(Day1, calories)
{
	const std::string s1 = R"(
1000
2000
3000

4000

5000
6000

7000
8000
9000

10000
)";

	Calorie_Counting counting;
	counting.parseInput(s1);
}