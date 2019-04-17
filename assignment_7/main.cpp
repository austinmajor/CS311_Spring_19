// Function Test
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "StringSet.h"

int main()
{
  const int size = 5;

  string arr1[] = {"monday", "tuesday", "wednesday", "thursday", "friday"};
  string arr2[] = {"fred", "george", "sally", "mike", "sandi"};

  StringSet s1(arr1, size);
  StringSet s2(arr2, size);

  s1.print();
  s2.print();

  s1.add("TEST");
  s2.add("TEST");

  s1.print();
  s2.print();

  s1.Union(s2);
  s1.intersect(s2);

  s1.remove("sunday"); // results as "no element found"
  s1.remove("monday"); // removes monday

  s1.print();
  s1.clear();

  s2.print();
  s2.clear();

  return 0;
}