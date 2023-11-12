#ifndef COVIDCOLLECTION_H
#define COVIDCOLLECTION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>

namespace sdds {
	struct Covid {
		std::string country;
		std::string city;
		std::string variant;
		int year;
		unsigned int numCases;
		unsigned int numDeaths;
	};
	class CovidCollection {
		std::vector<Covid> covidArray;
	public:
		//CovidCollection();
		CovidCollection(std::string fileName);
		void display(std::ostream& out) const;
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);

}
#endif