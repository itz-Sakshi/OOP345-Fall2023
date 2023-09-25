// Workshop 2 - Summer 2023
// w2_p1.cpp
// Rania Arbash

#include <iostream>
#include <iomanip>
#include <string>
#include "AirportModels.h"

// Cheching if header guards exist and follow convention.
#ifndef SDDS_AIRPORTMODELS_H
#error "The header guard for 'AirportModels.h' doesn't follow the convention!"
#endif

int cout = 0; // won't compile if headers don't follow convention regarding namespaces


void printDivider(size_t cnt) {
    for (auto i = 0u; i < cnt; ++i)
        std::cout << "*";
    std::cout << std::endl;
}

void printHeader(const char* head) {
    std::cout << std::endl;
    printDivider(53);
    std::cout << head << std::endl;
    printDivider(53);
}


// ws airport_data.csv
int main(int argc, char** argv)
{
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; i++)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";

    if (argc != 2)
    {
        std::cerr << std::endl << "***Incorrect number of arguments***" << std::endl;
        return 1;
    }



    printHeader("Empty Airport Log entries");

    sdds::AirportLog alog1;

    std::cout << alog1[0] << std::endl;
    std::cout << alog1[30] << std::endl;
    std::cout << alog1[50] << std::endl;
    std::cout << alog1[size_t(alog1) - 1] << std::endl;



    printHeader("Non Empty Airport Log entries");

    sdds::AirportLog alog2(argv[1]);

    std::cout << alog2[0] << std::endl;
    std::cout << alog2[30] << std::endl;
    std::cout << alog2[100] << std::endl;
    std::cout << alog2[200] << std::endl;
    std::cout << alog2[300] << std::endl;

    std::cout << alog2[size_t(alog2) - 1] << std::endl;



    printHeader("Add to Empty Airport Log");
    sdds::Airport a1{ "ADK","Adak Airport","Adak","AK","USA",51.87796,-176.64603 };
    sdds::Airport a2{ "DIK","Dickinson Theodore Roosevelt Regional Airport","Dickinson","ND","USA",46.79739,-102.80195 };
    sdds::Airport a3{ "IMT","Ford Airport","Iron Mountain/Kingsford","MI","USA",45.81835,-88.11454 };
    sdds::Airport a4{ "TYS","McGhee Tyson Airport","Knoxville","TN","USA",35.81249,-83.99286 };
    alog1.addAirport(a1);
    alog1.addAirport(a2);
    alog1.addAirport(a3);
    alog1.addAirport(a4);

    std::cout << alog1[0] << std::endl;
    std::cout << alog1[1] << std::endl;
    std::cout << alog1[2] << std::endl;
    std::cout << alog1[size_t(alog1) - 1] << std::endl;

    printHeader("Find specific state's airports");
    //std::cout << alog2.findAirport("NJ", "USA");
    sdds::AirportLog found = alog2.findAirport("AK", "USA");
    std::cout << "Number of matches found: " << size_t(found) << std::endl;
    std::cout << "First match found:\n" << found[0] << std::endl;
    std::cout << "Last match found:\n" << found[size_t(found) - 1] << std::endl;

    printHeader("Find an non existing airport");
    sdds::AirportLog notfound = alog2.findAirport("Ontario", "Canada");
    std::cout << "Number of airports found: " << size_t(notfound) << std::endl;

    return cout;
}