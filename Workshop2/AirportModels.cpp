<<<<<<< HEAD
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
#include <sstream>
#include "AirportModels.h"

using namespace std;

namespace sdds {
    Airport::Airport() {
        m_code = "";
        m_name = "";
        m_city = "";
        m_state = "";
        m_country = "";
        m_latitude = 0.0;
        m_longitude = 0.0;
    }

    Airport::Airport(const std::string& code, const std::string& name, const std::string& city,
        const std::string& state, const std::string& country, double latitude, double longitude)
        : m_code(code), m_name(name), m_city(city), m_state(state), m_country(country),
        m_latitude(latitude), m_longitude(longitude) {
    }

    Airport::Airport(const Airport& other) {
        m_code = other.m_code;
        m_name = other.m_name;
        m_city = other.m_city;
        m_state = other.m_state;
        m_country = other.m_country;
        m_latitude = other.m_latitude;
        m_longitude = other.m_longitude;
    }


    Airport& Airport::operator=(const Airport& other) {
        if (this != &other) {
            m_code = other.m_code;
            m_name = other.m_name;
            m_city = other.m_city;
            m_state = other.m_state;
            m_country = other.m_country;
            m_latitude = other.m_latitude;
            m_longitude = other.m_longitude;
        }
        return *this;
    }

    

    std::ostream& operator<<(std::ostream& os, const Airport& airport) {
        if (airport.m_code == "") {
            os << "Empty Airport";
        }
        else {
            os << std::right << std::setw(23) << setfill('.') << "Airport Code : " << std::left << std::setw(30) << setfill('.') << airport.m_code << std::endl
                << std::right << std::setw(23) << setfill('.') << "Airport Name : " << std::left << std::setw(30) << setfill('.') << airport.m_name << std::endl
                << std::right << std::setw(23) << setfill('.') << "City : " << std::left << std::setw(30) << setfill('.') << airport.m_city << std::endl
                << std::right << std::setw(23) << setfill('.') << "State : " << std::left << std::setw(30) << setfill('.') << airport.m_state << std::endl
                << std::right << std::setw(23) << setfill('.') << "Country : " << std::left << std::setw(30) << setfill('.') << airport.m_country << std::endl
                << setiosflags(ios::right) << setw(20) << setfill('.') << "Latitude" << " : " << resetiosflags(ios::right)
                << setiosflags(ios::left) << setw(30) << setfill('.') << airport.m_latitude << resetiosflags(ios::left) << endl
                << setiosflags(ios::right) << setw(20) << setfill('.') << "Longitude" << " : " << resetiosflags(ios::right)
                << setiosflags(ios::left) << setw(30) << setfill('.') << airport.m_longitude << resetiosflags(ios::left) << endl;
        }
        return os;
    }

    AirportLog::AirportLog() : m_airports(nullptr), m_count(0) {}

