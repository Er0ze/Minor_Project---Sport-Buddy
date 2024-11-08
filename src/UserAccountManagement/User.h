// User.h
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Location.h" // Include the Location class

class User {
public:
    // Updated constructor to include an id parameter
    User(int id, const std::string& username, const std::string& name, const std::string& email, double latitude, double longitude)
        : id(id), username(username), name(name), email(email), location(latitude, longitude) {}

    // Getter for user ID
    int getId() const { return id; }

    std::string getUsername() const { return username; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    Location getLocation() const { return location; } // Return the location object

    void addInterest(const std::string& interest) { interests.push_back(interest); }
    const std::vector<std::string>& getInterests() const { return interests; }

private:
    int id; // Unique identifier for the user
    std::string username;
    std::string name;
    std::string email;
    Location location; // Use the Location class instead of separate latitude and longitude
    std::vector<std::string> interests; // User interests
};

#endif // USER_H
