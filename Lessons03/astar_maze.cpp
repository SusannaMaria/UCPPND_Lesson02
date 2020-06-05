#include "astar_maze.hpp"


std::vector<vector<State>> Search(const vector<vector<State>> &board, int init[2], int goal[2]){
    std::vector<vector<State>> result;

    cout << "No path found!" << endl;

    return result;
}

int Heuristic(int x1, int y1, int x2, int y2){
    int result = abs(x1-x2)+abs(y1-y2);
    return result;
}

string CellString(State cell)
{
    switch (cell)
    {
    case State::kObstacle:
        return "⛰️ ";
    default:
        return "0 ";
    }
}

void PrintBoard(const vector<vector<State>> &board, const std::vector<vector<State>> &solution)
{
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            cout << CellString(cell) << " ";
        }
        cout << "\n";
    }
}

vector<State> ParseLine(string line)
{
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;

    // Testing to see if the stream was successful and printing results.
    while (sline >> n >> c && c == ',')
    {
        switch (n)
        {
        case 0:
            row.push_back(State::kEmpty);
            break;

        default:
            row.push_back(State::kObstacle);
            break;
        }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(const string &filename)
{
    std::ifstream my_file;
    my_file.open(filename);

    vector<vector<State>> board;

    if (my_file)
    {
        string line;

        while (getline(my_file, line))
        {
            auto row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}
