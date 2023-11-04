/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H

#include "Collection.h"

namespace sdds {
    template <typename T>
    class OrderedCollection : public Collection<T, 72> {
    public:
        void operator+=(T item) {
            if (this->size() < 72) {
                this->m_items[this->size()] = item;
                for (unsigned int i = this->size(); i > 0; i--) {
                    if (this->m_items[i - 1] > this->m_items[i]) {
                        T temp = this->m_items[i - 1];
                        this->m_items[i - 1] = this->m_items[i];
                        this->m_items[i] = temp;
                    }
                }
                this->incrementSize();
                this->setSmallestItem(item);
                this->setLargestItem(item);
            }
        }
    };
} 
#endif  // SDDS_ORDEREDCOLLECTION_H