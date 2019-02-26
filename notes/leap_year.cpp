#include <iostream>

using namespace std;

int main()
{
  int year;

  cout << "enter a year, i'll tell you if it's a leap year" << endl;
  cin >> year;

  if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}