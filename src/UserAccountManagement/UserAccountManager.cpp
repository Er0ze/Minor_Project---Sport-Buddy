#include "UserAccountManager.h"
#include "User.h"
#include <stdexcept> // For std::runtime_error

void UserAccountManager::addUser(const User& user) {
    users[user.getUsername()] = user; // Use the username as the key
}

bool UserAccountManager::userExists(const std::string& username) const {
    return users.find(username) != users.end(); // Check if user exists using find
}

User UserAccountManager::getUser(const std::string& username) const {
    auto it = users.find(username); // Use unordered_map's find
    if (it != users.end()) {
        return it->second; // Return the user object
    }
    throw std::runtime_error("User not found");
}

std::vector<User> UserAccountManager::getAllUsers() const {
    std::vector<User> allUsers;
    for (const auto& pair : users) {
        allUsers.push_back(pair.second); // Push back the User objects
    }
    return allUsers;
}
