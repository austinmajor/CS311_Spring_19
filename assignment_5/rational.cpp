/*
* Program: OOP - RATIONAL NUMBER CLASS
* Author: Austin Major
* Class: CS311
* Date: 4/3/19
*/

#include <iostream>

using namespace std;

class RationalNumber
{
public:
  // Constructors
  RationalNumber(int, int);
  RationalNumber(int);

  // Member functions
  void add(RationalNumber);
  void sub(RationalNumber);
  void mul(RationalNumber);
  void div(RationalNumber);
  bool less(RationalNumber);

  // Getters
  int getNumerator();
  int getDenominator();

  // Setters
  void setNumerator(int);
  void setDenominator(int);

private:
  int numerator;
  int denominator;
  int factor(int, int);
};

RationalNumber::RationalNumber(int n, int d)
{
  this->numerator = n;
  this->denominator = d;
}

RationalNumber::RationalNumber(int n)
{
  this->numerator = n;
  this->denominator = 1;
}

void RationalNumber::add(RationalNumber rn)
{
  int a, b, c, d;
  a = getNumerator();
  b = getDenominator();
  c = rn.getNumerator();
  d = rn.getDenominator();
  int numerator = (a * d + b * c);
  int denominator = (b * d);

  int g = factor(numerator, denominator);
  if (denominator != 1)
    cout << numerator / g << "/" << denominator / g;
  else
    cout << numerator / g << endl;
}

void RationalNumber::sub(RationalNumber rn)
{
  int a, b, c, d;
  a = getNumerator();
  b = getDenominator();
  c = rn.getNumerator();
  d = rn.getDenominator();
  int numerator = (a * d - b * c);
  int denominator = (b * d);
  int g = factor(numerator, denominator);
  if (denominator != 1)
    cout << numerator / g << "/" << denominator / g;
  else
    cout << numerator / g;
}

void RationalNumber::mul(RationalNumber rn)
{
  int a, b, c, d;
  a = getNumerator();
  b = getDenominator();
  c = rn.getNumerator();
  d = rn.getDenominator();
  int numerator = (a * c);
  int denominator = (b * d);
  int g = factor(numerator, denominator);
  if (denominator != 1)
    cout << numerator / g << "/" << denominator / g;
  else
    cout << numerator / g;
}

void RationalNumber::div(RationalNumber rn)
{
  int a, b, c, d;
  a = getNumerator();
  b = getDenominator();
  c = rn.getNumerator();
  d = rn.getDenominator();
  int numerator = (a * d);
  int denominator = (c * b);
  int g = factor(numerator, denominator);
  if (denominator != 1)
    cout << numerator / g << "/" << denominator / g;
  else
    cout << numerator / g;
}

bool RationalNumber::less(RationalNumber rn)
{
  int a = numerator;
  int b = denominator;
  int c = rn.numerator;
  int d = rn.denominator;
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

void RationalNumber::setNumerator(int n)
{
  this->numerator = n;
}

void RationalNumber::setDenominator(int d)
{
  this->denominator = d;
}

int RationalNumber::factor(int a, int b)
{
  if ((a % b) == 0)
    return b;
  else
    return factor(b, a % b);
}

int main()
{
  RationalNumber a(1, 2);
  RationalNumber b(1, 4);

  cout << "First Rational Number: ";
  cout << a.getNumerator() << "/" << a.getDenominator() << endl;
  cout << "Second Rational Number: ";
  cout << b.getNumerator() << "/" << b.getDenominator() << endl;

  cout << "Addition: ";
  a.add(b);
  cout << endl;

  cout << "Subtraction: ";
  a.sub(b);
  cout << endl;

  cout << "Multiplication: ";
  a.mul(b);
  cout << endl;

  cout << "Division: ";
  a.div(b);
  cout << endl;

  cout << "Inequality: ";
  bool x = a.less(b);
  if (x)
    cout << a.getNumerator() << "/" << a.getDenominator() << " < " << b.getNumerator() << "/" << b.getDenominator() << endl;
  else
    cout << a.getNumerator() << "/" << a.getDenominator() << " > " << b.getNumerator() << "/" << b.getDenominator() << endl;

  return 0;
}