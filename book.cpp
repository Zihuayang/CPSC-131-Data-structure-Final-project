#include <cmath>                                                      // abs(), pow()
#include <iomanip>                                                    // quoted()
#include <iostream>
#include <string>
#include <type_traits>                                                // is_floating_point_v, common_type_t
#include <utility>                                                    // move()

#include "book.hpp"

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/

// Default and Conversion Constructor
Book::Book(std::string title, std::string author, std::string isbn, double price)
{
    _title = title;
    _author = author;
    _isbn = isbn;
    _price = price;

}

// Copy constructor
Book::Book(Book const& other)

    = default;


// Copy Assignment Operator
Book& Book::operator=(Book const& rhs)&

    = default;


// Destructor
Book::~Book() noexcept

    = default;


/*******************************************************************************
**  Accessors
*******************************************************************************/

// isbn() const
std::string const& Book::isbn() const&
{
    return _isbn;
}




// title() const
std::string const& Book::title() const&
{
    return _title;
}




// author() const
std::string const& Book::author() const&
{
    return _author;
}



// price() const
double Book::price() const&
{
    return _price;
}




// isbn()
std::string Book::isbn()&&
{
    return std::move(_isbn);
}




// title()
std::string Book::title()&&
{
    return std::move(_title);
}




// author()
std::string Book::author()&&
{
    return std::move(_author);
}








/*******************************************************************************
**  Modifiers
*******************************************************************************/

// isbn()
Book& Book::isbn(std::string newIsbn)&
{
    _isbn = std::move(newIsbn);
    return *this;
}




// title()
Book& Book::title(std::string newTitle)&
{
    _title = std::move(newTitle);
    return *this;
}




// author()
Book& Book::author(std::string newAuthor)&
{
    _author = std::move(newAuthor);
    return *this;
}




// price()
Book& Book::price(double newPrice)&
{
    _price = std::move(newPrice);
    return *this;
}



/*******************************************************************************
**  Relational Operators
*******************************************************************************/


// operator==
bool Book::operator==(const Book& rhs) const noexcept
{
    // All attributes must be equal for the two books to be equal to the other.  This can be done in any order, so put the quickest
    // and then the most likely to be different first.

    return _price == rhs._price && _isbn == rhs._isbn && _title == rhs._title && _author == rhs._author;

}

// operator!=
bool Book::operator!=(const Book& rhs) const noexcept
{
    // Two books are unequal if any of their attributes are unequal.

    return _price != rhs._price || _isbn != rhs._isbn || _title != rhs._title || _author != rhs._author;

}

// operator<
bool Book::operator<(const Book& rhs) const noexcept
{
    // Books are ordered (sorted) by ISBN, author, title, then price.

    bool compare = false;

    if (isbn() == rhs.isbn())
    {
        if (author() == rhs.author())
        {
            if (title() == rhs.title())
            {
                if (price() < rhs.price())
                {
                    compare = true;
                }
            }
            else if (title() < rhs.title())
            {
                compare = true;
            }
        }
        else if (author() < rhs.author())
        {
            compare = true;
        }
    }
    else if (isbn() < rhs.isbn())
    {
        compare = true;
    }

    return compare;
}

// operator<=
bool Book::operator<=(const Book& rhs) const noexcept
{
    // Books are ordered (sorted) by ISBN, author, title, then price.

    bool compare = true;

    if (isbn() == rhs.isbn())
    {
        if (author() == rhs.author())
        {
            if (title() == rhs.title())
            {
                if (price() > rhs.price())
                {
                    compare = false;
                }
            }
            else if (title() > rhs.title())
            {
                compare = false;
            }
        }
        else if (author() > rhs.author())
        {
            compare = false;
        }
    }
    else if (isbn() > rhs.isbn())
    {
        compare = false;
    }

    return compare;
}

// operator>
bool Book::operator>(const Book& rhs) const noexcept
{
    // Books are ordered (sorted) by ISBN, author, title, then price.

    bool compare = false;

    if (isbn() == rhs.isbn())
    {
        if (author() == rhs.author())
        {
            if (title() == rhs.title())
            {
                if (price() > rhs.price())
                {
                    compare = true;
                }
            }
            else if (title() > rhs.title())
            {
                compare = true;
            }
        }
        else if (author() > rhs.author())
        {
            compare = true;
        }
    }
    else if (isbn() > rhs.isbn())
    {
        compare = true;
    }

    return compare;
}

// operator>=
bool Book::operator>=(const Book& rhs) const noexcept
{
    // Books are ordered (sorted) by ISBN, author, title, then price.

    bool compare = true;
    if (isbn() == rhs.isbn())
    {
        if (author() == rhs.author())
        {
            if (title() == rhs.title())
            {
                if (price() < rhs.price())
                {
                    compare = false;
                }
            }
            else if (title() < rhs.title())
            {
                compare = false;
            }
        }
        else if (author() < rhs.author())
        {
            compare = false;
        }
    }
    else if (isbn() < rhs.isbn())
    {
        compare = false;
    }

    return compare;
}







/*******************************************************************************
**  Insertion and Extraction Operators
*******************************************************************************/

// operator>>
std::istream& operator>>(std::istream& stream, Book& book)
{
    /// A lot can go wrong when reading from streams - no permission, wrong types, end of file, etc. Minimal exception guarantee says
    /// there should be no side affects if an error or exception occurs, so let's do our work in a local object and move it into place
    /// at the end if all goes well.
    ///
    /// This function should be symmetrical with operator<< below.  Read what your write, and write what you read
    ///
    ///
    /// Assume fields are separated by commas and string attributes are enclosed with double quotes.  For example:
    ///    ISBN             | Title                 | Author             | Price
    ///    -----------------+-----------------------+--------------------+-----
    ///    "9789998287532",   "Over in the Meadow",   "Ezra Jack Keats",   91.11
    ///
    ///
    /// Hint:  Use std::quoted to read and write quoted strings.  See
    ///        1) https://en.cppreference.com/w/cpp/io/manip/quoted
    ///        2) https://www.youtube.com/watch?v=Mu-GUZuU31A


    std::string isbn, title, author;
    char gap1, gap2, gap3;
    double price;
    stream >> std::quoted(isbn);
    stream >> gap1;
    book._isbn = isbn;
    stream >> std::quoted(title);
    stream >> gap2;
    book._title = title;
    stream >> std::quoted(author);
    book._author = author;
    stream >> gap3;
    stream >> price;
    book._price = price;
    return stream;

}




// operator<<
std::ostream& operator<<(std::ostream& stream, const Book& book)
{

    /// This function should be symmetrical with operator>> above.  Read what your write, and write what you read
    std::string isbn, title, author;
    std::string gap = ",";
    double price = 0.0;
    isbn = book._isbn;
    stream << std::quoted(isbn);
    stream << gap;
    title = book._title;
    stream << std::quoted(title);
    stream << gap;
    author = book._author;
    stream << std::quoted(author);
    stream << gap;
    price = book._price;
    stream << price << "\n";
    return stream;
}
