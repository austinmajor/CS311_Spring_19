/*
* Program: (Textbook Cha9 Q9) Create a Library class.
* Author: Austin Major
* Class: CS311
* Date: 4/9/19
*/

// Declaration of class Library
#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Patron.h"
#include "Book.h"

class Library
{
  std::vector<Book> book;
  size_t bk_index; // an index into the book vector
  std::vector<Patron> patron;
  struct Transaction
  {
    Transaction() : book(), patron() {}
    Book book;
    Patron patron;
  };
  std::vector<Transaction> transaction;
  // private member methods
  bool have_book(Book &b);	 // returns true if book is in the library
  bool is_member(Patron &p); // returns true if patron is member of the library
  bool owes_fees(Patron &p); // returns true if patron owes fees
  void store_transaction(Book &b, Patron &p);
  std::vector<std::string> who_owes_fees(); // creates a vector of
                                            // patrons owing fees

public:
  // modifying methods
  Library();															// default contructor
  void add_patron(Patron p);							// adds a member to the library
  void add_book(Book b);									// adds a book to the library collection
  void checkout_book(Book &b, Patron &p); // attempts to checkout a book
  // non-modifying methods
  void list_book_titles();	 // lists book titles in library collection
  void list_books();				 // lists all books and book info in collection
  void list_patron_names();	// lists names of library patrons
  void list_patrons();			 // lists all patrons and patron info in library
  void list_transactions();	// lists all transaction records
  void list_who_owes_fees(); // lists names of patrons owing fees
};													 // class Library

#endif // LIBRARY_H
