#ifndef ANT_H
#define ANT_H

#include "animal.h"
#include "sim.h"

class Ant : public Organism
{
private:
  void generateOffspring(int whereX, int whereY);
public:
  Ant(World *aWorld, int xcoord, int ycoord);

  void move();

  void breed();

  OrganismType getType() const;

  char representation() const;

  int size() const;

  bool in_range(int xx, int yy);
};

#endif
