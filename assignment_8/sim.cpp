#include <iostream>
#include <time.h>
#include <random>
#include "sim.h"

using namespace std;

void sim::initGrid()
{
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      Animal a;
      grid[i][j] = a;
    }
  }
  srand(time(0));
  int row, col;
  //Insert bug
  for (int i = 0; i < bugCount;)
  {
    row = rand() % 20;
    col = rand() % 20;
    Animal ani = grid[row][col];
    if (ani.getVal() == ' ')
    {
      Bug b;
      grid[row][col] = b;
      grid[row][col].setVal('x');
      i++;
    }
  }
  //Insert ants
  for (int i = 0; i < antCount;)
  {
    row = rand() % 20;
    col = rand() % 20;
    Animal ani = grid[row][col];
    if (ani.getVal() == ' ')
    {
      Ant a;
      grid[row][col] = a;
      grid[row][col].setVal('o');
      i++;
    }
  }
}

void sim::printGrid()
{
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      cout << grid[i][j].getVal() << " ";
    }
    cout << endl;
  }
}

void sim::step()
{
  srand(time(0));
  int direction = rand() % 4 + 1;
  // 1: left 2: right , 3:down, 4:up
  int row = (direction == 3) ? 1 : -1;
  int col = (direction == 2) ? 1 : -1;
  //First move bugs
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      if (grid[i][j].getVal() == 'x')
      {
        if (i + row < 20 && i + row >= 0 && j + col < 20 && j + col >= 0 && grid[i + row][j + col].getVal() != 'x')
        {
          grid[i + row][j + col].setSteps(grid[i + row][j + col].getSteps() + 1);
          if (grid[i + row][j + col].getVal() == '0')
          {
            antCount--;
            grid[i + row][j + col].starve = false;
          }
          grid[row][col].setVal(' ');
          grid[i + row][j + col].setVal('x');
          if (grid[i + row][j + col].getSteps() >= 3 && grid[i + row][j + col].starve != false)
            grid[i + row][j + col].setVal(' '); // Starve bug after three steps
        }
      }
    }
  }
  //Now move ants
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      if (grid[i][j].getVal() == 'x')
      {
        if (i + row < 20 && i + row >= 0 && j + col < 20 && j + col >= 0 && grid[i + row][j + col].getVal() != 'x' && grid[i + row][j + col].getVal() != 'o')
        {
          grid[row][col].setVal(' ');
          grid[i + row][j + col].setVal('0');
          grid[i + row][j + col].setSteps(grid[i + row][j + col].getSteps() + 1);
        }
      }
    }
  }
}

void sim::breedAnt()
{
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      if (grid[i][j].getVal() == '0')
      {
        if (grid[i][j].getSteps() >= 3)
        {
          if (i + 1 < 20 && grid[i + 1][j].getVal() == ' ')
          {
            grid[i + 1][j].setVal('0');
          }
          else if (i - 1 >= 0 && grid[i - 1][j].getVal() == ' ')
          {
            grid[i - 1][j].setVal('0');
          }
          else if (j + 1 < 20 && grid[i][j + 1].getVal() == ' ')
          {
            grid[i][j + 1].setVal('0');
          }
          else if (j - 1 >= 0 && grid[i][j - 1].getVal() == ' ')
          {
            grid[i][j - 1].setVal('0');
          }
          grid[i][j].setSteps(0);
        }
      }
    }
  }
}

void sim::breedBug()
{
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      if (grid[i][j].getVal() == 'x')
      {
        if (grid[i][j].getSteps() >= 8)
        {
          if (i + 1 < 20 && grid[i + 1][j].getVal() == ' ')
          {
            grid[i + 1][j].setVal('x');
          }
          else if (i - 1 >= 0 && grid[i - 1][j].getVal() == ' ')
          {
            grid[i - 1][j].setVal('x');
          }
          else if (j + 1 < 20 && grid[i][j + 1].getVal() == ' ')
          {
            grid[i][j + 1].setVal('x');
          }
          else if (j - 1 >= 0 && grid[i][j - 1].getVal() == ' ')
          {
            grid[i][j - 1].setVal('x');
          }
          grid[i][j].setSteps(0);
        }
      }
    }
  }
}

int main()
{
  sim s;
  s.initGrid();
  int i = 0;
  while (1)
  {
    s.printGrid();
    getchar();
    s.step();
    cout << "After step:" << i++ << endl;
    s.breedAnt();
    s.breedBug();
  }
  return 0;
}