#include "AlphabeticalSorter.h"
#include <algorithm>

// Sort users by their usernames
void AlphabeticalSorter::sortByUsername(std::vector<User>& users) {
    std::sort(users.begin(), users.end(), [](const User& a, const User& b) {
        return a.getUsername() < b.getUsername();
    });
}

// Sort event names alphabetically
void AlphabeticalSorter::sortEventsAlphabetically(std::vector<std::string>& events) {
    std::sort(events.begin(), events.end());
}
