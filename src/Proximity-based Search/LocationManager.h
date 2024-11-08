#ifndef LOCATION_MANAGER_H
#define LOCATION_MANAGER_H

#include "User.h"
#include <vector>

class LocationManager {
public:
    void addUserLocation(const User& user);
    std::vector<User> findUsersNearby(const User& user, double maxDistance) const;

    // New method to get all users
    std::vector<User> getAllUsers() const;

    // Static method to calculate distance between two coordinates
    static double calculateDistance(double lat1, double lon1, double lat2, double lon2);

private:
    std::vector<User> users;
};

#endif // LOCATION_MANAGER_H
