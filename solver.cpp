#include "solver.h"

// function parses input file and inserts values into the grid
void Solver::parse_input(string filename)
{
  int x = 0; // column position
  int y = 0; // row position
  string line;
  char c;

  ifstream infile(filename);
  if(infile.is_open())
  {
    while( getline(infile, line) )
    {
      stringstream stream(line);
      while(stream >> c)
      {
        m_grid[x][y].m_value = c;
        if(c == '*')
          m_grid[x][y].m_fixed = false;
        else
          m_grid[x][y].m_fixed = true;
        ++x;
      }
      x = 0;
      ++y;
    }
  }
  infile.close();
}

void Solver::print_grid()
{
  // printing the m_grid
  for(int y = 0; y < n; ++y)
  {
    for(int x = 0; x < n; ++x)
    {
      cout << m_grid[x][y].m_value;
    }
    cout << endl;
  }
}

// function where backtracking algorithm will be implemented
void Solver::solve_sudoku()
{

}

bool Solver::checkRow(char value, int rowNum)
{
  for(int i = 0; i < 16; i++)
  {
    if(m_grid[rowNum][i].m_value == value)
    {
      return false;
    }
  }
  return true;
}

bool Solver::checkBlock(char value, int rowNum, int colNum)
{
  for(int y = 0; y < n; ++y)
	{
		for(int x = 0; x < n; ++x)
		{
			if(m_grid[x+rowNum][y+colNum] == value)
				return false;
		}
	}
	return true;
}