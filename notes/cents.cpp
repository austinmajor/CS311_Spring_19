// find all the possible change for 1 dollar

#include <iostream>

using namespace std;

int main()
{
  for(int q = 0; q <= 4; q++)
  {
    for(int d = 0; d <= 10; d++)
    {
      for(int n = 0; n <= 20; n++)
      {
        for(int p = 0; p <= 100; p++)
        {
          if(25 * q + 10 * d + 5 * n + 1 * p == 100)
          {
            cout << "Q: " << q << " D: " << d << " N: " << n << " P: " << p << endl;
          }
        }
      }
    }
  }

  return 0;
}