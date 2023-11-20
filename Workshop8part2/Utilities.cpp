// Name: Sakshi Sakshi
// Seneca Student ID: 112602222
// Seneca email: ssakshi7@myseneca.ca
// Date of completion: 19 November, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include <memory>
#include <utility>
#include "DataBase.h"
#include "Profile.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	DataBase<Profile> excludeRaw(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles) {
		DataBase<Profile> result;
        bool isBanned = false;
		// TODO: Add your code here to build a collection of Profiles.
		//         The result should contain only profiles from `allProfiles`
		//         which are not in `bannedProfiles` using Raw Pointers.
        for (size_t i = 0; i < allProfiles.size(); ++i) {
            // Check if the profile is banned
            isBanned = false;
            for (size_t j = 0; j < bannedProfiles.size() && !isBanned; ++j) 
            {
                isBanned = (allProfiles[i].m_name.first_name == bannedProfiles[j].m_name.first_name &&
                    allProfiles[i].m_name.last_name == bannedProfiles[j].m_name.last_name &&
                    allProfiles[i].m_age == bannedProfiles[j].m_age);
            }

            // If not banned, allocate dynamic memory, validate, and add to result
            if (!isBanned) {
                Profile* newProfile = new Profile(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age);
                try {

                    newProfile->validateAddress();
                }
                catch (...)
                {
                    delete newProfile;
                    throw;
                }
                result += newProfile;
                delete newProfile;
            }
        }
		return result;
	}
    DataBase<Profile> excludeSmart(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles)
    {
        DataBase<Profile> result;
        bool isBanned = false;
        // TODO: Add your code here to build a collection of Profiles.
        //         The result should contain only profiles from `allProfiles`
        //         which are not in `bannedProfiles` using Raw Pointers.
        for (size_t i = 0; i < allProfiles.size(); ++i) {
            // Check if the profile is banned
            isBanned = false;
            for (size_t j = 0; j < bannedProfiles.size() && !isBanned; ++j)
            {
                isBanned = (allProfiles[i].m_name.first_name == bannedProfiles[j].m_name.first_name &&
                    allProfiles[i].m_name.last_name == bannedProfiles[j].m_name.last_name &&
                    allProfiles[i].m_age == bannedProfiles[j].m_age);
            }

            // If not banned, allocate dynamic memory, validate, and add to result
            if (!isBanned) {
                shared_ptr<Profile> newProfile(new Profile(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age));
                newProfile->validateAddress();
                result += newProfile;
            }
        }
        return result;
    }
}