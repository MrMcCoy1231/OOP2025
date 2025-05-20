#include "pch.h"
#include "functii.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Suita1deTeste, AlreadySorted) {
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	classicSort(vec);
	EXPECT_TRUE(isSorted(vec));
}

TEST(Suita1deTeste, ReverseSorted) {
	std::vector<int> vec = { 5, 4, 3, 2, 1 };
	classicSort(vec);
	EXPECT_TRUE(isSorted(vec));
}

TEST(Suita1deTeste, RandomOrder) {
	std::vector<int> vec = { 3, 1, 4, 2, 5 };
	classicSort(vec);
	EXPECT_TRUE(isSorted(vec));
}

TEST(Suita1deTeste, AllEqual) {
	std::vector<int> vec = { 7, 7, 7, 7 };
	classicSort(vec);
	EXPECT_TRUE(isSorted(vec));
}

TEST(Suita1deTeste, SingleElement) {
	std::vector<int> vec = { 42 };
	classicSort(vec);
	EXPECT_TRUE(isSorted(vec));
}

TEST(Suita1deTeste, EmptyVector) {
	std::vector<int> vec;
	classicSort(vec);
	EXPECT_TRUE(isSorted(vec));
}
