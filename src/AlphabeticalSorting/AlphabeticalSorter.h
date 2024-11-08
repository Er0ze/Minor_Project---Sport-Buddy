#ifndef ALPHABETICALSORTER_H
#define ALPHABETICALSORTER_H

#include <vector>
#include <string>
#include "User.h"

class AlphabeticalSorter {
public:
    // Sort a list of users alphabetically based on their usernames
    static void sortByUsername(std::vector<User>& users); // Corrected method name

    // Sort a list of event names alphabetically
    static void sortEventsAlphabetically(std::vector<std::string>& events); // Also make this static if needed
};

#endif // ALPHABETICALSORTER_H
