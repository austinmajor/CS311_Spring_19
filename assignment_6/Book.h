/*
* Program: (Textbook Cha9 Q9) Create a Library class.
* Author: Austin Major
* Class: CS311
* Date: 4/9/19
*/

#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book
{
public:
  enum Genre
  {
    fiction,
    nonfiction,
    periodical,
    biography,
    children,
    unknown
  };
  enum Book_status
  {
    out,
    in
  };
  Book(); // default constructor
  // Init: initialise all parameters:
  void Init(std::string isbn, std::string title,
            std::string fn, std::string ln,
            Genre g, Book_status s);
  // non-modifying methods
  std::string get_isbn() const { return isbn13; }
  std::string get_title() const { return title; }
  std::string get_author() const { return author_fname + " " + author_lname; }
  Genre get_genre() const { return genre; }
  std::string genre_tostring() const; // return the genre as a string
  bool is_bookin() const { return is_checkedin; }
  void print();

  // modifying methods
  void read_isbn();
  bool set_isbn(std::string n);
  void read_title();
  void set_title(std::string t)
  {
    title = t;
    cout << "DEBUG: Book::set_title()\n";
  }
  void read_author();
  void set_author(std::string fname, std::string lname);
  void read_genre();
  void set_genre(Genre g)
  {
    genre = g;
    cout << "DEBUG: Book::set_genre()\n";
  }
  void checkin();
  void checkout();

private:
  std::string isbn13; // size must be 13 char long, no more, no less
  static const uint isbn13_length = 13;
  std::string title;
  std::string author_fname;
  std::string author_lname;
  Genre genre;
  bool is_checkedin;

}; // class Book

// overloaded operators
bool operator==(const Book &a, const Book &b);
bool operator!=(const Book &a, const Book &b);
std::ostream &operator<<(std::ostream &os, const Book &book);

#endif