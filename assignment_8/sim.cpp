#include "sim.h"

World::World(unsigned int seed)
{
  srand(seed);

  for (int i = 0; i < WORLDSIZE; i++)
  {
    for (int j = 0; j < WORLDSIZE; j++)
    {
      grid[i][j] = NULL;
    }
  }

  createOrganisms(ANT, INITIAL_ANTS);

  createOrganisms(BUG, INITIAL_BUGS);
}

World::~World()
{
  for (int i = 0; i < WORLDSIZE; i++)
  {
    for (int j = 0; j < WORLDSIZE; j++)
    {
      if (grid[i][j] != NULL)
      {
        delete grid[i][j];
      }
    }
  }
}

Organism *World::getAt(int x, int y) const
{
  if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE))
  {
    return grid[x][y];
  }
  else
  {
    return NULL;
  }
}

void World::setAt(int x, int y, Organism *org)
{
  if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE))
  {
    grid[x][y] = org;
  }
}

void World::display() const
{
  int numAnts = 0;
  int numBugs = 0;
  cout << endl
       << endl;
  for (int j = 0; j < WORLDSIZE; j++)
  {
    for (int i = 0; i < WORLDSIZE; i++)
    {
      if (grid[i][j] == NULL)
      {
        cout << ".";
      }
      else
      {
        if (grid[i][j]->getType() == ANT)
        {
          numAnts++;
        }
        else if (grid[i][j]->getType() == BUG)
        {
          numBugs++;
        }
        cout << grid[i][j]->representation();
      }
    }
    cout << endl;
  }
  cout << "Ants: " << numAnts << " Bugs: " << numBugs << endl;
}

void World::simulateOneStep()
{
  resetOrganisms();

  moveOrganism(BUG);

  moveOrganism(ANT);

  cleanup();

  breedOrganisms();
}

Position World::randomPosition() const
{
  Position p;
  p.x = rand() % WORLDSIZE;
  p.y = rand() % WORLDSIZE;
  return p;
}

Move World::randomMove() const
{
  return static_cast<Move>(rand() % 4);
}

void World::createOrganisms(OrganismType orgType, int count)
{
  int orgCount = 0;
  while (orgCount < count)
  {
    Position p = randomPosition();

    if (grid[p.x][p.y] == NULL)
    {
      orgCount++;
      if (orgType == ANT)
      {
        new Ant(this, p.x, p.y);
      }
      else if (orgType == BUG)
      {
        new Bug(this, p.x, p.y);
      }
    }
  }
}

void World::resetOrganisms()
{
  for (int i = 0; i < WORLDSIZE; i++)
  {
    for (int j = 0; j < WORLDSIZE; j++)
    {
      if (grid[i][j] != NULL)
      {
        grid[i][j]->setMoved(false);
      }
    }
  }
}

void World::moveOrganism(OrganismType aType)
{
  for (int i = 0; i < WORLDSIZE; i++)
  {
    for (int j = 0; j < WORLDSIZE; j++)
    {
      if (grid[i][j] != NULL)
      {
        if (grid[i][j]->getType() == aType && !(grid[i][j]->hasMoved()))
        {
          grid[i][j]->move();
        }
      }
    }
  }
}

void World::cleanup()
{
  for (int i = 0; i < WORLDSIZE; i++)
  {
    for (int j = 0; j < WORLDSIZE; j++)
    {

      if ((grid[i][j] != NULL) && grid[i][j]->isDead())
      {
        delete grid[i][j];
        grid[i][j] = NULL;
      }
    }
  }
}

void World::breedOrganisms()
{
  for (int i = 0; i < WORLDSIZE; i++)
  {
    for (int j = 0; j < WORLDSIZE; j++)
    {
      if (grid[i][j] != NULL)
      {
        grid[i][j]->breed();
      }
    }
  }
}