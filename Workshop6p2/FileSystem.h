/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_FILESYSTEM_H
#define SDDS_FILESYSTEM_H

#include <string>
#include "Resource.h"
#include "Directory.h"



namespace sdds
{
	class Filesystem
	{
		Directory* m_root;
		Directory* m_current;
		void addResource(const std::string& path, const std::string& content = "");
	public:
		Filesystem();
		Filesystem(std::string fileName, std::string rootName = "");
		//this class should not allow copy operations.
		Filesystem(const Filesystem&) = delete;
		Filesystem& operator=(const Filesystem&) = delete;
		Filesystem(Filesystem&&);
		Filesystem& operator=(Filesystem&&);
		Filesystem& operator+=(Resource*);
		Directory* change_directory(const std::string & = "");
		Directory* get_current_directory() const;
		~Filesystem();
	};
}
#endif // SDDS_FILESYSTEM_H