#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Solver
{
  public:
    Solver() {};
    void parse_input(string filename);
    void print_grid();
    void solve_sudoku();
    bool checkRow(int value, int rowNum);
    bool checkCol(int value, int colNum);
    bool checkBlock(int value, int rowNum, int colNum);
    
  private:
    class Cell
    {
      public:
        char m_value;
        bool m_fixed;
    };
    
    static const int n = 16;
    Cell m_grid[n][n]; // grid of cell objects
};
#endif
