#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::sort;
using std::abs;

enum class State
{
    kEmpty,
    kObstacle,
    kClosed,
    kPath
};


std::vector<vector<State>> Search(vector<vector<State>> &board, int init[2], int goal[2]);
int Heuristic(int x1, int y1, int x2, int y2);
string CellString(State cell);
void PrintBoard(const vector<vector<State>> &board, const std::vector<vector<State>> &solution);
vector<State> ParseLine(string line);
vector<vector<State>> ReadBoardFile(const string &filename);
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open_nodes, vector<vector<State>> &board);
void PrintVectorOfVectors(vector<vector<int>> v);
void PrintVectorOfVectors(vector<vector<State>> v);
bool Compare(const vector<int> &a, const vector<int> &b);
void CellSort(vector<vector<int>> *v);
bool CheckValidCell(int x, int y, vector<vector<State>> &board);
