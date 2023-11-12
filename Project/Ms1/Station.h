// Name: Sakshi Sakshi
// Seneca Student ID: 112602222
// Seneca email: ssakshi7@myseneca.ca
// Date of completion: 11 November, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>

namespace sdds
{
    class Station
    {
        int m_id;
        std::string m_name;
        std::string m_desc;
        unsigned int m_nextSerialNum;
        unsigned int m_stockNum;
        static size_t m_widthField;
        static int id_generator;

    public:
        Station();
        Station(const std::string& record);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}

#endif