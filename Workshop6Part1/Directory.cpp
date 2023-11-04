/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "Directory.h"

using namespace std;

namespace sdds
{
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

            // If RECURSIVE flag is set and the resource is a directory, recursively search within it.
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
        for (Resource* resource : m_contents) {
            delete resource;
        }
    }
    Directory::operator bool() const
    {
        return !m_name.empty() && !m_parent_path.empty();
    }
    void Directory::remove(const std::string&, const std::vector<OpFlags>&)
    {

    }
    void Directory::display(std::ostream&, const std::vector<FormatFlags>&) const
    {

    }
}