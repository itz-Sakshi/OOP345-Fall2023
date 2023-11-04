/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "Cheese.h"

using namespace std;
namespace sdds
{
    Cheese::Cheese()
    {
        m_name = "NaC";
        m_weightInGrams = 0;
        m_pricePerGram = 0.0;
        m_features = "";
    }

    Cheese::Cheese(const std::string& str)
    {

        std::istringstream ss(str);
        std::string token;

        if (std::getline(ss, token, ',')) 
        {
            m_name = trim(token);
        }

        if (std::getline(ss, token, ',')) 
        {
            m_weightInGrams = std::stoul(trim(token));
        }

        if (std::getline(ss, token, ',')) 
        {
            m_pricePerGram = std::stod(trim(token));
        }

        while (std::getline(ss, token, ','))
        {
            m_features += trim(token);
            if (!ss.eof()) {
                m_features += " ";
            }
        }
    }
    // Helper function
    std::string trim(const std::string & str)
    {
        size_t start = str.find_first_not_of(" \t\r\n");
        if (start == std::string::npos) 
        {
            return "";
        }
        size_t end = str.find_last_not_of(" \t\r\n");
        if (end == std::string::npos) {
            end = str.size() - 1;
        }
        return str.substr(start, end - start + 1);
    }

    Cheese::Cheese(const Cheese& otherCheese) {
        m_name = otherCheese.m_name;
        m_weightInGrams = otherCheese.m_weightInGrams;
        m_pricePerGram = otherCheese.m_pricePerGram;
        m_features = otherCheese.m_features;
    }

    Cheese& Cheese::operator=(const Cheese& otherCheese) {
        if (this == &otherCheese) {
            return *this; 
        }

        m_name = otherCheese.m_name;
        m_weightInGrams = otherCheese.m_weightInGrams;
        m_pricePerGram = otherCheese.m_pricePerGram;
        m_features = otherCheese.m_features;

        return *this;
    }


    Cheese Cheese::slice(size_t weight)
    {
        if (int(weight) <= m_weightInGrams)
        {
            Cheese slicedCheese(*this);
            slicedCheese.m_weightInGrams = weight;

            // Updating the current object's weight after slicing
            this->m_weightInGrams -= weight;
            return slicedCheese;
        }
        else
        {
            return Cheese();
        }
    }

    std::string Cheese::getName() const
    {
        return m_name;
    }
    int Cheese::getWeight() const
    {
        return m_weightInGrams;
    }
    double Cheese::getPrice() const
    {
        return m_pricePerGram;
    }
    std::string Cheese::getFeatures() const
    {
        return m_features;
    }

    std::ostream& operator<<(std::ostream& os, const Cheese& cheese)
    {
        os << "|" << std::left << std::setw(21) << cheese.getName() << "|"
            << std::setw(5) << cheese.getWeight() << "|"
            << std::fixed << std::setprecision(2) << std::setw(5) << cheese.getPrice() << "|"
            << std::right << std::setw(33) << cheese.getFeatures() << " |" << std::endl;

        return os;
    }

    Cheese::~Cheese()
    {
    }
}