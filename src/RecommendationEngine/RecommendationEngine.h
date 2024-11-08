#ifndef RECOMMENDATIONENGINE_H
#define RECOMMENDATIONENGINE_H

#include <vector>
#include <string>
#include "User.h"
#include "GraphManager.h"
#include "LocationManager.h"

class RecommendationEngine {
public:
    // Get recommended users based on proximity and connections
    std::vector<User> getRecommendations(const User& currentUser, double range);

private:
    // Helper to filter users based on proximity
    std::vector<User> filterByProximity(const User& currentUser, double range);

    // Helper to sort users alphabetically
    void sortUsersAlphabetically(std::vector<User>& users);

    // Helper to check if two users are connected
    bool areConnected(const User& u1, const User& u2);
};

#endif // RECOMMENDATIONENGINE_H
