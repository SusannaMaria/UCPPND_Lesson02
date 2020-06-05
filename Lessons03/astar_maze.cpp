#include "astar_maze.hpp"

void PrintVectorOfVectors(vector<vector<int>> v) {
  for (auto row : v) {
    cout << "{ ";
    for (auto col : row) {
      cout << col << " ";
    }
    cout << "}" << "\n";
  }
}

void PrintVectorOfVectors(vector<vector<State>> v) {
  for (auto row : v) {
    cout << "{ ";
    for (auto col : row) {
      cout << CellString(col) << " ";
    }
    cout << "}" << "\n";
  }
}

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open_nodes, vector<vector<State>> &board){
    vector<int> node={x, y, g, h};
    open_nodes.push_back(node);
    board[x][y]=State::kClosed;
}

std::vector<vector<State>> Search(vector<vector<State>> &board, int init[2], int goal[2]){
    std::vector<vector<State>> result;

    // Create the vector of open nodes.
    vector<vector<int>> open {};
    int x = init[0];
    int y = init[1];
    int g = 0;
    int h = Heuristic(x,y,goal[0],goal[1]);
  
    AddToOpen(x,y,g,h, open, board);
    
    // while open vector is non empty
    while (!open.empty()) {
      CellSort(&open);
      auto curr_node = open.back();
      open.pop_back();

      board[curr_node[0]][curr_node[1]] = State::kPath;

      if ((curr_node[0] == goal[0]) && (curr_node[1] == goal[1])){
        return board;
      }
    } 
  
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

bool Compare(const vector<int> &a, const vector<int> &b){
  int f1 = a[2] + a[3]; // f1 = g1 + h1
  int f2 = b[2] + b[3]; // f2 = g2 + h2
  return f1 > f2;   
}

void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}