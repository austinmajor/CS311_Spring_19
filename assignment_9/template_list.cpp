/*
* Program: Function Template & Vector List Search
* Author: Austin Major
* Class: CS311
* Date: 5/4/19
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
int seqSearch(vector<T> list,T item)
{
  int count;
  for (unsigned int i = 0; i < list.size(); i++)
  {
    if (list[i] == item)
    {
      count++;
    }
  }
  return count > 0 ? count : -1;
}


int main()
{
  vector<string> v1;
  string item;
  v1.push_back("Blue");
  v1.push_back("Red");
  v1.push_back("Orange");
  v1.push_back("Yellow");

  // vector<int> v1;
  // int item;
  // v1.push_back(1);
  // v1.push_back(2);
  // v1.push_back(3);
  // v1.push_back(4);

  cout << "Enter the element to be searched: " << endl;
  cin >> item;

  int found = seqSearch(v1, item);
  if (found == -1)
  {
    cout << "The element " << item << " is not found in the vecor list" << endl;
  } else {
    cout << "The element " << item << " is found in the vector list" << endl;
  }

  return 0;
}