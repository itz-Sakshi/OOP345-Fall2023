// w4_p1.cpp
// Jan 28 2023
// Michael Huang

/*#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Cheese.h"

// Cheching if header guards exist and follow convention.
#ifndef SDDS_CHEESE_H
#error "The header guard for 'Cheese.h' doesn't follow the convention!"
#endif

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

void printdivider(size_t cnt, const std::string heading = "") {
    if (heading != "")
        std::cout << heading << "\n";
    for (auto i = 0u; i < cnt; ++i)
        std::cout << "-";
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; i++)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n";

    sdds::Cheese** cheeses = nullptr;
    size_t cnt = 0;

    // Process the file
    if (argc > 1) {
        std::ifstream file(argv[1]);
        if (!file) {
            std::cout << "ERROR: Cannot open file [" << argv[1] << "].\n";
            return 1;
        }

        std::string cheeseline;
        // count how many records are in the file
        do {
            std::getline(file, cheeseline);

            // if the previous operation failed, the "file" object is
            //   in error mode
            if (file) {
                // Check if this is a commented line.
                //   In the input file, commented lines start with '#'
                if (cheeseline[0] != '#')
                    ++cnt;
            }
        } while (file);

        cheeses = new sdds::Cheese * [cnt];
        cnt = 0;

        // read again from the file, but this time load and store data
        file.clear();
        file.seekg(std::ios::beg);
        do {
            std::getline(file, cheeseline);

            // if the previous operation failed, the "file" object is
            //   in error mode
            if (file) {
                // Check if this is a commented line.
                //   In the input file, commented lines start with '#'
                if (cheeseline[0] != '#') {
                    cheeses[cnt] = new sdds::Cheese(cheeseline);
                    ++cnt;
                }
            }
        } while (file);
        file.close();
    }
    else {
        std::cout << "ERROR: cheeses.txt file not provided.\n";
        return 2;
    }

    // print cheese inventory
    printdivider(70, "Cheese Inventory");
    for (auto i = 0u; i < cnt; ++i) {
        std::cout << *cheeses[i];
    }
    printdivider(70);

    // slice some cheeses
    if (cnt != 0) {
        sdds::Cheese c1 = cheeses[0]->slice(100);   // Buffalo Gouda 500 -> 400
        sdds::Cheese c2 = cheeses[3]->slice(500);   // Smoked Moz 2000 -> 1500
        sdds::Cheese c3 = cheeses[8]->slice(10000); // not enough Manchego to slice
        // print sliced cheeses
        printdivider(70, "Sliced Cheeses");
        std::cout << c1 << c2 << c3;
        printdivider(70);
    }

    // cheese after slicing
    printdivider(70, "Cheese Inventory");
    for (auto i = 0u; i < cnt; ++i) {
        std::cout << *cheeses[i];
    }
    printdivider(70);

    // cleanup
    for (auto i = 0u; i < cnt; ++i)
        delete cheeses[i];
    delete[] cheeses;

    return cout;
}*/