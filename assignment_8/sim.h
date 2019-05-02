#ifndef SIM_H
#define SIM_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ant.h"
#include "bug.h"

using namespace std;

enum Move
{
  UP = 0,
  DOWN,
  LEFT,
  RIGHT
};

const int WORLDSIZE = 20;
const int INITIAL_ANTS = 100;
const int INITIAL_BUGS = 5;
const int BREED_ANTS = 3;
const int BREED_BUGS = 8;
const int STARVE_BUGS = 3;

struct Position
{
  int x;
  int y;
};

class World
{
private:
  Organism *grid[WORLDSIZE][WORLDSIZE];

  void createOrganisms(OrganismType orgType, int count);

  void resetOrganisms();

  void moveOrganism(OrganismType aType);

  void cleanup();

  void breedOrganisms();

public:
  World(unsigned int seed);

  ~World();

  Organism *getAt(int x, int y) const;

  void setAt(int x, int y, Organism *org);

  void display() const;

  void simulateOneStep();

  Position randomPosition() const;

  Move randomMove() const;
};

#endif