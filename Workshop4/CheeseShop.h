/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H

#include <iostream>
#include <iostream>
#include "Cheese.h"


namespace sdds
{
	class CheeseShop
	{
		std::string m_name;
	    const sdds::Cheese** m_cheeseArray;
		size_t m_numCheeses;
		void clearCheeses();
	public:
		CheeseShop(const std::string& name);
		CheeseShop& addCheese(const Cheese&);
		CheeseShop(const CheeseShop&);
		CheeseShop& operator=(const CheeseShop&);
		friend std::ostream& operator<<(std::ostream& os, const CheeseShop& shop);
		CheeseShop& operator=(CheeseShop&& other) noexcept;
		CheeseShop(CheeseShop&& other) noexcept;
		~CheeseShop();
	};
	
}

#endif