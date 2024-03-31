#include "pch.h"
#include <CounterUpper.h>
#include <IntProc.h>

namespace AoC2019
{
	TEST(Day1, part_1)
	{
		Module mod1(12);
		EXPECT_EQ(mod1.FuelRequired(), 2);
		Module mod2(14);
		EXPECT_EQ(mod2.FuelRequired(), 2);
		Module mod3(1969);
		EXPECT_EQ(mod3.FuelRequired(), 654);
		EXPECT_EQ(mod3.TotalFuelRequired(), 966);

		CounterUpper up1("100756");
		EXPECT_EQ(up1.GetFuel(), 33583);
	}

	TEST(Day1, part_2)
	{
		CounterUpper up1("100756");
		EXPECT_EQ(up1.GetTotalFuel(), 50346);
	}

	TEST(Day2, IntProcessor_1)
	{
		const std::string s1 = R"(
1,0,0,0,99
)";
		IntProc proc(s1);
		std::vector<uint> test1 = { 1, 0, 0, 0, 99 };
		std::vector<uint> test2 = { 2, 0, 0, 0, 99 };
		ASSERT_EQ(proc.Memory(), test1);
		proc.Run();
		ASSERT_EQ(proc.Memory(), test2);
	}

	TEST(Day2, IntProcessor_2)
	{
		const std::string s1 = R"(
2,3,0,3,99
)";
		IntProc proc(s1);
		std::vector<uint> test1 = { 2,3,0,3,99 };
		std::vector<uint> test2 = { 2,3,0,6,99 };
		ASSERT_EQ(proc.Memory(), test1);
		proc.Run();
		ASSERT_EQ(proc.Memory(), test2);
	}

	TEST(Day2, IntProcessor_3)
	{
		const std::string s1 = R"(
2,4,4,5,99,0
)";
		IntProc proc(s1);
		std::vector<uint> test1 = { 2,4,4,5,99,0 };
		std::vector<uint> test2 = { 2,4,4,5,99,9801 };
		ASSERT_EQ(proc.Memory(), test1);
		proc.Run();
		ASSERT_EQ(proc.Memory(), test2);
	}

	TEST(Day2, IntProcessor_4)
	{
		const std::string s1 = R"(
1,1,1,4,99,5,6,0,99
)";
		IntProc proc(s1);
		std::vector<uint> test1 = { 1,1,1,4,99,5,6,0,99 };
		std::vector<uint> test2 = { 30,1,1,4,2,5,6,0,99 };
		ASSERT_EQ(proc.Memory(), test1);
		proc.Run();
		ASSERT_EQ(proc.Memory(), test2);
	}

	TEST(Day2, IntProcessor_5)
	{
		const std::string s1 = R"(
1, 9, 10, 3, 2, 3, 11, 0, 99, 30, 40, 50
)";
		IntProc proc(s1);
		std::vector<uint> test1 = { 1, 9, 10, 3, 2, 3, 11, 0, 99, 30, 40, 50 };
		std::vector<uint> test2 = { 3500,9,10,70,2,3,11,0,99,30,40,50 };
		ASSERT_EQ(proc.Memory(), test1);
		proc.Run();
		ASSERT_EQ(proc.Memory(), test2);
	}


}