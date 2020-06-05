#include "gtest/gtest.h"
#include "astar_maze.hpp"

TEST(Heuristic_1, lessons3)
{
    ASSERT_EQ(Heuristic(1, 2, 3, 4), 4);
}

TEST(Heuristic_2, lessons3)
{
    ASSERT_EQ(Heuristic(2, -1, 4, -7), 8);
}