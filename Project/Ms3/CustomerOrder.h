// Name: Sakshi Sakshi
// Seneca Student ID: 112602222
// Seneca email: ssakshi7@myseneca.ca
// Date of completion: 18 November, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <utility>
#include <iomanip>
#include <iostream>
#include <string>
#include "Station.h"

namespace sdds
{
    struct Item
    {
        std::string m_itemName{};
        size_t m_serialNumber{ 0 };
        bool m_isFilled{ false };
        Item(const std::string& src) : m_itemName(src) {};
    };

    class CustomerOrder
    {
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{};
        Item** m_lstItem{};
        static size_t m_widthField;

    public:
        CustomerOrder();
        CustomerOrder(const std::string& str);
        CustomerOrder(const CustomerOrder& c); //The copy constructor should throw an exception if called
        //the copy operator= should be deleted.
        CustomerOrder& operator=(const CustomerOrder& c) = delete;
        CustomerOrder(CustomerOrder&& c) noexcept;
        CustomerOrder& operator=(CustomerOrder&& c) noexcept;
        bool isOrderFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;
        ~CustomerOrder();
    };
}

#endif