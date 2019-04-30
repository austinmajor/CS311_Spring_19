#include "animal.h"

Animal::Animal()
{
  steps = 0;
  val = ' ';
  starve = false;
}

int Animal::getSteps()
{
  return steps;
}

char Animal::getVal()
{
  return val;
}

void Animal::setVal(char value)
{
  val = value;
}

void Animal::setSteps(int step)
{
  steps = step;
}