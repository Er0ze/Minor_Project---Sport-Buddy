#include "RecommendationEngine.h"
#include <algorithm> // for std::sort

// Get recommended users based on proximity and connections
std::vector<User> RecommendationEngine::getRecommendations(const User& currentUser, double range) {
    // Filter users within the specified range
    std::vector<User> nearbyUsers = filterByProximity(currentUser, range);

    // Sort users alphabetically for a clean display
    sortUsersAlphabetically(nearbyUsers);

    // Return the final sorted list of recommendations
    return nearbyUsers;
}

// Helper function to filter users based on proximity
std::vector<User> RecommendationEngine::filterByProximity(const User& currentUser, double range) {
    LocationManager locationManager;  // Use the proximity logic
    std::vector<User> allUsers = locationManager.getAllUsers();
    std::vector<User> nearbyUsers;

    for (const User& user : allUsers) {
        // Use getLocation() to access latitude and longitude
        double distance = locationManager.calculateDistance(currentUser.getLocation().getLatitude(), currentUser.getLocation().getLongitude(),
                                                    user.getLocation().getLatitude(), user.getLocation().getLongitude());
        if (user.getUsername() != currentUser.getUsername() && distance <= range) {
            nearbyUsers.push_back(user);
        }
    }
    return nearbyUsers;
}

// Helper function to sort users alphabetically
void RecommendationEngine::sortUsersAlphabetically(std::vector<User>& users) {
    std::sort(users.begin(), users.end(), [](const User& a, const User& b) {
        return a.getUsername() < b.getUsername();
    });
}

// Helper function to check if two users are connected
bool RecommendationEngine::areConnected(const User& u1, const User& u2) {
    GraphManager graphManager;  // Use the graph logic
    return graphManager.isConnected(u1.getUsername(), u2.getUsername());
}
