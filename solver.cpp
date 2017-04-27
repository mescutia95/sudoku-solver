#include "solver.h"

// initializes the char reference array (m_ref)
Solver::Solver()
{
  int i = 0;
  // add char values 0 to 9
  for(int c = 48; c <= 57; ++c)
  {
    m_ref[i] = c;
    ++i;
  }
  // add char values A to F
  for(int c = 65; c <= 70; ++c)
  {
    m_ref[i] = c;
    ++i;
  }
}

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

// check if row has no violations
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

// check if column has no violations
bool checkCol(char value, int colNum)
{
  
}

// check if block has no violations
bool Solver::checkBlock(char value, int rowNum, int colNum)
{
	int startRow = rowNum - rowNum%4;
	int startCol = colNum - colNum%4;
	
  for(int y = 0; y < 4; ++y)
	{
		for(int x = 0; x < 4; ++x)
		{
			if(m_grid[x+startRow][y+startCol] == value)
				return false;
		}
	}
	return true;
}

// returns true if there are no violations for row, column, and, block
bool Solver::noViolations(char val, int rowNum, int colNum)
{
  return checkRow(val, rowNum) && checkCol(val, colNum) && checkBlock(val, rowNum, colNum);
}
