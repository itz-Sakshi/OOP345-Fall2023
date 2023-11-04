/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iomanip>
#include "Book.h"

namespace sdds {
    template <typename T, unsigned int C>
    class Collection {
        
        unsigned int m_size{};
        static T m_smallestItem;
        static T m_largestItem;
        
    protected:
        T m_items[C];
        void setSmallestItem(const T& item) {
            if (m_smallestItem > item) {
                m_smallestItem = item;
            }
        }

        void setLargestItem(const T& item) {
            if (m_largestItem < item) {
                m_largestItem = item;
            }
        }

        T operator[](const int index) {
            return m_items[index];
        }

        void incrementSize() {
            if (m_size < C) {
                m_size++;
            }
        }

    public:
        T getSmallestItem() const {
            return m_smallestItem;
        }

        T getLargestItem() const {
            return m_largestItem;
        }

        unsigned int size() const {
            return m_size;
        }

        unsigned int capacity() const {
            return C;
        }

        bool operator+=(const T& item) {
            bool Added = false;
            if (m_size < C) {
                setSmallestItem(item);
                setLargestItem(item);
                m_items[m_size] = item;
                m_size++;
                Added = true;
            }
            return Added;
        }

        std::ostream& print(std::ostream& os) const {
            os << "[";
            for (unsigned int i = 0; i < m_size; i++) {
                os << std::fixed << std::setprecision(1) << m_items[i];
                if (i != m_size - 1) {
                    os << ",";
                }
            }
            os << "]" << std::endl;
            return os;
        }
    };

    template <typename T, unsigned int C>
    T Collection<T, C>::m_smallestItem = 9999;
    template <typename T, unsigned int C>
    T Collection<T, C>::m_largestItem = -9999;
    template <>
    Book Collection<Book, 10>::m_smallestItem{ "", 1, 10000 };
    template <>
    Book Collection<Book, 10>::m_largestItem{ "", 10000, 1 };
    template <>
    Book Collection<Book, 72>::m_smallestItem{ "", 1, 10000 };
    template <>
    Book Collection<Book, 72>::m_largestItem{ "", 10000, 1 };

    template <>
    std::ostream& Collection<Book, 10>::print(std::ostream& os) const {
        os << "| ---------------------------------------------------------------------------|" << std::endl;
        for (unsigned int i = 0; i < m_size; i++) {
            os << "| ";
            m_items[i].print(os);
            os << " |" << std::endl;
        }
        os << "| ---------------------------------------------------------------------------|" << std::endl;
        return os;
    }

    template <>
    std::ostream& Collection<Book, 72>::print(std::ostream& os) const {
        os << "| ---------------------------------------------------------------------------|" << std::endl;
        for (unsigned int i = 0; i < m_size; i++) {
            os << "| ";
            m_items[i].print(os);
            os << " |" << std::endl;
        }
        os << "| ---------------------------------------------------------------------------|" << std::endl;
        return os;
    }
} 
#endif  // SDDS_COLLECTION_H