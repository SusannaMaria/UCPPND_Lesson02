#include "gtest/gtest.h"
#include "astar_maze.hpp"

TEST(compare_1, lessons3)
{
    vector<int> test_1 {1, 2, 5, 6};
    vector<int> test_2 {1, 3, 5, 7};
    vector<int> test_3 {1, 2, 5, 8};
    vector<int> test_4 {1, 3, 5, 7};

    ASSERT_FALSE(Compare(test_1, test_2));
    ASSERT_TRUE(Compare(test_3, test_4));
}