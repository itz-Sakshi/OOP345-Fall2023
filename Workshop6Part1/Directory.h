#ifndef SDDS_DIRECTORY_H
#define SDDS_DIRECTORY_H

#include "Resource.h"
#include <string>
#include <vector>

namespace sdds
{
    class Directory : public Resource
    {
        std::vector<Resource*> m_contents;
    public:
        Directory(std::string dName);
        void update_parent_path(const std::string&);
        std::string name() const;
        int count() const;
        std::string path() const;
        size_t size() const;
        NodeType type() const;
        Directory& operator+=(Resource*);
        Resource* find(const std::string&, const std::vector<OpFlags>& flags = {});
        ~Directory();
        operator bool() const;
        //this class should not allow copy/move operations.
        Directory(const Directory&) = delete;
        Directory& operator=(const Directory&) = delete;
        Directory(const Directory&&) = delete;
        Directory& operator=(const Directory&&) = delete;
        void remove(const std::string&, const std::vector<OpFlags>&);
        void display(std::ostream&, const std::vector<FormatFlags>& = {}) const;
    };
}
#endif // SDDS_DIRECTORY_H