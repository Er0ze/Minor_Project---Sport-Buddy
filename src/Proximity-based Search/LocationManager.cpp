#include "LocationManager.h"
#include <cmath> // for std::sin, std::cos, std::atan2, std::sqrt

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Static method to calculate the distance between two points
double LocationManager::calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const double EARTH_RADIUS = 6371.0; // Radius of the Earth in kilometers

    // Convert degrees to radians
    lat1 = lat1 * M_PI / 180.0;
    lon1 = lon1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;
    lon2 = lon2 * M_PI / 180.0;

    // Haversine formula
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    
    double a = std::sin(dLat / 2) * std::sin(dLat / 2) +
               std::cos(lat1) * std::cos(lat2) *
               std::sin(dLon / 2) * std::sin(dLon / 2);
    
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    
    return EARTH_RADIUS * c; // Distance in kilometers
}

// Add a user's location to the manager
void LocationManager::addUserLocation(const User& user) {
    users.push_back(user);
}

// Find users nearby within a maximum distance
std::vector<User> LocationManager::findUsersNearby(const User& user, double maxDistance) const {
    std::vector<User> nearbyUsers;

    for (const auto& otherUser : users) {
        if (user.getUsername() != otherUser.getUsername()) { // Avoid comparing the user to themselves
            double distance = calculateDistance(user.getLocation().getLatitude(), user.getLocation().getLongitude(), 
                                                otherUser.getLocation().getLatitude(), otherUser.getLocation().getLongitude());
            if (distance <= maxDistance) {
                nearbyUsers.push_back(otherUser);
            }
        }
    }

    return nearbyUsers;
}

// New method to get all users
std::vector<User> LocationManager::getAllUsers() const {
    return users; // Return a copy of the user list
}
