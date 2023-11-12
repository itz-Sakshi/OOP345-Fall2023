#include "CovidCollection.h"

namespace sdds {
	CovidCollection::CovidCollection(std::string fileName)
	{
		Covid covidCase{};
		std::ifstream fin(fileName);
		if (fin.is_open())
		{
			std::string line;
			while (std::getline(fin, line))
				{
				covidCase.country = line.substr(0, 25);
				covidCase.city = line.substr(25, 25);
				covidCase.variant = line.substr(50, 25);
				covidCase.year = std::stoi(line.substr(75, 5));
				covidCase.numCases = std::stoi(line.substr(80, 5));
				covidCase.numDeaths = std::stoi(line.substr(85, 5));
				covidArray.push_back(covidCase);
				}
		}
		else
		{
			throw "Filename is incorrect, failed to open file";
		}
	}
	void CovidCollection::display(std::ostream& out) const
	{
		std::for_each(covidArray.begin(), covidArray.end(), [&](const Covid& covidCase) {
				out << covidCase << std::endl;
			}
		);
	}
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid)
	{
		
		out << "| " << std::setw(21) << std::left << theCovid.country << " | "
			<< std::setw(15) << std::left << theCovid.city << " | "
			<< std::setw(20) << std::left << theCovid.variant << " | ";
			if (theCovid.year < 0) {
				out << "  ";
			}
			else {
				out << theCovid.year;
			}
			out << std::setw(4) << std::right << theCovid.numCases << " | "
			<< std::setw(3) << std::right << theCovid.numDeaths << " |";
		return out;
	}
}



