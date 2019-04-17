// Function Definitions
#include "StringSet.h"

StringSet::StringSet()
{
}

StringSet::StringSet(string str[], int size)
{
  int flag = 0;
  string s;

  for (int i = 0; i < size; i++)
  {
    flag = 0;
    s = str[i];

    for (unsigned j = 0; j < newVector.size(); j++)
    {
      if (newVector[j].compare(s) == 0)
      {
        flag = 1;
      }
    }

    if (flag == 0)
    {
      newVector.push_back(s);
    }
  }
}

StringSet::StringSet(vector<string> vec)
{
  int flag = 0;
  string s;

  for (unsigned i = 0; i < vec.size(); i++)
  {
    flag = 0;
    s = vec[i];

    for (unsigned j = 0; j < newVector.size(); j++)
    {
      if (newVector[j].compare(s) == 0)
      {
        flag = 1;
      }
    }

    if (flag == 0)
    {
      newVector.push_back(s);
    }
  }
}

StringSet::~StringSet()
{
}

int StringSet::size()
{
  return newVector.size();
}

void StringSet::add(string str)
{
  int flag = 0;
  string s = str;

  for (unsigned j = 0; j < newVector.size(); j++)
  {
    if (newVector[j].compare(s) == 0)
    {
      flag = 1;
    }
  }

  if (flag == 0)
  {
    newVector.push_back(s);
  }
}

void StringSet::remove(string str)
{
  int flag = 0;

  for (unsigned i = 0; i < newVector.size(); i++)
  {
    if (newVector[i].compare(str) == 0)
    {
      newVector.erase(newVector.begin() + i);
      flag = 1;
    }
  }

  if (flag == 1)
  {
    cout << "Element Successfully Removed" << endl;
  }
  else
  {
    cout << "No Element Found" << endl;
  }
  cout << endl;
}

void StringSet::clear()
{
  newVector.clear();
}

void StringSet::Union(const StringSet &ss)
{
  string s;
  int flag = 0;
  cout << "Union:" << endl;

  for (unsigned i = 0; i < newVector.size(); i++)
  {
    cout << newVector[i] << endl;
  }

  for (unsigned i = 0; i < ss.newVector.size(); i++)
  {
    flag = 0;
    s = ss.newVector[i];

    for (unsigned j = 0; j < newVector.size(); j++)
    {
      if (newVector[j].compare(s) == 0)
      {
        flag = 1;
      }
    }

    if (flag == 0)
    {
      cout << s << endl;
    }
  }
  cout << endl;
}

void StringSet::intersect(const StringSet &ss)
{
  string s;
  cout << "Intersection:" << endl;

  for (unsigned i = 0; i < newVector.size(); i++)
  {
    s = newVector[i];

    for (unsigned j = 0; j < ss.newVector.size(); j++)
    {
      if (ss.newVector[j].compare(s) == 0)
      {
        cout << newVector[j] << endl;
      }
    }
  }
  cout << endl;
}

void StringSet::print()
{
  for (unsigned i = 0; i < newVector.size(); i++)
  {
    cout << newVector[i] << endl;
  }
  cout << endl;
}