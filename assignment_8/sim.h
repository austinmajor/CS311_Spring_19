#ifndef SIM_H
#define SIM_H
#include <iostream>
#include "ant.h"
#include "bug.h"

class sim
{
private:
  Animal grid[20][20];
  int bugCount = 5;
  int antCount = 100;
public:
  void initGrid();
  void printGrid();
  void step();
  void breedAnt();
  void breedBug();
};

#endif