/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include <iomanip>
#include <algorithm>
#include "Directory.h"


using namespace std;

namespace sdds
{
    Directory::Directory()
    {
        m_name = {};
        m_contents = {};
    }
    
    Directory::Directory(std::string dName)
    {
      
        m_name = dName;
    }
    void Directory::update_parent_path(const std::string& Ppath)
    {
        m_parent_path = Ppath;
        for (Resource* res : m_contents)
        {
            if (res)
            {
                res->update_parent_path(path());
            }
        }
    }
    std::string Directory::name() const
    {
        return m_name;
    }
    int Directory::count() const
    {
        return static_cast<int>(m_contents.size());
    }
    std::string Directory::path() const
    {
        return m_parent_path + m_name;
    }
    size_t Directory::size() const
    {
        size_t size = 0;
        for (Resource* res : m_contents)
        {
            if (res)
            {
                size += res->size();
            }
        }
        return size;
    }
    NodeType Directory::type() const
    {
        return NodeType::DIR;
    }
    Directory& Directory::operator+=(Resource* resource)
    {
        if (resource)
        {
            for (Resource* res : m_contents)
            {
                if (res && res->name() == resource->name())
                {
                    throw std::runtime_error("Resource with the same name already exists in the directory.");
                }
            }
            m_contents.push_back(resource);
            resource->update_parent_path(path());
        }
        return *this;
    }
    Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flags)
    {
        for (Resource* resource : m_contents) {
            if (resource && resource->name() == name) {
                return resource;
            }
            if (std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) != flags.end() && resource && resource->type() == NodeType::DIR) {
                Resource* foundResource = dynamic_cast<Directory*>(resource)->find(name, flags);
                if (foundResource) {
                    return foundResource;
                }
            }
        }
        return nullptr;
    }
    Directory::~Directory()
    {
        for (auto resource : m_contents) {
            delete resource;
        }
    }
    Directory::operator bool() const
    {
        return !m_name.empty() && !m_parent_path.empty();
    }
    void Directory::remove(const std::string& name, const std::vector<OpFlags>& flags)
    {
        bool isRecursive = false;

        for (const OpFlags& f : flags)
        {
            if (f == OpFlags::RECURSIVE)
                isRecursive = true;
        }

        Resource* foundDir = find(name, flags);
        if (foundDir)
        {
            size_t resultIndex{}, counter = 0;
            for (auto element : m_contents)
            {
                if (element == foundDir)
                    resultIndex = counter;
                counter++;
            }

            if (foundDir->type() == NodeType::FILE)
            {
                delete foundDir;
                m_contents.erase(m_contents.begin() + resultIndex);
            }
            else if (foundDir->type() == NodeType::DIR)
            {
                if (isRecursive)
                {
                    delete foundDir;
                    m_contents.erase(m_contents.begin() + resultIndex);
                }
                else
                {
                    throw std::invalid_argument(name + " is a directory. Pass the recursive flag to delete directories.");
                }
            }
        }
        else
        {
            throw name + " does not exist in " + m_parent_path;
        }
    }
    void Directory::display(std::ostream& os, const std::vector<FormatFlags>& flags) const
    {
        bool hasLongFlag = false;
        for (const FormatFlags& f : flags)
        {
            if (f == FormatFlags::LONG)
                hasLongFlag = true;
        }

        os << "Total size: " << std::setw(2) << size() << " bytes" << std::endl;

        for (auto element : m_contents)
        {
            if (element->type() == NodeType::FILE)
            {
                os << "F";
            }
            else if (element->type() == NodeType::DIR)
            {
                os << "D";
            }

            os << " | " << std::setw(15) << std::left << element->name() << std::left << " |";

            if (hasLongFlag)
            {
                if (element->type() == NodeType::FILE)
                {
                    os << "  " << std::setw(2) << ""
                        << "|" << std::setw(5) << std::right << element->size() << std::right << " bytes | " << std::endl;
                }
                else if (element->type() == NodeType::DIR)
                {
                    os << "  " << std::setw(2) << element->count() << "|" << std::setw(5) << std::right << element->size() << std::right << " bytes | " << std::endl;
                }
            }
            else
                os << std::endl;
        }
    }
}