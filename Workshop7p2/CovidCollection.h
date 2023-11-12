/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

namespace sdds {
	struct Covid {
		std::string country{};
		std::string city{};
		std::string variant{};
		int year{};
		unsigned int numCases{};
		unsigned int numDeaths{};
		std::string infectionStatus = "General";
	};
	class CovidCollection {
		std::vector<Covid> covidArray;
	public:
		//CovidCollection();
		CovidCollection(std::string fileName);
		void display(std::ostream& out, const std::string& country = "ALL") const;
		void sort(const std::string& field = "country");
		bool inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const;
		std::list<Covid> getListForDeaths(unsigned int deaths) const;
		void updateStatus();
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);

}
#endif