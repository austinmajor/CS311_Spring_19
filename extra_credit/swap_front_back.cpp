/*
  Title: Swap Array - Front Back Method
  Author: Austin Major
  Date: 3/26/2019

  Note:
    Find the user input in main().

  Instructions:
  1) Write a function named swapFrontBack()
  2) Function INPUT: a) int array b) int size
  3) Swap the array:
      a) The original first element in the array will be swapped to the last.
      b) The original second element will be swapped to the second to the last.
      c) And so on..
  4) OUTPUT the final contents of the array

  TEST CASE:
    INPUT: 4
    INPUT: [0,1,2,3]
    OUTPUT: [3,2,1,0]

  Diagram:
    [0,1,2,3] -> [3,1,2,0] -> [3,2,1,0]
*/

#include <iostream>

using namespace std;

void swapFrontBack(int, int*); // as specified in details above
void print(int, int*); // prints the results

void swapFrontBack(int size, int* arr)
{
  int temp;
  int i;
  for(i=0; i<size/2; i++)
  {
    temp = arr[size-i-1];
    arr[size-i-1] = arr[i];
    arr[i] = temp;
  }
}

void print(int size, int* arr)
{
  int i;
  for(i=0; i<size; i++)
  {
    cout << " " << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  // INPUT: size and array integer values
  int size = 4;
  int arr[size] = {0,1,2,3};

  swapFrontBack(size, arr);
  print(size, arr);

  return 0;
}