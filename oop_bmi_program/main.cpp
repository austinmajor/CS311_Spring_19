#include <iostream>
#include <string>

#include "BMI.h"

using namespace std;

int main() {

  string name;
  int height;
  double weight;

  // STUDENT #1
  cout << "Enter your name: ";
  cin >> name;
  cout << "Enter your height (in inches): ";
  cin >> height;
  cout << "Enter your weight (in pounds): ";
  cin >> weight;

  BMI Patient_1(name, height, weight);

  cout << endl;

  cout <<  "Patient Name: " << Patient_1.getName() << endl;
  cout <<  "Height: " << Patient_1.getHeight() << endl;
  cout <<  "Weight: " << Patient_1.getWeight() << endl;
  cout <<  "BMI: " << Patient_1.calculateBMI() << endl;

  cout  << endl;

  // STUDENT #2
  cout << "Enter your name: ";
  cin >> name;
  cout << "Enter your height (in inches): ";
  cin >> height;
  cout << "Enter your weight (in pounds): ";
  cin >> weight;

  BMI Patient_2;

  Patient_2.setName(name);
  Patient_2.setHeight(height);
  Patient_2.setWeight(weight);

  cout << endl;

  cout <<  "Patient Name: " << Patient_2.getName() << endl;
  cout <<  "Height: " << Patient_2.getHeight() << endl;
  cout <<  "Weight: " << Patient_2.getWeight() << endl;
  cout <<  "BMI: " << Patient_2.calculateBMI() << endl;

  return 0;
}