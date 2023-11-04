/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "Resource.h"
#include <string>

namespace sdds
{
	class File : public Resource
	{
        std::string m_contents; // string that stores the contents of the file
    public:
        File(std::string fileName, std::string fileContent="");
        void update_parent_path(const std::string&);
        std::string name() const;
        int count() const;
        std::string path() const;
        size_t size() const;
        NodeType type() const;
        operator bool() const;
	};
}
#endif // SDDS_FILE_H