    AirportLog::AirportLog(const char* filename) : m_airports(nullptr), m_count(0) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }
        std::string line;
        getline(file, line); // Read and discard the header line
        while (getline(file, line)) {
            m_count++;
        }

        m_airports = new Airport[m_count];
        file.close();
        std::ifstream file1(filename);
        if (!file1.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }
        getline(file1, line); // Read and discard the header line
        for (size_t i = 0; i < m_count; i++) {
            getline(file1, line);
            std::istringstream iss(line);
            AirportLog airports;
            Airport airport;

            std::getline(iss, airport.m_code, ',');
            std::getline(iss, airport.m_name, ',');
            std::getline(iss, airport.m_city, ',');
            std::getline(iss, airport.m_state, ',');
            std::getline(iss, airport.m_country, ',');
            iss >> airport.m_latitude;
            iss.ignore(); // Ignore the comma
            iss >> airport.m_longitude;
            m_airports[i] = airport;;
        }
        
        

        file1.close();
    }

    AirportLog::~AirportLog() {
        delete[] m_airports;
    }

    AirportLog::AirportLog(const AirportLog& other) : m_count(other.m_count) {
        m_airports = new Airport[m_count];
        for (size_t i = 0; i < m_count; ++i) {
            m_airports[i] = other.m_airports[i];
        }
    }

    AirportLog& AirportLog::operator=(const AirportLog& other) {
        if (this != &other) {
            delete[] m_airports;
            m_count = other.m_count;
            m_airports = new Airport[m_count];
            for (size_t i = 0; i < m_count; ++i) {
                m_airports[i] = other.m_airports[i];
            }
        }
        return *this;
    }

    AirportLog::AirportLog(AirportLog&& other) noexcept : m_airports(other.m_airports), m_count(other.m_count) {
        other.m_airports = nullptr;
        other.m_count = 0;
    }

    AirportLog& AirportLog::operator=(AirportLog&& other) noexcept {
        if (this != &other) {
            delete[] m_airports;
            m_airports = other.m_airports;
            m_count = other.m_count;
            other.m_airports = nullptr;
            other.m_count = 0;
        }
        return *this;
    }

    void AirportLog::addAirport(const Airport& airport) {
        if (airport.m_code != "")
        {
            Airport* temp = new Airport[m_count + 1];
            for (size_t i = 0; i < m_count; i++) {
                temp[i] = m_airports[i];
            }
            temp[m_count] = airport;
            m_count++;
            delete[] m_airports;
            m_airports = temp;
        }
    }

    AirportLog AirportLog::findAirport(const char* state, const char* country) const {
        AirportLog result;
        for (size_t i = 0; i < m_count; ++i) {
            if (std::strcmp(m_airports[i].m_state.c_str(), state) == 0 && std::strcmp(m_airports[i].m_country.c_str(), country) == 0) {
                result.addAirport(m_airports[i]);
            }
        }
        return result;
    }

    Airport AirportLog::operator[](size_t index) const {
        if (index < m_count) {
            return m_airports[index];
        }
        else {
            return Airport();
        }
    }

    AirportLog::operator size_t() const {
        return m_count;
    }

 
        
=======
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
#include <sstream>
#include "AirportModels.h"

using namespace std;

namespace sdds {
    Airport::Airport() {
        m_code = "";
        m_name = "";
        m_city = "";
        m_state = "";
        m_country = "";
        m_latitude = 0.0;
        m_longitude = 0.0;
    }

    Airport::Airport(const std::string& code, const std::string& name, const std::string& city,
        const std::string& state, const std::string& country, double latitude, double longitude)
        : m_code(code), m_name(name), m_city(city), m_state(state), m_country(country),
        m_latitude(latitude), m_longitude(longitude) {
    }

    Airport::Airport(const Airport& other) {
        m_code = other.m_code;
        m_name = other.m_name;
        m_city = other.m_city;
        m_state = other.m_state;
        m_country = other.m_country;
        m_latitude = other.m_latitude;
        m_longitude = other.m_longitude;
    }


    Airport& Airport::operator=(const Airport& other) {
        if (this != &other) {
            m_code = other.m_code;
            m_name = other.m_name;
            m_city = other.m_city;
            m_state = other.m_state;
            m_country = other.m_country;
            m_latitude = other.m_latitude;
            m_longitude = other.m_longitude;
        }
        return *this;
    }

    

    std::ostream& operator<<(std::ostream& os, const Airport& airport) {
        if (airport.m_code == "") {
            os << "Empty Airport";
        }
        else {
            os << std::right << std::setw(23) << setfill('.') << "Airport Code : " << std::left << std::setw(30) << setfill('.') << airport.m_code << std::endl
                << std::right << std::setw(23) << setfill('.') << "Airport Name : " << std::left << std::setw(30) << setfill('.') << airport.m_name << std::endl
                << std::right << std::setw(23) << setfill('.') << "City : " << std::left << std::setw(30) << setfill('.') << airport.m_city << std::endl
                << std::right << std::setw(23) << setfill('.') << "State : " << std::left << std::setw(30) << setfill('.') << airport.m_state << std::endl
                << std::right << std::setw(23) << setfill('.') << "Country : " << std::left << std::setw(30) << setfill('.') << airport.m_country << std::endl
                << setiosflags(ios::right) << setw(20) << setfill('.') << "Latitude" << " : " << resetiosflags(ios::right)
                << setiosflags(ios::left) << setw(30) << setfill('.') << airport.m_latitude << resetiosflags(ios::left) << endl
                << setiosflags(ios::right) << setw(20) << setfill('.') << "Longitude" << " : " << resetiosflags(ios::right)
                << setiosflags(ios::left) << setw(30) << setfill('.') << airport.m_longitude << resetiosflags(ios::left) << endl;
        }
        return os;
    }

