#include "gtest/gtest.h"
#include "astar_maze.hpp"

TEST(Search_1, lessons3)
{
    int goal[2]{4, 5};

    const string filename = "/home/susanna/UCPPND_Lesson02/Lessons02/1.board";
    auto board = ReadBoardFile(filename);
  
    auto output = Search(board, goal, goal);
    vector<vector<State>> solution{{State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                            {State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty, State::kObstacle, State::kPath}};

    ASSERT_EQ(output,solution);
}



