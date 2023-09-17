/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include "RideRequest.h"

using namespace std;
double g_taxrate = 0.0;
double g_discount = 0.0;
namespace sdds
{
	int RideRequest::counter = 0;
	RideRequest::RideRequest()
	{
		rideDetail = nullptr;
		strcpy(customerName, "");
		price = 0.0;
		hasDiscount = false;
	}

	RideRequest::~RideRequest()
	{
		if (rideDetail != nullptr && strlen(rideDetail) != 0)
		{
			delete[] rideDetail;
			rideDetail = nullptr;
		}
	}
	void RideRequest::read(std::istream& in)
	{

		strcpy(customerName, "");
		string line;

		if (getline(in, line, ',')) 
		{
			strcpy(customerName, line.c_str());
		}
		if (rideDetail != nullptr) 
		{
			delete[] rideDetail;
			rideDetail = nullptr;
		}
		if (getline(in, line, ','))
		{
			rideDetail = new char[line.length() + 1];
			strcpy(rideDetail, line.c_str());
		}
		else
		{
			rideDetail = nullptr;
		}

		if (getline(in, line, ',')) 
		{
			price = stod(line);
		}

		if (getline(in, line)) 
		{
			hasDiscount = (line == "Y");
		}


	}
	void RideRequest::display()
	{
		counter++;
		if (customerName[0] == '\0')
		{
			std::cout << std::setw(2) << std::left << counter << ". No Ride Request" << std::endl;
		}
		else
		{
			double taxRate = g_taxrate;
			double priceWithTax = price * (1 + taxRate);

			std::cout << std::setw(2) << std::left << counter << ". ";
			std::cout << std::setw(10) << std::left << customerName;
			std::cout << "|";
			string newDetail(rideDetail);
			if (newDetail.length() <= 25)
			{
				std::cout << std::setw(25) << std::left << rideDetail;
			}
			else
			{
				std::cout << rideDetail;
			}
			std::cout << "|" << std::fixed << std::setprecision(2);
			std::cout << std::setw(12) << std::left << priceWithTax;

			if (hasDiscount)
			{
				double priceWithDiscount = priceWithTax - (g_discount);
				std::cout << std::right << "|" << std::setw(13) << priceWithDiscount;
			}
			else
			{
				std::cout << "|";
			}
		
			std::cout << std::endl;
              }
	}
	RideRequest::RideRequest(const RideRequest& other)
	{
		strcpy(customerName, other.customerName);
		if (other.rideDetail != nullptr) {
			rideDetail = new char[strlen(other.rideDetail) + 1];
			strcpy(rideDetail, other.rideDetail);
		}
		else 
		{
			rideDetail = nullptr;
		}

		price = other.price;
		hasDiscount = other.hasDiscount;
	}
	RideRequest& RideRequest::operator=(const RideRequest& other)
	{
		if (this != &other) 
		{
			delete[] rideDetail;

			strcpy(customerName, other.customerName);

			if (other.rideDetail != nullptr) 
			{
				rideDetail = new char[strlen(other.rideDetail) + 1];
				strcpy(rideDetail, other.rideDetail);
			}
			else 
			{
				rideDetail = nullptr;
			}

			price = other.price;
			hasDiscount = other.hasDiscount;
		}

		return *this;
	}

}
