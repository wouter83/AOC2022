#include "pch.h"
#include <Generic.h>
#include <Calories.h>
#include <RockPaperScissors.h>
#include <RuckSacks.h>
#include <CampCleanup.h>
#include <SupplyStacks.h>
#include <TuningTrouble.h>
#include <FileSystem.h>
#include <TreeHouse.h>
#include <RopeSimulator.h>
#include <HillClimbingAlgorithm.h>
#include <CathodeRayTube.h>

namespace AoC2022
{
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

TEST(Day6, TuningTroubleTest)
{
	const std::string s1 = R"(mjqjpqmgbljsphdztnvjfqwrcgsmlb)";
	const std::string s2 = R"(bvwbjplbgvbhsrlpgdmjqwftvncz)";
	const std::string s3 = R"(nppdvjthqldpwncqszvftbrmjlhg)";
	const std::string s4 = R"(nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg)";
	const std::string s5 = R"(zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw)";

	EXPECT_EQ(TuningTrouble::StartOfPacket(s1), 7);
	EXPECT_EQ(TuningTrouble::StartOfPacket(s2), 5);
	EXPECT_EQ(TuningTrouble::StartOfPacket(s3), 6);
	EXPECT_EQ(TuningTrouble::StartOfPacket(s4), 10);
	EXPECT_EQ(TuningTrouble::StartOfPacket(s5), 11);

	EXPECT_EQ(TuningTrouble::StartOfMessage(s1), 19);
	EXPECT_EQ(TuningTrouble::StartOfMessage(s2), 23);
	EXPECT_EQ(TuningTrouble::StartOfMessage(s3), 23);
	EXPECT_EQ(TuningTrouble::StartOfMessage(s4), 29);
	EXPECT_EQ(TuningTrouble::StartOfMessage(s5), 26);
}

TEST(Day7, FileSystemTest)
{
	const std::string s1 = R"($ cd /
$ ls
dir a
14848514 b.txt
8504156 c.dat
dir d
$ cd a
$ ls
dir e
29116 f
2557 g
62596 h.lst
$ cd e
$ ls
584 i
$ cd ..
$ cd ..
$ cd d
$ ls
4060174 j
8033020 d.log
5626152 d.ext
7214296 k
)";

	FileSystem fs(s1);
	EXPECT_EQ(fs.getTotalSizeSpecifSize(100000), 95437);
	EXPECT_EQ(fs.getTotalDeleteSize(70000000, 30000000), 24933642);

}

TEST(Day8, TreesTest)
{
	const std::string s1 = R"(30373
25512
65332
33549
35390
)";

	TreeHouse treehouse(s1);
	EXPECT_EQ(treehouse.GetVisibleCount(), 21);
	EXPECT_EQ(treehouse.GetScenicCount(), 8);
}

TEST(Day9, RopeBridgeTest)
{
	const std::string s1 = R"(
R 4
U 4
L 3
D 1
R 4
D 1
L 5
R 2
)";

	RopeSimulator sim(s1);
	ASSERT_EQ(sim.Run(), 13);


	const std::string s2 = R"(
R 5
U 8
L 8
D 3
R 17
D 10
L 25
U 20
)";
		RopeSimulator sim1(s2);
		ASSERT_EQ(sim1.Run(9), 36);
}

TEST(Day10, CathodeRayTubeTest)
{
	const std::string s1 = R"(
addx 15
addx -11
addx 6
addx -3
addx 5
addx -1
addx -8
addx 13
addx 4
noop
addx -1
addx 5
addx -1
addx 5
addx -1
addx 5
addx -1
addx 5
addx -1
addx -35
addx 1
addx 24
addx -19
addx 1
addx 16
addx -11
noop
noop
addx 21
addx -15
noop
noop
addx -3
addx 9
addx 1
addx -3
addx 8
addx 1
addx 5
noop
noop
noop
noop
noop
addx -36
noop
addx 1
addx 7
noop
noop
noop
addx 2
addx 6
noop
noop
noop
noop
noop
addx 1
noop
noop
addx 7
addx 1
noop
addx -13
addx 13
addx 7
noop
addx 1
addx -33
noop
noop
noop
addx 2
noop
noop
noop
addx 8
noop
addx -1
addx 2
addx 1
noop
addx 17
addx -9
addx 1
addx 1
addx -3
addx 11
noop
noop
addx 1
noop
addx 1
noop
noop
addx -13
addx -19
addx 1
addx 3
addx 26
addx -30
addx 12
addx -1
addx 3
addx 1
noop
noop
noop
addx -9
addx 18
addx 1
addx 2
noop
noop
addx 9
noop
noop
noop
addx -1
addx 2
addx -37
addx 1
addx 3
noop
addx 15
addx -21
addx 22
addx -6
addx 1
noop
addx 2
addx 1
noop
addx -10
noop
noop
addx 20
addx 1
addx 2
addx 2
addx -6
addx -11
noop
noop
noop
)";
	CathodeRayTube tube(s1);
	EXPECT_EQ(tube.RunCpu(), 13140);
	
	const std::string s2 = R"(
##..##..##..##..##..##..##..##..##..##..
###...###...###...###...###...###...###.
####....####....####....####....####....
#####.....#####.....#####.....#####.....
######......######......######......####
#######.......#######.......#######.....
)";
	auto crt = tube.RunCRT();
	auto str = Generic::splitString(s2,"\n");

	for (int i = 0; i < crt.size(); ++i)
	{
		EXPECT_EQ(crt[i], str[i]);
	}

	
}

TEST(Day12, HillClimbingTest)
{
	const std::string s1 = R"(
Sabqponm
abcryxxl
accszExk
acctuvwj
abdefghi
)";


	HillClimbingAlgorithm hill_Climb(s1);
	EXPECT_EQ(hill_Climb.GetLeasStepsToEnd(), 31);
	EXPECT_EQ(hill_Climb.GetLeasStepsToEndNonScenic(), 29);
	
}
}