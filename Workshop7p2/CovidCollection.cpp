/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
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
				covidCase.country.erase(0, covidCase.country.find_first_not_of(" \t"));
				covidCase.country.erase(covidCase.country.find_last_not_of(" \t") + 1);
				covidCase.city.erase(0, covidCase.city.find_first_not_of(" \t"));
				covidCase.city.erase(covidCase.city.find_last_not_of(" \t") + 1);
				covidCase.variant.erase(0, covidCase.variant.find_first_not_of(" \t"));
				covidCase.variant.erase(covidCase.variant.find_last_not_of(" \t") + 1);
				covidArray.push_back(covidCase);
			}
		}
		else
		{
			throw "Filename is incorrect, failed to open file";
		}
	}
	void CovidCollection::display(std::ostream& out, const std::string& country) const
	{
		if (country != "ALL")
			out << "Displaying information of country = " << country << std::endl;
		size_t totalWorldCases = std::accumulate(covidArray.begin(), covidArray.end(), (size_t)0, [](const size_t& totalWorldCases, const Covid& theCovid)
			{
				return totalWorldCases + theCovid.numCases;
			});
		size_t totalWorldDeaths = std::accumulate(covidArray.begin(), covidArray.end(), (size_t)0, [](const size_t& totalWorldDeaths, const Covid& theCovid)
			{
				return totalWorldDeaths + theCovid.numDeaths;
			});
		if (country == "ALL")
		{
			std::for_each(covidArray.begin(), covidArray.end(), [&out](const Covid& covid) {
				out << covid << std::endl;
				});
			out << "| " << std::setw(79) << "Total cases around the world: " << totalWorldCases << " |" << std::endl;
			out << "| " << std::setw(79) << "Total deaths around the world: " << totalWorldDeaths << " |" << std::endl;
		}
		else
		{
			size_t totalCases = 0;
			size_t totalDeaths = 0;
			std::for_each(covidArray.begin(), covidArray.end(), [&totalCases, &totalDeaths, &country, &out](const Covid& theCovid)
				{
					if (theCovid.country == country) {
						totalCases += theCovid.numCases;
						totalDeaths += theCovid.numDeaths;
						out << theCovid << std::endl;
					}
				});
			double casePercentage = (static_cast<double>(totalCases) / totalWorldCases) * 100.0;
			double deathPercentage = (static_cast<double>(totalDeaths) / totalWorldDeaths) * 100.0;
			std::string caseStr = "Total cases in " + country;
			std::string deathStr = "Total deaths in " + country;
			std::stringstream percentStr{};
			out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
			out << "| " << std::right << std::setw(78) << caseStr << ": " << std::setw(4) << totalCases << " |" << std::endl;
			out << "| " << std::right << std::setw(78) << deathStr << ": " << std::setw(4) << totalDeaths << " |" << std::endl;
			percentStr << country << " has " << std::setprecision(6) << std::setiosflags(std::ios::fixed) << casePercentage << "% of global cases and " << deathPercentage << "% of global deaths";
			out << "|" << std::setw(85) << percentStr.str() << " |\n" << std::resetiosflags(std::ios::right);
		}
	}
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid)
	{

		out << "| " << std::setw(21) << std::left << theCovid.country << " | "
			<< std::setw(15) << std::left << theCovid.city << " | "
			<< std::setw(20) << std::left << theCovid.variant << " | " << std::right << std::setw(6);
		if (theCovid.year < 0) {
			out << "  ";
		}
		else {
			out << theCovid.year;
		}
		out << " | " << std::setw(4) << std::right << theCovid.numCases << " | "
			<< std::setw(3) << std::right << theCovid.numDeaths << " |"
			<< " | " << std::right << std::setw(8) << theCovid.infectionStatus << " |";

		return out;
	}
	void CovidCollection::sort(const std::string& field)
	{
		std::sort(covidArray.begin(), covidArray.end(), [field](const Covid& covid, const Covid& otherCovid)
			{
				if (field == "country" || field == "DEFAULT") {
					if (covid.country == otherCovid.country)
						return covid.numDeaths < otherCovid.numDeaths;
					return covid.country < otherCovid.country;
				}
				else if (field == "year") {
					if (covid.year == otherCovid.year)
						return covid.numDeaths < otherCovid.numDeaths;
					return covid.year < otherCovid.year;
				}
				else if (field == "variant") {
					if (covid.variant == otherCovid.variant)
						return covid.numDeaths < otherCovid.numDeaths;
					return covid.variant < otherCovid.variant;
				}
				else
				{
					return false;
				}

	    });
    }
	bool CovidCollection::inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const
	{
		bool result = std::any_of(covidArray.begin(), covidArray.end(), [&](const Covid& covid) {
			return (covid.country == country) && (covid.variant == variant) && (covid.numDeaths > deaths);
			});
		return result;
	}
	std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) const
	{
		std::list<Covid> result;
		std::copy_if(covidArray.begin(), covidArray.end(), std::back_inserter(result), [&](const Covid& theCovid) {
			return theCovid.numDeaths >= deaths;
			});
		return result;
	}
	void CovidCollection::updateStatus() {
		std::for_each(covidArray.begin(), covidArray.end(), [](Covid& theCovid) {
			if (theCovid.numDeaths > 300)
			theCovid.infectionStatus = "EPIDEMIC";
			else if (theCovid.numDeaths < 50)
				theCovid.infectionStatus = "EARLY";
			else
				theCovid.infectionStatus = "MILD";
			});
	}
}



