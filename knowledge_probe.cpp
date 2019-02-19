#include <iostream>

using namespace std;

// decleration
double my_sum(double, double);

int main()
{
  cout << my_sum(11.25, 20) << endl;
  return 0;
}

double my_sum(double d1, double d2) {
  return d1 + d2;
}



// #4: No, don't use type on decleration. Ex.: foo(letters[33])



// #5 a: TRUE
// #5 b: TRUE
// #5 c: FALSE
// #5 d: TRUE



// #6 
/*
#include <iostream>

using namespace std;

int main() {

int x, *p, y;
x=34;
y=56;
p=&y; //p contains memory address of y
*p+=4; //*anything is always contents 
x=*p; 
y=88;
*p=(*p)/2

cout << *p << endl; // = 44
cout << p << endl;  // = memory address of y
cout << &p << endl; // = memory address of p
cout << &y << endl; // = memory address of y
cout << x << endl; // = 60


return 0;
}
*/


