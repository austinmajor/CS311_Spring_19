// Function Declarations
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#ifndef STRINGSET_H
#define STRINGSET_H

class StringSet
{
private:
  /* * * Data * * */
  vector<string> newVector;

public:
  /* * * Constructors * * */
  // Default Constructor
  StringSet();

  // Overloaded Constructors
  StringSet(string str[], int size);
  StringSet(vector<string> vec1);

  // Destructor
  ~StringSet();

    /* * * Member Functions * * */
  // Accessor Function
  int size();

  // Mutator Functions
  void add(string str);
  void remove(string str);
  void clear();
  void Union(const StringSet &ss); // caps because union is reserved by cpp
  void intersect(const StringSet &ss);
  void print();
};
#endif
