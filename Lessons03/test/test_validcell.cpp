#include "gtest/gtest.h"
#include "astar_maze.hpp"

TEST(validcell_1, lessons3)
{
  vector<vector<State>> grid{{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kClosed, State::kClosed, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}};
    ASSERT_FALSE(CheckValidCell(0, 0, grid));
    ASSERT_TRUE(CheckValidCell(4, 2, grid));
    ASSERT_FALSE(CheckValidCell(-1, 2, grid));
    ASSERT_FALSE(CheckValidCell(3, 100, grid));
    ASSERT_TRUE(CheckValidCell(3, 5, grid));
}



