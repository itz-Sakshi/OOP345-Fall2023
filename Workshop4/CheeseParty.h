/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H

#include <iostream>
#include <iostream>
#include "Cheese.h"

namespace sdds
{
	class CheeseParty
	{
		const sdds::Cheese** m_cheeseArray{ nullptr };
		size_t m_numCheeses{ 0 };
		void clearCheeses();
	public:
		CheeseParty();
		CheeseParty& addCheese(const Cheese&);
		CheeseParty& removeCheese();
		~CheeseParty();
		friend std::ostream& operator<<(std::ostream& os, const CheeseParty& cheeseParty);
		CheeseParty(const CheeseParty&);
		CheeseParty& operator=(const CheeseParty&);
		CheeseParty(CheeseParty&& other) noexcept;
		CheeseParty& operator=(CheeseParty&& other) noexcept;
	};
}

#endif