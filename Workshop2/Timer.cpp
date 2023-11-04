<<<<<<< HEAD
/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Date : 12 - 07 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/
using namespace std;
#include "Timer.h"

namespace sdds {
    Timer::Timer() : m_start(std::chrono::high_resolution_clock::now()) {}

    void Timer::start() {
        m_start = std::chrono::high_resolution_clock::now();
    }

    long long Timer::stop() const {
        auto m_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = m_end - m_start;
        return duration.count();
    }
}
=======
/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Date : 12 - 07 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/
using namespace std;
#include "Timer.h"

namespace sdds {
    Timer::Timer() : m_start(std::chrono::high_resolution_clock::now()) {}

    void Timer::start() {
        m_start = std::chrono::high_resolution_clock::now();
    }

    long long Timer::stop() const {
        auto m_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = m_end - m_start;
        return duration.count();
    }
}
>>>>>>> origin/main
