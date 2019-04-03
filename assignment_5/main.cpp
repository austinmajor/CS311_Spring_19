#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class RationalNumber
{
public:
  RationalNumber(int n);

  // Initializes the rational number to wholeNumber/1
  RationalNumber(int m, int n);

  bool less(RationalNumber r2);

  //Declaring functions
  void add(RationalNumber rn);
  void sub(RationalNumber rn);
  void mul(RationalNumber rn);
  void div(RationalNumber rn);
  int getNumerator();
  int getDenominator();
  void setNumerator(int numer);
  void setDenominator(int denom);

private:
  // Declaring variables
  int numerator;   // the numerator of the number
  int denominator; // the denominator of the number
  int factor(int a, int b);
};

RationalNumber::RationalNumber(int n)
{
  this->numerator = n;
  this->denominator = 1;
}

// Initializes the rational number to wholeNumber/1
RationalNumber::RationalNumber(int m, int n)
{
  if (denominator < 0)
  {
    this->numerator = -(m);
    this->denominator = -(n);
  }
  else
  {
    this->numerator = (m);
    this->denominator = (n);
  }
}

bool RationalNumber::less(RationalNumber r2)
{
  int a = numerator;
  int b = denominator;
  int c = r2.numerator;
  int d = r2.denominator;
  double n1 = a * d;
  double d1 = b * d;
  double n2 = c * b;
  double d2 = d * b;
  if ((n1 / d1) < (n2 / d2))
    return true;
  else
    return false;
}
int RationalNumber::getNumerator()
{
  return numerator;
}
int RationalNumber::getDenominator()
{
  return denominator;
}
void RationalNumber::setNumerator(int numer)
{
  this->numerator = numer;
}
void RationalNumber::setDenominator(int denom)
{
  this->denominator = denom;
}

int RationalNumber::factor(int a, int b)
{
  // % is modulus which is the remainder of a division
  // base case
  if ((a % b) == 0)
  {
    return b;
  }
  // recursive case
  else
  {
    return factor(b, a % b);
  }
}
//This method will add two rational numbers
void RationalNumber::add(RationalNumber rn)
{
  int a, b, c, d;
  a = getNumerator();
  b = getDenominator();
  c = rn.getNumerator();
  d = rn.getDenominator();
  int sumnumer = (a * d + b * c);
  int sumdenom = (b * d);

  int g = factor(sumnumer, sumdenom);
  if (sumdenom != 1)
    cout << sumnumer / g << "/" << sumdenom / g;
  else
    cout << sumnumer / g;
}
//This method will subtract two rational numbers
void RationalNumber::sub(RationalNumber rn)
{
  int a, b, c, d;
  a = getNumerator();
  b = getDenominator();
  c = rn.getNumerator();
  d = rn.getDenominator();
  int subnumer = (a * d - b * c);
  int subdenom = (b * d);
  int g = factor(subnumer, subdenom);
  if (subdenom != 1)
    cout << subnumer / g << "/" << subdenom / g;
  else
    cout << subnumer / g;
}
//This method will multiply two rational numbers
void RationalNumber::mul(RationalNumber rn)
{
  int a, b, c, d;
  a = getNumerator();
  b = getDenominator();
  c = rn.getNumerator();
  d = rn.getDenominator();
  int mulnumer = (a * c);
  int muldenom = (b * d);
  int g = factor(mulnumer, muldenom);
  if (muldenom != 1)
    cout << mulnumer / g << "/" << muldenom / g;
  else
    cout << mulnumer / g;
}
//This method will divide two rational numbers
void RationalNumber::div(RationalNumber rn)
{
  int a, b, c, d;
  a = getNumerator();
  b = getDenominator();
  c = rn.getNumerator();
  d = rn.getDenominator();
  int divnumer = (a * d);
  int divdenom = (c * b);
  int g = factor(divnumer, divdenom);
  if (divdenom != 1)
    cout << divnumer / g << "/" << divdenom / g;
  else
    cout << divnumer / g;
}

int main()
{
  //Creating the objects to RationalNumber class
  RationalNumber rn1(1, 6);
  RationalNumber rn2(2);

  //Getting the number entered by the user
  cout << "First Number:";
  cout << rn1.getNumerator() << "/" << rn1.getDenominator() << endl;
  cout << "\nSecond Number:";
  cout << rn2.getNumerator() << "/" << rn2.getDenominator() << endl;

  /* calling the function and displaying
* the result after adding two rational num bers
*/
  cout << "\nAddition :";
  rn1.add(rn2);
  /* calling the function and displaying
* the result after subtracting two rational num bers
*/
  cout << "\nSubtraction :";
  rn1.sub(rn2);
  /* calling the function and displaying
* the result after multiplying two rational num bers
*/
  cout << "\nMultiplication :";
  rn1.mul(rn2);
  /* calling the function and displaying
* the result after dividing two rational num bers
*/
  cout << "\nDivision :";
  rn1.div(rn2);

  bool b = rn1.less(rn2);
  if (b)
  {
    cout << "\nRationalNumber#1 is Less than RationalNumber#2" << endl;
  }
  else
  {
    cout << "\nRationalNumber#1 is not Less than RationalNumber#2" << endl;
  }

  return 0;
}

____________________________