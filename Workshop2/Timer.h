/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Date : 12 - 07 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <chrono>

namespace sdds
{
    class Timer {
    public:
        Timer();

        void start();

        long long stop() const;

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
    };
}

#endif // SDDS_TIMER_H