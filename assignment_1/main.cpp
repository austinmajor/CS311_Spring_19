/*
Program Name: Assignment 1
Description: Summation to Euler's Problem #13
Author: Austin Major
Date: 2/15/19
*/

#include <iostream>
#include <string>

using namespace std;

string add(string, string);
void print(string);

void print(string a)
{
  int array[55] = { 0 };

  string answer = a;

 // get length of string answer
	int sl = answer.length();

	int j = sl, i; 

	// traverse the string in reverse
	for (i = 0; answer[i] != '\0'; i++)
	{
		j--;
		// subtract string[i] by 48 to convert it to int
		// the character 1 in ascii is 48 in decimal
		array[j] = (answer[i] - 48);
	}

  // the answer
  cout << "The sum is: ";

  for (i = sl - 1; i >= 0; i--)
	{
		cout << array[i] << "";
	}

  cout << endl;

  // the first ten digits of the answer
  cout << "The first ten digits of the sum is: ";

  for (i = sl - 1; i >= sl - 10; i--)
	{
		cout << array[i] << "";
	}

  cout << endl;

}

string add(string a, string b)
{
  string sum = "";

  int line1 = a.size(); // get length of a
  int line2 = b.size(); // get lenght of b

  reverse(a.begin(),a.end()); // reverse a
  reverse(b.begin(),b.end()); // reverse b

  int i = 0 , j = 0 , carry = 0;

  while(i < line1 || j < line2) // start i from a and j from b
  {
    int ai, bj; 

    if(i < line1)
      ai = a[i] - '0'; // get a[i];
    else
      ai = 0; // if i is greater than line1 set it equal to 0

    if(j < line2)
      bj = b[j] - '0'; // get b[j]
    else
      bj = 0; // if j is greater than line2 set it equal to 0

    int s = carry + ai + bj;

    carry = s/10; // get the sum at any index

    s %= 10; // get carry

    sum = sum + to_string(s); // convert to string and add it to final sum

    i++ , j++; // increase i & j
  }

  if(carry > 0) // if carrry is greater than 0 add it to sum
    sum = sum + to_string(carry);
    reverse(sum.begin(),sum.end()); // reverse the sum

  return sum; // return sum
}

int main()
{
  freopen("nums.txt", "r", stdin);

  int count = 100;
  string answer = "";
  string sum;

  while(count--)
  {
    cin >> sum;
    answer = add(answer,sum);
  }

  print(answer);

  return 0;
}