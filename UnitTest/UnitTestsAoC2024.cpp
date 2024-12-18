#include "pch.h"
#include <Generic.h>
#include <HistorianHysteria.h>
#include <RedNosedReports.h>

namespace AoC2024
{
	TEST(Day1, HH)
	{
		const std::string s1 = R"(
3   4
4   3
2   5
1   3
3   9
3   3
)";
		HistorianHysteria hh;
		hh.ParseInput(s1);
		EXPECT_EQ(hh.TotalDistance(), 11);
		EXPECT_EQ(hh.SimilarityScore(), 31);
	}

	TEST(Day2, RNR)
	{
		const std::string s1 = R"(
7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9
)";
		RedNosedReports rnr ;
		rnr.ParseInput(s1);
		EXPECT_EQ(rnr.ReturnSafeCount(), 2);
	}
}
