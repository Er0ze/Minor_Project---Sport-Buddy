// ConnectionManager.h
#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <vector>

class ConnectionManager {
public:
    ConnectionManager(int n); // Constructor to initialize n users

    void unionUsers(int u, int v); // Connect two users (union operation)
    int findUser(int u);           // Find the root of a user (find operation)
    bool areConnected(int u, int v); // Check if two users are connected

private:
    std::vector<int> parent; // Stores the parent of each user
    std::vector<int> rank;   // Optimizes union by rank
};

#endif // CONNECTIONMANAGER_H
