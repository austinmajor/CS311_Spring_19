#include "sim.h"

int main()
{
  World myWorld(time(0));

  myWorld.display();

  char ch;

  while (cin.get(ch) && ch != 'q')
  {
    myWorld.simulateOneStep();
    myWorld.display();
  }

  return 0;
}