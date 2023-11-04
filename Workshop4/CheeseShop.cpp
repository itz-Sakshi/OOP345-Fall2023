/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "CheeseShop.h"

using namespace std;
namespace sdds
{
    CheeseShop::CheeseShop(const std::string& name = "No Name") : m_name(name), m_cheeseArray(nullptr), m_numCheeses(0) {}

    

    CheeseShop::~CheeseShop() {
        clearCheeses();
    }

    CheeseShop& CheeseShop::addCheese(const Cheese& cheese) {
        const sdds::Cheese** newCheeses = new const sdds::Cheese * [m_numCheeses + 1];

        for (size_t i = 0; i < m_numCheeses; i++) {
            newCheeses[i] = m_cheeseArray[i];
        }

        newCheeses[m_numCheeses] = new Cheese(cheese);

        delete[] m_cheeseArray;
        m_cheeseArray = newCheeses;
        m_numCheeses++;

        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const CheeseShop& shop) {
        os << "--------------------------" << std::endl;
        os << shop.m_name << std::endl;
        os << "--------------------------" << std::endl;

        if (shop.m_numCheeses == 0) {
            os << "This shop is out of cheese!" << std::endl;
        }
        else {
            for (size_t i = 0; i < shop.m_numCheeses; i++) {
                os << *(shop.m_cheeseArray[i]);
            }
        }
        os << "--------------------------" << std::endl;

        return os;
    }
    CheeseShop::CheeseShop(const CheeseShop& other) : m_name(other.m_name), m_numCheeses(other.m_numCheeses) {
        m_cheeseArray = new const sdds::Cheese * [m_numCheeses];
        for (size_t i = 0; i < m_numCheeses; i++) {
            m_cheeseArray[i] = new const sdds::Cheese(*(other.m_cheeseArray[i])); 
        }
    }

 
    CheeseShop& CheeseShop::operator=(const CheeseShop& other) {
        if (this == &other) {
            return *this; 
        }
        clearCheeses();
        m_name = other.m_name;
        m_numCheeses = other.m_numCheeses;
        m_cheeseArray = new const sdds::Cheese * [m_numCheeses];
        for (size_t i = 0; i < m_numCheeses; i++) {
            m_cheeseArray[i] = new const sdds::Cheese(*(other.m_cheeseArray[i])); 
        }

        return *this;
    }

    // Move constructor 
    CheeseShop::CheeseShop(CheeseShop&& other) noexcept
        : m_name(std::move(other.m_name)),
        m_cheeseArray(other.m_cheeseArray),
        m_numCheeses(other.m_numCheeses) {
        other.m_cheeseArray = nullptr;
        other.m_numCheeses = 0;
    }

    // Move assignment 
    CheeseShop& CheeseShop::operator=(CheeseShop&& other) noexcept {
        if (this == &other) {
            return *this; 
        }
        clearCheeses();
        m_name = std::move(other.m_name);
        m_cheeseArray = other.m_cheeseArray;
        m_numCheeses = other.m_numCheeses;   
        other.m_cheeseArray = nullptr;
        other.m_numCheeses = 0;

        return *this;
    }
    void CheeseShop::clearCheeses() {
        for (size_t i = 0; i < m_numCheeses; ++i) {
            delete m_cheeseArray[i]; 
        }
        delete[] m_cheeseArray; 
        m_cheeseArray = nullptr;
        m_numCheeses = 0;
    }

}