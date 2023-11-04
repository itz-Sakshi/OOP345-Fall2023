/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H

#include <string>
#include <iostream>
#include <sstream>

namespace sdds {
	class Cheese
	{
		std::string m_name;
		int m_weightInGrams;
		double m_pricePerGram;
		std::string m_features;
	public:
		Cheese();
		Cheese(const std::string& str);
		Cheese(const Cheese& otherCheese);
		Cheese& operator=(const Cheese& otherCheese);
		Cheese slice(size_t weight);
		std::string getName() const;
		int getWeight() const;
		double getPrice() const;
		std::string getFeatures() const;
		~Cheese();

	};
	std::string trim(const std::string& str);
	std::ostream& operator<<(std::ostream& os, const Cheese& cheese);
	
}


# endif