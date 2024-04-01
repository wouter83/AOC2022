#include "pch.h"
#include <DepthMeassurment.h>
#include <SubMarine.h>
#include <BinaryDiagnostic.h>
#include <BingoBoard.h>
#include <HydrothermalVents.h>
#include <Lanternfish.h>
#include <Crabs.h>
#include <SevenSegment.h>
#include <Generic.h>
#include <LowPoints.h>

namespace AoC2021
{
	TEST(Day1, increased)
	{
		unsigned int input[] = {
			199,
			200,
			208,
			210,
			200,
			207,
			240,
			269,
			260,
			263,
		};
		DepthMeassurment meassurment;
		std::vector<unsigned int> inputV(std::begin(input), std::end(input));
		meassurment.input(inputV);
		EXPECT_EQ(meassurment.increaseCount(), 7u);
		EXPECT_EQ(meassurment.threeSlideCount(), 5u);
	}

	TEST(Day2, Submarine)
	{
		std::string input[] = {
			"forward 5",
			"down 5",
			"forward 8",
			"up 3",
			"down 8",
			"forward 2",
		};

		std::vector<std::string> inp2(std::begin(input), std::end(input));
		SubMarine sub;
		sub.input(inp2);
		EXPECT_EQ(sub.HorDepth(), 150);
		EXPECT_EQ(sub.HorDepthAim(), 900);
	}

	TEST(Day3, Binary_Diagnostics)
	{
		std::string input[] = {
			"00100",
			"11110",
			"10110",
			"10111",
			"10101",
			"01111",
			"00111",
			"11100",
			"10000",
			"11001",
			"00010",
			"01010",
		};
		std::vector<std::string> inp(std::begin(input), std::end(input));

		BinaryDiagnostic bd;
		bd.input(inp);
		EXPECT_EQ(bd.powerConsumption(), 198);
		EXPECT_EQ(bd.lifeSupportRating(), 230);
	}

	TEST(Day4, Bingo)
	{
		std::string input[] = {
			"7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1",
			"",
			"22 13 17 11  0",
			" 8  2 23  4 24",
			"21  9 14 16  7",
			" 6 10  3 18  5",
			" 1 12 20 15 19",
			"",
			" 3 15  0  2 22",
			" 9 18 13 17  5",
			"19  8  7 25 23",
			"20 11 10 24  4",
			"14 21 16 12  6",
			"",
			"14 21 17 24  4",
			"10 16 15  9 19",
			"18  8 23 26 20",
			"22 11 13  6  5",
			" 2  0 12  3  7",
		};
		std::vector<std::string> inp(std::begin(input), std::end(input));

		BingoBoard bb;
		bb.input(inp);
		EXPECT_EQ(bb.getBingoAnswerBest(), 4512);
		EXPECT_EQ(bb.getBingoAnswerWorst(), 1924);
	}

	TEST(Day5, Hydrothermal_Venture_HV)
	{
		std::string input[] = {
			"0,9 -> 5,9",
			"8,0 -> 0,8",
			"9,4 -> 3,4",
			"2,2 -> 2,1",
			"7,0 -> 7,4",
			"6,4 -> 2,0",
			"0,9 -> 2,9",
			"3,4 -> 1,4",
			"0,0 -> 8,8",
			"5,5 -> 8,2",
		};
		std::vector<std::string> inp(std::begin(input), std::end(input));
		HydrothermalVents hv;
		hv.input(inp);


		EXPECT_EQ(hv.overlap(2), 5);
		//EXPECT_EQ(hv.(), 1924);
	}

	TEST(Day5, Hydrothermal_Venture_HVD)
	{
		std::string input[] = {
			"0,9 -> 5,9",
			"8,0 -> 0,8",
			"9,4 -> 3,4",
			"2,2 -> 2,1",
			"7,0 -> 7,4",
			"6,4 -> 2,0",
			"0,9 -> 2,9",
			"3,4 -> 1,4",
			"0,0 -> 8,8",
			"5,5 -> 8,2",
		};
		std::vector<std::string> inp(std::begin(input), std::end(input));
		HydrothermalVents hv;
		hv.input(inp, true);


		EXPECT_EQ(hv.overlap(2), 12);

	}

