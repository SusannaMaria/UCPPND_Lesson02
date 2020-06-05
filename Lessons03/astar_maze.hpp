#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State
{
    kEmpty,
    kObstacle
};


std::vector<vector<State>> Search(const vector<vector<State>> &board, int init[2], int goal[2]);
int Heuristic(int x1, int y1, int x2, int y2);
string CellString(State cell);
void PrintBoard(const vector<vector<State>> &board, const std::vector<vector<State>> &solution);
vector<State> ParseLine(string line);
vector<vector<State>> ReadBoardFile(const string &filename);
