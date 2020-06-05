#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle};

string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️ ";
    default: return "0 "; 
  }
}

void PrintBoard(const vector<vector<State>> &board) {
    for(const auto &row : board){
        for(const auto &cell : row){
            cout << CellString(cell) << " ";
        }
        cout << "\n";
    }
}

vector<State> ParseLine(string line){
    istringstream sline(line);
    int n;   
    char c;
    vector<State> row;

    // Testing to see if the stream was successful and printing results.
    while (sline >> n >> c && c == ',') {
        switch(n){
            case 0: row.push_back(State::kEmpty);
            break;
            
            default: row.push_back(State::kObstacle);
            break;
        }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(const string &filename){
    std::ifstream my_file;
    my_file.open(filename);
    
    vector<vector<State>> board;

    if (my_file) {
        string line;
        
        while (getline(my_file, line)) {
            auto row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;

}

int main() {
    
    auto board=ReadBoardFile("/home/susanna/UCPPND_Lesson02/Lessons02/1.board");
    PrintBoard(board);
}