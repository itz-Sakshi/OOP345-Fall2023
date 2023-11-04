/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "Book.h"
#include <iomanip>
#include <iostream>
#include <string>

namespace sdds {
    Book::Book(const std::string& title, unsigned nChapters, unsigned nPages) {
        m_title = title;
        m_numChapters = nChapters;
        m_numPages = nPages;
    }

    std::ostream& Book::print(std::ostream& os) const {
        if (!m_title.empty() && m_numChapters != 0 && m_numPages != 0) {
            std::string chapters = std::to_string(m_numChapters);
            std::string pages = std::to_string(m_numPages);
            os << " " << std::right << std::setw(55) << m_title + "," + chapters + "," + pages << " | ";
            os << "(" << std::fixed << std::setprecision(6) << (double)m_numPages / m_numChapters << ")    ";
        }
        else {
            os << "| Invalid book data";
        }
        return os;
    }

    Book& Book::operator=(const Book& book) {
        if (this != &book) {
            m_title = book.m_title;
            m_numChapters = book.m_numChapters;
            m_numPages = book.m_numPages;
        }
        return *this;
    }

    bool Book::operator<(const Book& book) {
        return ((double)m_numPages / m_numChapters < (double)book.m_numPages / book.m_numChapters);
    }

    bool Book::operator>(const Book& book) {
        return ((double)m_numPages / m_numChapters > (double)book.m_numPages / book.m_numChapters);
    }

    std::ostream& operator<<(std::ostream& os, const Book& bk) {
        return bk.print(os);
    }
} 