    AirportLog::AirportLog() : m_airports(nullptr), m_count(0) {}

    AirportLog::AirportLog(const char* filename) : m_airports(nullptr), m_count(0) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }
        std::string line;
        getline(file, line); // Read and discard the header line
        while (getline(file, line)) {
            m_count++;
        }

        m_airports = new Airport[m_count];
        file.close();
        std::ifstream file1(filename);
        if (!file1.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }
        getline(file1, line); // Read and discard the header line
        for (size_t i = 0; i < m_count; i++) {
            getline(file1, line);
            std::istringstream iss(line);
            AirportLog airports;
            Airport airport;

            std::getline(iss, airport.m_code, ',');
            std::getline(iss, airport.m_name, ',');
            std::getline(iss, airport.m_city, ',');
            std::getline(iss, airport.m_state, ',');
            std::getline(iss, airport.m_country, ',');
            iss >> airport.m_latitude;
            iss.ignore(); // Ignore the comma
            iss >> airport.m_longitude;
            m_airports[i] = airport;;
        }
        
        

        file1.close();
    }

    AirportLog::~AirportLog() {
        delete[] m_airports;
    }

    AirportLog::AirportLog(const AirportLog& other) : m_count(other.m_count) {
        m_airports = new Airport[m_count];
        for (size_t i = 0; i < m_count; ++i) {
            m_airports[i] = other.m_airports[i];
        }
    }

    AirportLog& AirportLog::operator=(const AirportLog& other) {
        if (this != &other) {
            delete[] m_airports;
            m_count = other.m_count;
            m_airports = new Airport[m_count];
            for (size_t i = 0; i < m_count; ++i) {
                m_airports[i] = other.m_airports[i];
            }
        }
        return *this;
    }

    AirportLog::AirportLog(AirportLog&& other) noexcept : m_airports(other.m_airports), m_count(other.m_count) {
        other.m_airports = nullptr;
        other.m_count = 0;
    }

    AirportLog& AirportLog::operator=(AirportLog&& other) noexcept {
        if (this != &other) {
            delete[] m_airports;
            m_airports = other.m_airports;
            m_count = other.m_count;
            other.m_airports = nullptr;
            other.m_count = 0;
        }
        return *this;
    }

    void AirportLog::addAirport(const Airport& airport) {
        if (airport.m_code != "")
        {
            Airport* temp = new Airport[m_count + 1];
            for (size_t i = 0; i < m_count; i++) {
                temp[i] = m_airports[i];
            }
            temp[m_count] = airport;
            m_count++;
            delete[] m_airports;
            m_airports = temp;
        }
    }

    AirportLog AirportLog::findAirport(const char* state, const char* country) const {
        AirportLog result;
        for (size_t i = 0; i < m_count; ++i) {
            if (std::strcmp(m_airports[i].m_state.c_str(), state) == 0 && std::strcmp(m_airports[i].m_country.c_str(), country) == 0) {
                result.addAirport(m_airports[i]);
            }
        }
        return result;
    }

    Airport AirportLog::operator[](size_t index) const {
        if (index < m_count) {
            return m_airports[index];
        }
        else {
            return Airport();
        }
    }

    AirportLog::operator size_t() const {
        return m_count;
    }

 
        
>>>>>>> origin/main
}