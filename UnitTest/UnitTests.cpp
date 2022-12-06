#include "pch.h"
#include "../Generic/Generic.h"
#include "../Core/Calories.h"
#include "../Core/RockPaperScissors.h"
#include "../Core/RuckSacks.h"

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
	ASSERT_EQ(counting.GetMostCalories(), 24000);
	ASSERT_EQ(counting.GetTopThreeTotal(), 45000);

}

TEST(Day2, rock_paper_scissors)
{
	const std::string s1 = R"(
A Y
B X
C Z
)";

	RockPaperScissors rpc;
	rpc.parseInput(s1);
	ASSERT_EQ(rpc.GetTotalScorePart1(), 15);
	ASSERT_EQ(rpc.GetTotalScorePart2(), 12);

}

TEST(Day3, RuckSackPriority)
{
	const std::string s1 = R"(
vJrwpWtwJgWrhcsFMMfFFhFp
jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
PmmdzqPrVvPwwTWBwg
wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
ttgJtRGJQctTZtZT
CrZsJsPPZsGzwwsLwLmpwMDw
)";

	const std::string s2 = R"(
a
aba
abb
)";
	RuckSacks rs;

	ASSERT_EQ(rs.ParseForPriorityPerLine(s1), 157);
	ASSERT_EQ(rs.ParseForPriorityPerGroup(s1), 70);

}