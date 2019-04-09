/*
* Program: (Textbook Cha9 Q9) Create a Library class.
* Author: Austin Major
* Class: CS311
* Date: 4/9/19
*/

#ifndef PATRON_H
#define PATRON_H
#include <string>

class Patron
{
public:
  Patron(); // default constructor
  // non-modifying methods
  std::string get_name() const { return first_name + " " + last_name; }
  int get_card_num() const { return card_num; }
  double get_fee() const { return fee; }
  bool owes_fees() const { return (fee ? true : false); }
  void print();

  // modifying methods
  void set_first_name(std::string fname);
  void set_last_name(std::string lname);
  void set_name(std::string fname, std::string lname);
  void set_card_num(int num);
  void set_fee(double amount);
  void Init(std::string fn, std::string ln, int cnum, double fee);

private:
  std::string first_name;
  std::string last_name;
  int card_num;
  double fee;

}; // class Patron

// overloaded operators
bool operator==(const Patron &a, const Patron &b);
bool operator!=(const Patron &a, const Patron &b);
std::ostream &operator<<(std::ostream &os, const Patron &patron);

#endif // PATRON_H
