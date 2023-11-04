/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds {
    class Book {
        std::string m_title{};
        unsigned m_numChapters{};
        unsigned m_numPages{};

    public:
        Book() {};
        Book(const std::string& title, unsigned nChapters, unsigned nPages);
        Book& operator=(const Book& otherBook);
        bool operator<(const Book& otherBook);
        bool operator>(const Book& otherBook);

        std::ostream& print(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, const Book& bk);
}  
#endif  // SDDS_BOOK_H