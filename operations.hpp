#ifndef _operations_hpp_

#define _operations_hpp_



#include <forward_list>

#include <list>

#include <map>

#include <string>

#include <unordered_map>

#include <utility>

#include <vector>



#include "book.hpp"



//

// INSERT OPERATIONS

//



struct insert_at_back_of_vector {

  // Function takes a constant Book as a parameter, inserts that book at the
  // back of a vector, and returns nothing.

  void operator()(const Book& book) {

    ///////////////////////// TO-DO (1) //////////////////////////////



    my_vector.push_back(book);





    /////////////////////// END-TO-DO (1) ////////////////////////////

  }



  std::vector<Book>& my_vector;

};



struct insert_at_back_of_dll {

  // Function takes a constant Book as a parameter, inserts that book at the
  // back of a doubly linked list, and returns nothing.

  void operator()(const Book& book) {

    ///////////////////////// TO-DO (2) //////////////////////////////



    my_dll.push_back(book);



    /////////////////////// END-TO-DO (2) ////////////////////////////

  }



  std::list<Book>& my_dll;

};



struct insert_at_back_of_sll {

  // Function takes a constant Book as a parameter, inserts that book at the
  // back of a singly linked list, and returns nothing.

  void operator()(const Book& book) {

    ///////////////////////// TO-DO (3) //////////////////////////////





    std::forward_list<Book>::iterator bef_back = my_sll.before_begin();

    for (auto& x : my_sll) {

    ++bef_back;

    }

    my_sll.insert_after(bef_back, book);



    /////////////////////// END-TO-DO (3) ////////////////////////////

  }



  std::forward_list<Book>& my_sll;

};



struct insert_at_front_of_vector {

  // Function takes a constant Book as a parameter, inserts that book at the
  // front of a vector, and returns nothing.

  void operator()(const Book& book) {

    ///////////////////////// TO-DO (4) //////////////////////////////



    my_vector.insert(my_vector.begin(), book);



    /////////////////////// END-TO-DO (4) ////////////////////////////

  }



  std::vector<Book>& my_vector;

};



struct insert_at_front_of_dll {

  // Function takes a constant Book as a parameter, inserts that book at the
  // front of a doubly linked list, and returns nothing.

  void operator()(const Book& book) {

    ///////////////////////// TO-DO (5) //////////////////////////////



    my_dll.insert(my_dll.begin(), book);



    /////////////////////// END-TO-DO (5) ////////////////////////////

  }



  std::list<Book>& my_dll;

};



struct insert_at_front_of_sll{

  // Function takes a constant Book as a parameter, inserts that book at the
  // front of a singly linked list, and returns nothing.

  void operator()(const Book& book) {

    ///////////////////////// TO-DO (6) //////////////////////////////



    my_sll.push_front(book);



    /////////////////////// END-TO-DO (6) ////////////////////////////

  }



  std::forward_list<Book>& my_sll;

};



struct insert_into_bst {

  // Function takes a constant Book as a parameter, inserts that book indexed by
  // the book's ISBN into a binary search tree, and returns nothing.

  void operator()(const Book& book) {

    ///////////////////////// TO-DO (7) //////////////////////////////



    if(my_bst.find(book.isbn()) == my_bst.end()) {

             my_bst[book.isbn()] = book;

            }

              else {

                return;

            }



    /////////////////////// END-TO-DO (7) ////////////////////////////

  }



  std::map<std::string, Book>& my_bst;

};



struct insert_into_hash_table {

  // Function takes a constant Book as a parameter, inserts that book indexed by
  // the book's ISBN into a hash table, and returns nothing.

  void operator()(const Book& book) {

    ///////////////////////// TO-DO (8) //////////////////////////////



    if(my_hash_table.find(book.isbn()) == my_hash_table.end()) {

            my_hash_table[book.isbn()] = book;

        }

        else {

            return;

        }



    /////////////////////// END-TO-DO (8) ////////////////////////////

  }



