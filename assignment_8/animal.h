#ifndef ANIMAL_H
#define ANIMAL_H

enum OrganismType
{
  ANT,
  BUG
};

class World;

class Organism
{
protected:
  virtual void generateOffspring(int whereX, int whereY) = 0;

  void movesTo(int xNew, int yNew);

  void breedAtAdjacentCell();

  int x;

  int y;

  bool moved;

  int breedTicks;

  World *world;

public:
  Organism(World *aWorld, int xcoord, int ycoord);

  virtual ~Organism() {}

  virtual void move() = 0;

  virtual void breed() = 0;

  virtual OrganismType getType() const = 0;

  void setMoved(bool hasMoved);

  virtual char representation() const = 0;

  virtual int size() const = 0;

  bool hasMoved() const;

  virtual bool isDead() const;

  bool in_range(int xx, int yy);
};

#endif