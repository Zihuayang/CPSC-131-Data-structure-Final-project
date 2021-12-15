#include "book.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

//
// Constructors, Assignments, and Destructor
//

Book::Book(const std::string& title,
           const std::string& author,
           const std::string& isbn, 
           double price)
///////////////////////// TO-DO (2) //////////////////////////////
{}
/////////////////////// END-TO-DO (2) ////////////////////////////

Book::Book(const Book& other)
///////////////////////// TO-DO (3) //////////////////////////////
{}
/////////////////////// END-TO-DO (3) ////////////////////////////

Book& Book::operator=(const Book& rhs)
///////////////////////// TO-DO (5) //////////////////////////////
{}
/////////////////////// END-TO-DO (5) ////////////////////////////

// Destructor
Book::~Book() noexcept
///////////////////////// TO-DO (7) //////////////////////////////
{}
/////////////////////// END-TO-DO (7) ////////////////////////////

//
//  Accessors
//

const std::string& Book::isbn() const {
  ///////////////////////// TO-DO (8) //////////////////////////////
  /////////////////////// END-TO-DO (8) ////////////////////////////
}

const std::string& Book::title() const {
  ///////////////////////// TO-DO (9) //////////////////////////////
  /////////////////////// END-TO-DO (9) ////////////////////////////
}

const std::string& Book::author() const {
  ///////////////////////// TO-DO (10) //////////////////////////////
  /////////////////////// END-TO-DO (10) ////////////////////////////
}

double Book::price() const {
  ///////////////////////// TO-DO (11) //////////////////////////////
  /////////////////////// END-TO-DO (11) ////////////////////////////
}

std::string Book::isbn() {
  ///////////////////////// TO-DO (12) //////////////////////////////
  /////////////////////// END-TO-DO (12) ////////////////////////////
}

std::string Book::title() {
  ///////////////////////// TO-DO (13) //////////////////////////////
  /////////////////////// END-TO-DO (13) ////////////////////////////
}

std::string Book::author() {
  ///////////////////////// TO-DO (14) //////////////////////////////
  /////////////////////// END-TO-DO (14) ////////////////////////////
}

//
// Modifiers
//

Book& Book::isbn(const std::string& new_isbn) {
  ///////////////////////// TO-DO (15) //////////////////////////////
  /////////////////////// END-TO-DO (15) ////////////////////////////
}

Book& Book::title(const std::string& new_title) {
  ///////////////////////// TO-DO (16) //////////////////////////////
  /////////////////////// END-TO-DO (16) ////////////////////////////
}

Book& Book::author(const std::string& new_author) {
  ///////////////////////// TO-DO (17) //////////////////////////////
  /////////////////////// END-TO-DO (17) ////////////////////////////
}

Book& Book::price(double new_price) {
  ///////////////////////// TO-DO (18) //////////////////////////////
  /////////////////////// END-TO-DO (18) ////////////////////////////
}

//
// Relational Operators
//

bool Book::operator==(const Book& rhs) const noexcept {
  // All attributes must be equal for the two books to be equal to the other. 
  //
  // This can be done in any order, so put the quickest and the most likely
  // to be different first.

  ///////////////////////// TO-DO (20) //////////////////////////////
  /////////////////////// END-TO-DO (20) ////////////////////////////
}

bool Book::operator!=(const Book& rhs) const noexcept {
  // Two books are unequal if any of their attributes are unequal.

  ///////////////////////// TO-DO (20) //////////////////////////////
  /////////////////////// END-TO-DO (20) ////////////////////////////
}

bool Book::operator<(const Book& rhs) const noexcept {
  // Books are ordered (sorted) by ISBN, author, title, then price.

  ///////////////////////// TO-DO (20) //////////////////////////////
  /////////////////////// END-TO-DO (20) ////////////////////////////
}

bool Book::operator<=(const Book& rhs) const noexcept {
  // Books are ordered (sorted) by ISBN, author, title, then price.

  ///////////////////////// TO-DO (20) //////////////////////////////
  /////////////////////// END-TO-DO (20) ////////////////////////////
}

bool Book::operator>(const Book& rhs) const noexcept {
  // Books are ordered (sorted) by ISBN, author, title, then price.

  ///////////////////////// TO-DO (20) //////////////////////////////
  /////////////////////// END-TO-DO (20) ////////////////////////////
}

bool Book::operator>=(const Book& rhs) const noexcept {
  // Books are ordered (sorted) by ISBN, author, title, then price.

  ///////////////////////// TO-DO (20) //////////////////////////////
  /////////////////////// END-TO-DO (20) ////////////////////////////
}

//
// Insertion and Extraction Operators
//

std::istream& operator>>(std::istream& stream, Book& book) {
  ///////////////////////// TO-DO (21) //////////////////////////////
  // A lot can go wrong when reading from streams - no permission, wrong types,
  // end of file, etc. Minimal exception guarantee says there should be no side
  // affects if an error or exception occurs, so let's do our work in a local object
  // and move it into place at the end if all goes well.
  //
  // This function should be symmetrical with operator<< below.
  //
  // Assume fields are separated by commas and string attributes are enclosed
  // with double quotes.  For example:
  //    ISBN             | Title                 | Author             | Price
  //    -----------------+-----------------------+--------------------+-----
  //    "9789998287532",   "Over in the Meadow",   "Ezra Jack Keats",   91.11
  //
  //
  // Hint:  Use std::quoted to read and write quoted strings.  See
  //        1) https://en.cppreference.com/w/cpp/io/manip/quoted
  //        2) https://www.youtube.com/watch?v=Mu-GUZuU31A

  /////////////////////// END-TO-DO (21) ////////////////////////////
}

std::ostream& operator<<(std::ostream& stream, const Book& book) {
  ///////////////////////// TO-DO (22) //////////////////////////////
  // This function should be symmetrical with operator>> above.
  /////////////////////// END-TO-DO (22) ////////////////////////////
}