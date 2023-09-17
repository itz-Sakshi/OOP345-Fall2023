/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/

// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Hina Tariq - 2023/03/06
// Cornel - 2023/09/08

#include <iostream>
#include <iomanip>
#include <fstream>
#include "RideRequest.h"

// Cheching if header guards exist and follow convention.
#ifndef SDDS_RIDEREQUEST_H
#error "The header guard for 'RideRequest.h' doesn't follow the convention!"
#endif

int cout = 0; // won't compile if headers don't follow convention regarding namespaces


/* input file format: a comma separated set of fields with a consistent format of
<Ride Order Tag>,<Customer Name>,<Ride Description>,<Rate>,<Discount Status>

<Ride Order Tag> can be one of:
	O - Ride to Office
	H - Ride to Home

<Discount Status> can be one of:
	Y - Discount Applied
	N - No Discount
*/

// TODO: write the prototype for the main function
//         to accept command line arguments
int main (int argc, char* argv[])
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	// TODO: print the command line here, in the format
	//   1: first argument
	//   2: second argument
	//   3: third argument
	//   ...
	// Don't use "magic numbers": https://en.wikipedia.org/wiki/Magic_number_(programming)
	for (int i = 0; i < argc; i++) 
	{
		std::cout << std::setw(2) << " " << i + 1 << ": " << argv[i] << std::endl;
	}
		std::cout <<  "--------------------------\n\n";

	// Keep a record of the *Home* rides separately
	sdds::RideRequest recordedRequests[10];
	// Keep a count of how many rides recorded
	size_t numRides = 0;

	sdds::RideRequest currentRide;

	for (auto day = 1; day < argc; ++day)
	{
		// Rates change from day 1 to day 2
		if (day == 1) {
			g_taxrate = 0.13;
			g_discount = 1.15;
		}
		else {
			g_taxrate = 0.14;
			g_discount = 1.20;
		}

		// each parameter contains the rides from one day, process each one at a time
		std::cout << "--------------------\n";
		std::cout << "    Day " << day << '\n';
		std::cout << "--------------------\n";
		std::ifstream in(argv[day]);
		if (in.is_open() == false)
		{
			std::cout << "Cannot open file [" << argv[day] << "]. Ignoring it!\n";
			continue; // go to the next iteration of the loop
		}
		std::cout << "Name          |Ride Description         |Price w/ Tax|Price with Discount" << std::endl;
		char ridetag = '\0';

		// loop through each order in the file
		while (in) {

			// read in the ridetag
			in >> ridetag;
			// skip the delimiter
			in.ignore();

			// end of the file
			if (in.fail())
				break;

			// read in the rest of the data as a RideRequest
			currentRide.read(in);
			currentRide = currentRide;

			// Handle the office and home rides differently
			if (ridetag == 'O') {
				sdds::RideRequest copy = currentRide;
				copy.display();
			}
			else if (ridetag == 'H') { // adds the home rides to the record
				recordedRequests[numRides++] = currentRide;
				currentRide.display();
			}
		}
	}

	// print the recorded rides
	std::cout << "--------------------\n";
	std::cout << "Recorded Home Ride Orders\n";
	std::cout << "--------------------\n";
	std::cout << "Name          |Ride Description         |Price w/ Tax|Price with Discount" << std::endl;
	for (auto i = 0u; i < numRides; ++i)
		recordedRequests[i].display();
	std::cout << "--------------------\n";

	return cout;
}
