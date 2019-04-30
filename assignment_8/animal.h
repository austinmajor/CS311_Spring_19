#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
private:
  int steps;
  char val;
public:
  Animal();
  int getSteps();
  void setSteps(int step);
  char getVal();
  void setVal(char value);
  bool starve;
};

#endif