  std::unordered_map<std::string, Book>& my_hash_table;

};



//

// REMOVE OPERATIONS

//



struct remove_from_back_of_vector {

  // Function takes no parameters, removes the book at the back of a vector, and
  // returns nothing.

  void operator()(const Book& unused) {

    ///////////////////////// TO-DO (9) //////////////////////////////



    if(!my_vector.empty()){

      my_vector.pop_back();

    }

    else{

      throw std::out_of_range("vector is empty");

    }



    /////////////////////// END-TO-DO (9) ////////////////////////////

  }



  std::vector<Book>& my_vector;

};



struct remove_from_back_of_dll {

  // Function takes no parameters, removes the book at the back of a doubly
  // linked list, and returns nothing.

  void operator()(const Book& unused) {

    ///////////////////////// TO-DO (10) //////////////////////////////



    if (my_dll.empty()) {

      throw std::out_of_range("SLL is empty!");

    }

    else {

    my_dll.pop_back();

    }



    /////////////////////// END-TO-DO (10) ////////////////////////////

  }



  std::list<Book>& my_dll;

};



struct remove_from_back_of_sll {

  // Function takes no parameters, removes the book at the back of a singly
  // linked list, and returns nothing.

  void operator()(const Book& unused) {

    ///////////////////////// TO-DO (11) //////////////////////////////





    if (my_sll.empty())

      {

          throw std::out_of_range("SLL is empty!");

      }

          auto pred = my_sll.before_begin();

          auto curr = my_sll.begin();

          curr++;

          while (curr != my_sll.end())

          {

              curr++;

              pred++;

          }



          my_sll.erase_after(pred, curr);

          return;



    /////////////////////// END-TO-DO (11) ////////////////////////////



  }

  std::forward_list<Book>& my_sll;

};



struct remove_from_front_of_vector {

  // Function takes no parameters, removes the book at the front of a vector,
  // and returns nothing.

  void operator()(const Book& unused) {

    ///////////////////////// TO-DO (12) //////////////////////////////



    if (my_vector.empty()) {

    throw std::out_of_range("vector is empty");

    }

    else {

    my_vector.erase(my_vector.begin());

    }



    /////////////////////// END-TO-DO (12) ////////////////////////////

  }



  std::vector<Book>& my_vector;

};



struct remove_from_front_of_dll {

  // Function takes no parameters, removes the book at the front of a doubly
  // linked list, and returns nothing.

  void operator()(const Book& unused) {

    ///////////////////////// TO-DO (13) //////////////////////////////



    if (my_dll.empty()) {

      throw std::out_of_range("Dll is empty");

    }

    else {

      my_dll.pop_front();

    }



    /////////////////////// END-TO-DO (13) ////////////////////////////

  }



  std::list<Book>& my_dll;

};



struct remove_from_front_of_sll {

  // Function takes no parameters, removes the book at the front of a singly
  // linked list, and returns nothing.

  void operator()(const Book& unused) {

    ///////////////////////// TO-DO (14) //////////////////////////////



    if (my_sll.empty()) {

   throw std::out_of_range("Sll is empty");

    }

    else {

    my_sll.pop_front();

    }



    /////////////////////// END-TO-DO (14) ////////////////////////////

  }



  std::forward_list<Book>& my_sll;

};



struct remove_from_bst {

  // Function takes a constant Book as a parameter, finds and removes from the
  // binary search tree the book with a matching ISBN (if any), and returns
  // nothing. If no Book matches the ISBN, the method does nothing.

  void operator()(const Book& book) {

    ///////////////////////// TO-DO (15) //////////////////////////////



    if(my_bst.find(book.isbn()) == my_bst.end()) {}

              else {

                 my_bst.erase(my_bst.find(book.isbn()));

                 return;

            }





    /////////////////////// END-TO-DO (15) ////////////////////////////

  }



  std::map<std::string, Book>& my_bst;

};



struct remove_from_hash_table {

