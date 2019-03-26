/*
  Title: Syracuse Sequence - (+ || - || 1)
  Author: Austin Major
  Date: 3/26/2019

  Note:
    Find the user input in main().

  Instructions:
  1) Write a function named syracuseSequence()
  2) Function INPUT: positive integer
  3) Loop until f(x) != 1:
      a) IF even
          x=x/2
          print
      b) IF odd
          x=3x+1
  4) OUTPUT each step

  TEST CASE:
    INPUT: 5
    OUTPUT: 5,16,8,4,2,1
*/

#include <iostream>

using namespace std;

void syracuseSequence(int);
void print(int);

void syracuseSequence(int x)
{
  while (x != 1)
  {
    if (x%2 == 0)
    {
      x = x/2;
      print(x);
    }
    else if (x%2 != 0)
    {
      x = (3*x)+1;
      print(x);
    }
    else if (x == 1)
    {
      print(x);
    }
  }
}

void print(int x)
{
  cout << " " << x << " ";
  if (x == 1)
    cout << endl;
}

int main()
{
  // INPUT: a natural positive integer
  int input = 5;

  print(input);
  syracuseSequence(input);

  return 0;
}