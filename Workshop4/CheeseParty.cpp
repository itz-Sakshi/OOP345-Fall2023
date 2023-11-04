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
#include "CheeseParty.h"

using namespace std;
namespace sdds
{
	CheeseParty::CheeseParty()
	{
		m_cheeseArray = nullptr;
	}
	CheeseParty& CheeseParty::addCheese(const Cheese& cheese)
	{
		for (size_t i = 0; i < m_numCheeses; i++)
		{
			if (m_cheeseArray[i] == &cheese) {
				return *this;
			}
		}
		const Cheese** newCheeses = new const Cheese * [m_numCheeses + 1];

		for (size_t i = 0; i < m_numCheeses; i++) {
			newCheeses[i] = m_cheeseArray[i];
		}

		newCheeses[m_numCheeses] = &cheese;

		delete[] m_cheeseArray;
		m_cheeseArray = newCheeses;
		m_numCheeses++;

		return *this;

	}
	CheeseParty& CheeseParty::removeCheese()
	{
		size_t validCount = 0;
		for (size_t i = 0; i < m_numCheeses; i++) {
			if (m_cheeseArray[i]->getWeight() != 0) {
				validCount++;
			}
		}


		const Cheese** validCheeses = new const Cheese * [validCount + 1];

		size_t newIndex = 0;
		for (size_t i = 0; i < m_numCheeses; i++) {
			if (m_cheeseArray[i]->getWeight() != 0) {
				validCheeses[newIndex++] = m_cheeseArray[i];
			}
		}


		clearCheeses();

	
		m_cheeseArray = validCheeses;
		m_numCheeses = validCount;

		return *this;
	}
	CheeseParty::~CheeseParty()
	{
		clearCheeses();
	}
	std::ostream& operator<<(std::ostream& os, const CheeseParty& cheeseParty)
	{
		os << "--------------------------" << std::endl;
		os << "Cheese Party" << std::endl;
		os << "--------------------------" << std::endl;

		if (cheeseParty.m_numCheeses == 0) {
			os << "This party is just getting started!" << std::endl;
		}
		else {
			for (size_t i = 0; i < cheeseParty.m_numCheeses; i++) {
				os << *(cheeseParty.m_cheeseArray[i]);
			}
		}
		os << "--------------------------" << std::endl;

		return os;
	}
	CheeseParty::CheeseParty(const CheeseParty& other) {
		m_numCheeses = other.m_numCheeses;
		m_cheeseArray = new const Cheese * [m_numCheeses];

		for (size_t i = 0; i < m_numCheeses; i++) {
			m_cheeseArray[i] = other.m_cheeseArray[i];
		}
	}

	CheeseParty& CheeseParty::operator=(const CheeseParty& other) {
		if (this == &other) {
			return *this; 
		}

		clearCheeses();

		m_numCheeses = other.m_numCheeses;

		m_cheeseArray = new const Cheese * [m_numCheeses];

		for (size_t i = 0; i < m_numCheeses; i++) {
			m_cheeseArray[i] = other.m_cheeseArray[i];
		}

		return *this;
	}
	void CheeseParty::clearCheeses() {
		delete[] m_cheeseArray;
		m_cheeseArray = nullptr;
		m_numCheeses = 0;
	}

	// Move constructor
	CheeseParty::CheeseParty(CheeseParty&& other) noexcept
		: m_cheeseArray(other.m_cheeseArray),
		m_numCheeses(other.m_numCheeses) {
		other.m_cheeseArray = nullptr;
		other.m_numCheeses = 0;
	}

	CheeseParty& CheeseParty::operator=(CheeseParty&& other) noexcept {
		if (this == &other) {
			return *this;
		}
		clearCheeses();
		m_cheeseArray = other.m_cheeseArray;
		m_numCheeses = other.m_numCheeses;
		other.m_cheeseArray= nullptr;
		other.m_numCheeses = 0;

		return *this;
	}

}