  // Function takes a constant Book as a parameter, finds and removes from the
  // hash table the book with a matching ISBN (if any), and returns nothing. If
  // no Book matches the ISBN, the method does nothing.

  void operator()(const Book& book) {

    ///////////////////////// TO-DO (16) //////////////////////////////



    if(my_hash_table.find(book.isbn()) == my_hash_table.end()) {}

        else {

            my_hash_table.erase(my_hash_table.find(book.isbn()));

            return;

        }



    /////////////////////// END-TO-DO (16) ////////////////////////////

  }



  std::unordered_map<std::string, Book>& my_hash_table;

};



//

// SEARCH OPERATIONS

//



struct search_within_vector {

  // Function takes no parameters, searches a vector for a book with an ISBN
  // matching the target ISBN, and returns a pointer to that found book if such
  // a book is found, nullptr otherwise.

  Book* operator()(const Book& unused) {

    ///////////////////////// TO-DO (17) //////////////////////////////

    for(int i = 0; i < my_vector.size(); i++) {

    if(my_vector[i].isbn() == target_isbn) {

      return &(my_vector[i]);
      }
    }
    
    return nullptr;



    /////////////////////// END-TO-DO (17) ////////////////////////////

  }


  std::vector<Book>& my_vector;

  const std::string target_isbn;

};



struct search_within_dll {

  // Function takes no parameters, searches a doubly linked list for a book with
  // an ISBN matching the target ISBN, and returns a pointer to that found book
  // if such a book is found, nullptr otherwise.

  Book* operator()(const Book& unused) {

    ///////////////////////// TO-DO (18) //////////////////////////////

    std::list<Book>::iterator it = my_dll.begin();

    while (it != my_dll.end()){

      if (it ->isbn() == target_isbn) {

        return &(*it);

      }

      it++;

    }

        return nullptr;

      }

    /////////////////////// END-TO-DO (18) ////////////////////////////



  std::list<Book>& my_dll;

  const std::string target_isbn;

};



struct search_within_sll {

  // Function takes no parameters, searches a singly linked list for a book with
  // an ISBN matching the target ISBN, and returns a pointer to that found book
  // if such a book is found, nullptr otherwise.

  Book* operator()(const Book& unused) {

    ///////////////////////// TO-DO (19) //////////////////////////////

    std::forward_list<Book>::iterator it = my_sll.begin();

    while (it != my_sll.end()) {

      if (it ->isbn() == target_isbn) {

        return &(*it);

      }

      it++;

    }

        return nullptr;

     }

    /////////////////////// END-TO-DO (19) ////////////////////////////



  std::forward_list<Book>& my_sll;

  const std::string target_isbn;

};



struct search_within_bst {

  // Function takes no parameters, searches a binary search tree for a book with
  // an ISBN matching the target ISBN, and returns a pointer to that found book
  // if such a book is found, nullptr otherwise.

  Book* operator()(const Book& unused) {

    ///////////////////////// TO-DO (20) //////////////////////////////



    if(my_bst.find(target_isbn) == my_bst.end()) {

        return nullptr;

    }

    else

    {

        return &(my_bst.find(target_isbn)->second);

    }



    /////////////////////// END-TO-DO (20) ////////////////////////////

  }



  std::map<std::string, Book>& my_bst;

  const std::string target_isbn;

};



struct search_within_hash_table {

  // Function takes no parameters, searches a hash table for a book with an ISBN
  // matching the target ISBN, and returns a pointer to that found book if such
  // a book is found, nullptr otherwise.

  Book* operator()(const Book& unused) {

    ///////////////////////// TO-DO (21) //////////////////////////////



      if(my_hash_table.find(target_isbn) == my_hash_table.end()) {

            return nullptr;

        }

      else {

        return &(my_hash_table.find(target_isbn)->second);

        }



    /////////////////////// END-TO-DO (21) ////////////////////////////

  }



  std::unordered_map<std::string, Book>& my_hash_table;

  const std::string target_isbn;

};



#endif
