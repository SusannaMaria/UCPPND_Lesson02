#include "gtest/gtest.h"
#include "astar_maze.hpp"

TEST(Search_1, lessons3)
{
  int init[2]{0, 0};
  int goal[2]{4, 5};
  const string filename = "/home/susanna/UCPPND_Lesson02/Lessons02/1.board";
  auto board = ReadBoardFile(filename);

  vector<vector<State>> solution{{State::kStart, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                 {State::kPath, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                 {State::kPath, State::kObstacle, State::kEmpty, State::kClosed, State::kClosed, State::kClosed},
                                 {State::kPath, State::kObstacle, State::kClosed, State::kPath, State::kPath, State::kPath},
                                 {State::kPath, State::kPath, State::kPath, State::kPath, State::kObstacle, State::kFinish}};

  auto output = Search(board, init, goal);

  ASSERT_EQ(output, solution);
}
