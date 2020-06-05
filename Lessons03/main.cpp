#include "astar_maze.hpp"
int main()
{
    const string filename = "/home/susanna/UCPPND_Lesson02/Lessons02/1.board";
    auto board = ReadBoardFile(filename);

    int init[2]{0, 0};
    int goal[2]{4, 5};
    auto solution = Search(board, init, goal);
    PrintBoard(board, solution);
}