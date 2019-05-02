#ifndef BUG_H
#define BUG_H

#include "animal.h"
#include "sim.h"

class Bug : public Organism
{
private:
  void generateOffspring(int whereX, int whereY);
  int death_tik;
public:
  Bug(World *aWorld, int xcoord, int ycoord);

  void move();

  void breed();

  OrganismType getType() const;

  char representation() const;

  int size() const;

  bool isDead() const;

  bool in_range(int xx, int yy);
};

#endif
