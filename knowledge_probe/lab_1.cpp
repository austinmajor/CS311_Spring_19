/*
  Austin Major
  N675Q967
  LAB #1
  1/29/19
*/

#include <iostream>

using namespace std;

void get_no_of_student(int&);
void get_no_of_quiz(int&);
void get_data_base(int&, int&, int**);
void get_print_results(int&, int&, int**);

void get_no_of_student(int& n)
{
  while (true)
  {
    cout << "Enter # of students: ";
    cin >> n;

    if (n < 1 || n > 5)
    {
      cout << "Try again - Must be between 1 and 5 !" << endl;
      continue;
    }
    break;
  }
}

void get_no_of_quiz(int& q)
{
  while (true)
  {
    cout << "Enter # of quizes: ";
    cin >> q;

    if (q < 8 || q > 10)
    {
      cout << "Try again - Must be between 8 and 10 !" << endl;
      continue;
    }
      break;
  }
}

void get_data_base(int& n, int& q, int **a)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < q; j++)
    {
      a[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << "Enter Student # " << i + 1 << " quiz scores: " << endl;
    for (int j = 0; j < q; j++)
    {
      cout << "Enter Score " << j + 1 <<" : ";
      cin >> a[i][j];

      if (a[i][j] == -1)
      {
        break;
      }
    }
  }
}

void get_print_results(int& n, int& q, int **a)
{
  int total = 0, average = 0;
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    total = 0;
    count = 0;

    for (int j = 0; j < q; j++)
    {
      if (a[i][j] != 0)
      {
        count ++;
        total += a[i][j];
      }
    };

    average = total / count;
    cout << "Average Total Score of Student # " << i + 1 << " : " << average << endl;
  }
}

int main()
{
  int no_of_student, no_of_quiz;
  get_no_of_student(no_of_student);
  get_no_of_quiz(no_of_quiz);

  // 2D Array Declaration - not sure how to decouple this logic
  int **array;
  array = new int *[no_of_student];
  for(int i = 0; i < no_of_quiz; i++)
  {
    array[i] = new int[no_of_quiz];
  }
  get_data_base(no_of_student, no_of_quiz, array);
  get_print_results(no_of_student, no_of_quiz, array);

  return 0;
}