// goldbach_conj.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <math.h> // for linux/mac: #include <cmath> for the sqrt() function

using namespace std;

//func declaration
bool isPrime(unsigned int);
void goldBach(unsigned int);

int main()
{
  for (int i = 4; i < 200; i += 2)
  {
    cout << "i: " << i << '\t';
    goldBach(i);
  }
  return 0;
}

void goldBach(unsigned int num)
{
  if (num < 3 || num % 2 != 0)
  {
    cout << "The num must be > 3 and be even. " << endl;
    return;
  }

  for (int i = 2; i < num; i++)
  {
    if (isPrime(i) && isPrime(num - i))
    {
      cout << "Found two primes: " << i << " & " << num - i << endl;
      return;
    }
  }
}

bool isPrime(unsigned int num)
{
  if (num == 0 || num == 1)
    return false;
  if (num == 2)
    return true;
  // write a loop that provides all possible factors to the num
  // test if the num can evenly divide the factor

  // sqrt() is the "mid point" for the num
  // if there is no factor before the mid point,
  // then ther is no factor after since all factors come in a pair.
  for (int i = 2; i < sqrt(num) + 1; i++)
  {
    if (num % i == 0)
    {
      return false;
    }
  }

  // if after the loop we did not find any factor,
  // we will say the num is prime
  return true;
}