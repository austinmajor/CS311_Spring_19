#include<iostream>
#include<string>

using namespace std;

string sum_no(string a ,string b)
{
  string sum = "";

  int l1 = a.size(); // get length of a
  int l2 = b.size(); // get lenght of b

  reverse(a.begin(),a.end()); // reverse a now 219
  reverse(b.begin(),b.end()); // reverse b now 029

  int i = 0 , j = 0 , carry = 0;

  cout << "l1: " << l1 << endl;
  cout << "l2: " << l2 << endl; 

  while(i < l1 || j < l2) // start i from a and j from b
  {
    int ai, bj;

    if(i < l1)
      ai = a[i] - '0'; // get a[i];
    else
      ai = 0; // if i is greater than l1 set it equsl to 0

    if(j < l2)
      bj = b[j] - '0'; // get b[j]
    else
      bj = 0; // if j is greater than l2 set it equal to 0

    int s = carry + ai + bj;

    carry = s/10; // get the sum it any index

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
  string sum = "";
  string t;

  while(count--)
  {
    cin >> t;

    // cout << count << " " << t << endl;

    sum = sum_no(sum,t);
  }

  cout << sum << endl;
  cout << sum.substr(0,10) << endl;

  return 0;
}