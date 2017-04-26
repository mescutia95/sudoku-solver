#include <iostream>
#include "solver.h"

// program reads input_file from command line argument
int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    cerr << "Error: not enough arguments\n";
    exit(1);
  }
  
  Solver solver;
  solver.parse_input(argv[1]);
  solver.solve_sudoku();
  solver.print_grid();
  
  return 0;
}
