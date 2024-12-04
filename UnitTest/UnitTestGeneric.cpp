#include "pch.h"
#include "../Generic/Generic.h"

namespace Generic
{
	TEST(TestCaseName, TestName) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(true);
	}

	TEST(GenericTest, SplitString)
	{
		std::string input = "een twee  drie";
		std::vector<std::string> outp = Generic::splitString(input, " ");
		ASSERT_EQ(outp.size(), 3);
		EXPECT_EQ(outp[0], "een");
		EXPECT_EQ(outp[1], "twee");
		EXPECT_EQ(outp[2], "drie");
	}

	TEST(GenericTest, generateAllUniquePermutations)
	{
		auto vect = Generic::generateAllUniquePermutations(1, 3);
		// 1,2,3
		// 1,3,2
		// 2,1,3
		// 2,3,1
		// 3,1,2
		// 3,2,1
		std::vector<int> test1 = { 1,2,3 };

		ASSERT_EQ(vect.size(), 6);
		EXPECT_EQ(vect[0], test1);
	}
}