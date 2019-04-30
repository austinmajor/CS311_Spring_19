#ifndef BUG_H
#define BUG_H
#pragma once
#include "Animal.h"

class Bug : public Animal
{
public:
  char val = 'x';
  Bug();
};

#endif // BUG_H