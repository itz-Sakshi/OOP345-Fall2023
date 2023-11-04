/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "File.h"

using namespace std;
namespace sdds
{
    File:: File(const std::string fileName, const std::string fileContent)
    {
        if (strcmp(fileName.c_str(), "") != 0)
        {
            m_name = fileName;
        }
        if (strcmp(fileContent.c_str(), "") != 0)
        {
            m_contents = fileContent;
        }

    }
    void File::update_parent_path(const std::string& parentPath)
    {
        if (strcmp(parentPath.c_str(), "") != 0)
        {
            m_parent_path = parentPath;
        }
    }
    std::string File::name() const
    {
        return m_name;
    }
    int File::count() const
    {
        return -1;
    }
    std::string File::path() const
    {
        return (m_parent_path + m_name);
    }
    size_t File::size() const
    {
        return m_contents.size();
    }
    NodeType File::type() const
    {
        return NodeType::FILE;
    }
    File::operator bool() const
    {
        return !m_name.empty() && !m_parent_path.empty();
    }
}