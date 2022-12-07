#include "pch.h"
#include "../Generic/Generic.h"
#include "../Core/Calories.h"
#include "../Core/RockPaperScissors.h"
#include "../Core/RuckSacks.h"
#include "../Core/CampCleanup.h"
#include "../Core/SupplyStacks.h"

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

	RuckSacks rs;

	ASSERT_EQ(rs.ParseForPriorityPerLine(s1), 157);
	ASSERT_EQ(rs.ParseForPriorityPerGroup(s1), 70);

}

TEST(Day4, CampCleanupTest)
{
	const std::string s1 = R"(
2-4,6-8
2-3,4-5
5-7,7-9
2-8,3-7
6-6,4-6
2-6,4-8
)";


	Assignments a(2, 8);
	Assignments b(3, 7);
	ASSERT_TRUE(a.fullyContains(b));

	Assignments c(5, 7);
	Assignments d(7, 9);
	ASSERT_TRUE(c.hasOverlap(d));

	CampCleanup CC(s1);
	ASSERT_EQ(CC.GetTotalFully(), 2);
	ASSERT_EQ(CC.GetTotalOverlap(), 4);

}

TEST(Day5, SupplyStackTest)
{
	const std::string s1 = R"(
    [D]    
[N] [C]    
[Z] [M] [P]
 1   2   3 

move 1 from 2 to 1
move 3 from 1 to 3
move 2 from 2 to 1
move 1 from 1 to 2
)";

	SupplyStacks CM9000(s1);
	ASSERT_EQ(CM9000.GetBoxesAfterRearranging(true), "CMZ");
	
	SupplyStacks CM9001(s1);
	ASSERT_EQ(CM9001.GetBoxesAfterRearranging(false), "MCD");
}