/*
Full Name : Sakshi Sakshi
Student ID#  : 112602222
Email : ssakshi7@myseneca.ca
Date : 12 - 07 - 2023
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* **********************************************************************/
#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>


namespace sdds {

    struct Airport {
        std::string m_code;
        std::string m_name;
        std::string m_city;
        std::string m_state;
        std::string m_country;
        double m_latitude;
        double m_longitude;
        Airport(); 
        Airport(const std::string& code, const std::string& name, const std::string& city,
            const std::string& state, const std::string& country, double latitude, double longitude);
        Airport(const Airport& other);
        Airport& operator=(const Airport& other);

       
    };

    std::ostream& operator<<(std::ostream& os, const Airport& airport);
    

    class AirportLog {
        Airport* m_airports;
        size_t m_count;

    public:
        AirportLog();
        AirportLog(const char* filename); 
        // Rule of 5 
        ~AirportLog();
        AirportLog(const AirportLog& other); // Copy constructor
        AirportLog& operator=(const AirportLog& other); // Copy assignment
        AirportLog(AirportLog&& other) noexcept; // Move constructor
        AirportLog& operator=(AirportLog&& other) noexcept; // Move assignment

        void addAirport(const Airport& airport);
        AirportLog findAirport(const char* state, const char* country) const; // Find airports by state and country
        Airport operator[](size_t index) const; // Index operator
        operator size_t() const; // Casting operator
    };

    

}

#endif // SDDS_AIRPORT_MODELS_H