	TEST(Day6, FishesTest)
	{
		size_t input[] = {
			3,4,3,1,2
		};
		std::vector<size_t> inp(std::begin(input), std::end(input));

		LanternfishSwarm lf;
		lf.input(inp);

		EXPECT_EQ(lf.parse(18), 26);
		EXPECT_EQ(lf.parse(80 - 18), 5934);
		EXPECT_EQ(lf.parse(256 - 80), 26984457539);
	}

	TEST(Day7, Crabs_test)
	{
		size_t input[] = {
			16,1,2,0,4,2,7,1,2,14
		};
		std::vector<size_t> inp(std::begin(input), std::end(input));

		Crabs crabs;
		crabs.input(inp);

		EXPECT_EQ(crabs.moveToPosition(1), 41);
		EXPECT_EQ(crabs.moveToPosition(2), 37);
		EXPECT_EQ(crabs.moveToPosition(3), 39);
		EXPECT_EQ(crabs.moveToPosition(10), 71);
		EXPECT_EQ(crabs.getBestFuelCalc(), 37);

		EXPECT_EQ(crabs.moveToPosition(5, true), 168);
		EXPECT_EQ(crabs.moveToPosition(2, true), 206);
	}

	TEST(Day8, Segements_small)
	{
		std::string input[] = {
			"acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab | cdfeb fcadb cdfeb cdbaf"
		};
		std::vector<std::string> inp(std::begin(input), std::end(input));

		SevenSegment seven;
		seven.input(inp);

		EXPECT_EQ(seven.OneFourSevenEight(), 0);
		EXPECT_EQ(seven.OutputTotal(), 5353);
	}

	TEST(Day8, Segements_large)
	{
		std::string input[] = {
			"be cfbegad cbdgef fgaecd cgeb fdcge agebfd fecdb fabcd edb | fdgacbe cefdb cefbgd gcbe",
			"edbfga begcd cbg gc gcadebf fbgde acbgfd abcde gfcbed gfec | fcgedb cgb dgebacf gc",
			"fgaebd cg bdaec gdafb agbcfd gdcbef bgcad gfac gcb cdgabef | cg cg fdcagb cbg",
			"fbegcd cbd adcefb dageb afcb bc aefdc ecdab fgdeca fcdbega | efabcd cedba gadfec cb",
			"aecbfdg fbg gf bafeg dbefa fcge gcbea fcaegb dgceab fcbdga | gecf egdcabf bgf bfgea",
			"fgeab ca afcebg bdacfeg cfaedg gcfdb baec bfadeg bafgc acf | gebdcfa ecba ca fadegcb",
			"dbcfg fgd bdegcaf fgec aegbdf ecdfab fbedc dacgb gdcebf gf | cefg dcbef fcge gbcadfe",
			"bdfegc cbegaf gecbf dfcage bdacg ed bedf ced adcbefg gebcd | ed bcgafe cdgba cbgef",
			"egadfb cdbfeg cegd fecab cgb gbdefca cg fgcdab egfdb bfceg | gbdfcae bgc cg cgb",
			"gcafb gcf dcaebfg ecagb gf abcdeg gaef cafbge fdbac fegbdc | fgae cfgab fg bagce"
		};
		std::vector<std::string> inp(std::begin(input), std::end(input));

		SevenSegment seven;
		seven.input(inp);

		EXPECT_EQ(seven.OneFourSevenEight(), 26);
		EXPECT_EQ(seven.OutputTotal(), 61229);
	}

	TEST(Day9, Low_points)
	{
		std::string input[] = {
			"2199943210",
			"3987894921",
			"9856789892",
			"8767896789",
			"9899965678",
		};
		std::vector<std::string> inp(std::begin(input), std::end(input));

		LowPoints lp;
		lp.input(inp);

		EXPECT_EQ(lp.riskPoints(), 15);
		EXPECT_EQ(lp.bassins(), 1134);
	}

	TEST(Day9, Low_points_corners)
	{
		std::string input[] = {
			"01234543210",
			"12345654321",
			"23456765432",
			"34567876543",
			"45678987654",
			"56789998765",
			"45678987654",
			"34567876543",
			"23456765432",
			"12345654321",
			"01234543210",
		};
		std::vector<std::string> inp(std::begin(input), std::end(input));

		LowPoints lp;
		lp.input(inp);

		EXPECT_EQ(lp.riskPoints(), 4);
		//EXPECT_EQ(seven.OutputTotal(), 5353);
	}
}