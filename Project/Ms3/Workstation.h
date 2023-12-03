// Name: Sakshi Sakshi
// Seneca Student ID: 112602222
// Seneca email: ssakshi7@myseneca.ca
// Date of completion: 2 December, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <deque>
#include <ostream>
#include <string>
#include "Station.h"
#include "CustomerOrder.h"

namespace sdds {
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;

    class Workstation : public Station {
        std::deque<CustomerOrder> m_orders;
        Workstation* m_pNextStation = nullptr;
    public:
        Workstation(const std::string&);
        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station = nullptr);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);
        // Since a Workstation object represents a single location on the assembly line, the object cannot be copied or moved.
        Workstation(const Workstation&) = delete;
        Workstation(Workstation&&) = delete;
        Workstation& operator=(const Workstation&) = delete;
        Workstation& operator=(Workstation&&) = delete;
    };
}

#endif