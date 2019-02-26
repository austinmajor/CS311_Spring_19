// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
// a prime # is divisible by itself and 1 only

#include <iostream>

using namespace std;

int main()
{
  int n, i;
  bool isPrime = true;

  cout << "Enter a positive integer: ";
  cin >> n;

  for (i = 2; i <= n / 2; ++i)
  {
    if (n % i == 0)
    {
      isPrime = false;
      break;
    }
  }

  cout << n / 2 << endl;
  cout << i << endl;

  if (isPrime)
    cout << "This is a prime number";
  else
    cout << "This is not a prime number";

  return 0;
}