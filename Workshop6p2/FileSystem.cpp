/*
Full Name : Sakshi Sakshi
Student ID# : 112602222
Email : ssakshi7@myseneca.ca
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include <fstream>
#include <vector>
#include <utility>
#include <memory>
#include "Filesystem.h"
#include "Directory.h"
#include "File.h"
#include "Flags.h"
using namespace std;
namespace sdds
{
    Filesystem::Filesystem()
    {
        m_root = {};
        m_current = {};
    }

    Filesystem::Filesystem(std::string fname, std::string dirName) : Filesystem()
    {
        m_root = new Directory(dirName);
        m_current = m_root;

        std::ifstream fin(fname);

        if (fin.is_open())
        {
            std::string line, filePath, fileContent, dirPath;
            size_t index = std::string::npos;

            do
            {
                std::getline(fin, line);
                if ((index = line.find('|')) != std::string::npos)
                {
                    filePath = line.substr(0, index);
                    line.erase(0, index + 1);                                                           //+1 to include '|' in the erasure
                    fileContent = line.substr(line.find_first_not_of(' '), line.find_last_not_of(' ')); // automatically takes off whitespaces
                    fileContent.erase(fileContent.find_last_not_of(' ') + 1);

                    index = std::string::npos;
                    if ((index = filePath.find_first_not_of(' ')))
                    {
                        filePath = filePath.erase(0, index);
                    }

                    index = std::string::npos;
                    if ((index = filePath.find_last_of(' ')) < filePath.length())
                    {
                        filePath.erase(filePath.find_last_not_of(' ') + 1, index); //+1 to last letter
                    }

                    addResource(filePath, fileContent);
                }
                else
                {
                    dirPath = line.substr(0, line.find_last_of('/') + 1); //+1 to include '/'
                    addResource(dirPath);
                }
            } while (fin);
        }
        else
        {
            throw "File does not Exist";
        }
    }

    void Filesystem::addResource(const std::string& path, const std::string& content)
    {
        Directory* current = m_root;

        std::string remainingPath = path;
        std::size_t found = remainingPath.find("/");

        while (found != std::string::npos)
        {
            std::string dirName = remainingPath.substr(0, found + 1);
            remainingPath = remainingPath.substr(found + 1);

            Directory* newDir = dynamic_cast<Directory*>(current->find(dirName));
            if (!newDir)
            {
                newDir = new Directory(dirName);
                *current += newDir;
            }
            current = newDir;

            found = remainingPath.find("/");
        }

        if (!content.empty() && !current->find(remainingPath))
        {
            *current += new File(remainingPath.c_str(), content.c_str());
        }
    }

    Filesystem& Filesystem::operator+=(Resource* newRes)
    {
        *m_current += newRes;
        return *this;
    }

    Directory* Filesystem::change_directory(const std::string& newDir)
    {
        if (newDir.length())
        {
            std::vector<OpFlags> flag = { OpFlags::RECURSIVE }; // confirmed from w6_p2.cpp

            Resource* findDir = m_root->find(newDir, flag);
            if (findDir && findDir->type() == NodeType::DIR)
            {
                m_current = dynamic_cast<Directory*>(findDir);
            }
            else
            {
                throw std::invalid_argument("Cannot change directory! " + newDir + " not found!");
            }
        }
        else
        {
            m_current = m_root;
        }

        return m_current;
    }

    Directory* Filesystem::get_current_directory() const
    {
        return m_current;
    }

    Filesystem::Filesystem(Filesystem&& f)
    {
        *this = std::move(f);
    }

    Filesystem& Filesystem::operator=(Filesystem&& f)
    {
        if (this != &f)
        {
            delete m_root;
            m_root = f.m_root;
            m_current = m_root;
            delete f.m_root;
            f.m_current = nullptr;
        }
        return *this;
    }

    Filesystem::~Filesystem()
    {
        delete m_root;
        m_current = nullptr;
    }
}