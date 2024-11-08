#ifndef USER_ACCOUNT_MANAGER_H
#define USER_ACCOUNT_MANAGER_H

#include "User.h"
#include <unordered_map>
#include <vector>

class UserAccountManager {
public:
    void addUser(const User& user);
    bool userExists(const std::string& username) const;
    User getUser(const std::string& username) const;
    std::vector<User> getAllUsers() const;

private:
    std::unordered_map<std::string, User> users; // Keep using unordered_map
};

#endif // USER_ACCOUNT_MANAGER_H
