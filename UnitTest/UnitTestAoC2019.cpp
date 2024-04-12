#include "pch.h"
#include <CounterUpper.h>
#include <IntProc.h>
#include <CrossedWires.h>
#include <Password.h>
#include <OrbitMap.h>
#include <PhaseComputer.h>

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
		std::vector<int> test1 = { 1, 0, 0, 0, 99 };
		std::vector<int> test2 = { 2, 0, 0, 0, 99 };
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
		std::vector<int> test1 = { 2,3,0,3,99 };
		std::vector<int> test2 = { 2,3,0,6,99 };
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
		std::vector<int> test1 = { 2,4,4,5,99,0 };
		std::vector<int> test2 = { 2,4,4,5,99,9801 };
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
		std::vector<int> test1 = { 1,1,1,4,99,5,6,0,99 };
		std::vector<int> test2 = { 30,1,1,4,2,5,6,0,99 };
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
		std::vector<int> test1 = { 1, 9, 10, 3, 2, 3, 11, 0, 99, 30, 40, 50 };
		std::vector<int> test2 = { 3500,9,10,70,2,3,11,0,99,30,40,50 };
		ASSERT_EQ(proc.Memory(), test1);
		proc.Run();
		ASSERT_EQ(proc.Memory(), test2);
	}

	TEST(Day3, wires_1)
	{
		std::string wire1 = "R8,U5,L5,D3";
		std::string wire2 = "U7,R6,D4,L4";
		CrossedWires wire;
		wire.LoadWires(wire1, wire2);

		int closedCross = 0;
		int shortestCross = 0;
		wire.RunWires(closedCross, shortestCross);
		ASSERT_EQ(6, closedCross);
		ASSERT_EQ(30, shortestCross);
	}

	TEST(Day3, wires_2)
	{
		std::string wire1 = "R3,D2,L5";
		std::string wire2 = "U1,L1,D4";

		CrossedWires wire;

		wire.LoadWires(wire1, wire2);

		int closedCross = 0;
		int shortestCross = 0;
		wire.RunWires(closedCross, shortestCross);

		ASSERT_EQ(3, closedCross);

	}

	TEST(Day3, wires_3)
	{
		std::string wire1 = "R2,D2,L4,U4";
		std::string wire2 = "U3,L3,D1,R1";

		CrossedWires wire;

		wire.LoadWires(wire1, wire2);

		int closedCross = 0;
		int shortestCross = 0;
		wire.RunWires(closedCross, shortestCross);
		ASSERT_EQ(4, closedCross);
	}

	TEST(Day3, wires_4)
	{
		std::string wire1 = "R75,D30,R83,U83,L12,D49,R71,U7,L72"; // col = 134, row = 
		std::string wire2 = "U62,R66,U55,R34,D71,R55,D58,R83";
		CrossedWires wire;

		wire.LoadWires(wire1, wire2);

		int closedCross = 0;
		int shortestCross = 0;
		wire.RunWires(closedCross, shortestCross);
		ASSERT_EQ(159, closedCross);
		ASSERT_EQ(610, shortestCross);
	}

	TEST(Day3, wires_5)
	{
		std::string wire1 = "R98,U47,R26,D63,R33,U87,L62,D20,R33,U53,R51";
		std::string wire2 = "U98,R91,D20,R16,D67,R40,U7,R15,U6,R7";
		CrossedWires wire;
		wire.LoadWires(wire1, wire2);

		int closedCross = 0;
		int shortestCross = 0;
		wire.RunWires(closedCross, shortestCross);
		ASSERT_EQ(135, closedCross);
		ASSERT_EQ(410, shortestCross);
	}

	TEST(Day4, password)
	{
		Password p;
		std::string input = "122345";
		ASSERT_TRUE(p.Verify(input));

		input = "111123";
		ASSERT_FALSE(p.Verify(input));

		input = "135679";
		ASSERT_FALSE(p.Verify(input));

		input = "111111";
		ASSERT_FALSE(p.Verify(input));

		input = "223450";
		ASSERT_FALSE(p.Verify(input));

		input = "123789";
		ASSERT_FALSE(p.Verify(input));

		input = "112233";
		ASSERT_TRUE(p.Verify(input));

		input = "123444";
		ASSERT_FALSE(p.Verify(input));

		input = "111122";
		ASSERT_TRUE(p.Verify(input));

		input = "122333";
		ASSERT_TRUE(p.Verify(input));
	}

	TEST(Day5, IntProcessor_6)
	{
		const std::string s1 = R"(
3,0,4,0,99
)";
		IntProc proc(s1);
		InpOutp io;
		io.Input.push_back(100);
		proc.Run(io);

		EXPECT_EQ(io.Input, io.Output);
	}

	TEST(Day5, IntProcessor_7)
	{
		const std::string s1 = R"(
1002, 4, 3, 4, 33
)";
		IntProc proc(s1);
		proc.Run();
		EXPECT_EQ(proc.Memory().at(4), 99);
	}

	TEST(Day5, IntProcessor_8)
	{
		const std::string s1 = R"(
3,21,1008,21,8,20,1005,20,22,107,8,21,20,1006,20,31,
1106,0,36,98,0,0,1002,21,125,20,4,20,1105,1,46,104,
999,1105,1,46,1101,1000,1,20,4,20,1105,1,46,98,99
)";
		IntProc proc(s1);
		InpOutp io;
		io.Input.push_back(7);
		proc.Run(io);
		EXPECT_EQ(io.Output.front(), 999);
	}

	TEST(Day5, IntProcessor_9)
	{
		const std::string s1 = R"(
3,21,1008,21,8,20,1005,20,22,107,8,21,20,1006,20,31,
1106,0,36,98,0,0,1002,21,125,20,4,20,1105,1,46,104,
999,1105,1,46,1101,1000,1,20,4,20,1105,1,46,98,99
)";
		IntProc proc(s1);
		InpOutp io;
		io.Input.push_back(8);
		proc.Run(io);
		EXPECT_EQ(io.Output.front(), 1000);
	}
	TEST(Day5, IntProcessor_10)
	{
		const std::string s1 = R"(
3,21,1008,21,8,20,1005,20,22,107,8,21,20,1006,20,31,
1106,0,36,98,0,0,1002,21,125,20,4,20,1105,1,46,104,
999,1105,1,46,1101,1000,1,20,4,20,1105,1,46,98,99
)";
		IntProc proc(s1);
		InpOutp io;
		io.Input.push_back(9);
		proc.Run(io);
		EXPECT_EQ(io.Output.front(), 1001);
	}

	TEST(Day5, IntProcessor_11)
	{
		const std::string s1 = R"(
3,3,1105,-1,9,1101,0,0,12,4,12,99,1
)";
		IntProc proc(s1);
		InpOutp io;
		io.Input.push_back(0);
		proc.Run(io);
		EXPECT_EQ(io.Output.front(), 0);
	}

	TEST(day6, orbits)
	{
		const std::string s1 = R"(
COM)B
B)C
C)D
D)E
E)F
B)G
G)H
D)I
E)J
J)K
K)L
)";
		OrbitMap map(s1);
		EXPECT_EQ(map.GetOrbit(), 42);
	}
	TEST(day6, shortest)
	{
		const std::string s1 = R"(
COM)B
B)C
C)D
D)E
E)F
B)G
G)H
D)I
E)J
J)K
K)L
K)YOU
I)SAN
)";
		OrbitMap map(s1);
		EXPECT_EQ(map.GetShortest(), 4);
	}

	TEST(day7, phase_setting)
	{
		const std::string s1 = R"(
3,15,3,16,1002,16,10,16,1,16,15,15,4,15,99,0,0
)";	

		PhaseComputer pc(s1);
		pc.sequence("4,3,2,1,0");
		EXPECT_EQ(pc.getResult(), 43210);

	}

	TEST(day7, phase_setting_1)
	{
		const std::string s1 = R"(
3,23,3,24,1002,24,10,24,1002,23,-1,23,
101,5,23,23,1,24,23,23,4,23,99,0,0
)";

		PhaseComputer pc(s1);
		pc.sequence("0,1,2,3,4");
		EXPECT_EQ(pc.getResult(), 54321);

	}
}

