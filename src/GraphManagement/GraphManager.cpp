#include "GraphManager.h"
#include <algorithm>

// Add a connection between two users
void GraphManager::addConnection(const std::string& user1, const std::string& user2) {
    connections[user1].push_back(user2);
    connections[user2].push_back(user1); // If connections are bidirectional
}

// Check if two users are connected
bool GraphManager::isConnected(const std::string& user1, const std::string& user2) const {
    auto it = connections.find(user1);
    if (it != connections.end()) {
        const std::vector<std::string>& userConnections = it->second;
        return std::find(userConnections.begin(), userConnections.end(), user2) != userConnections.end();
    }
    return false; // If user1 has no connections or doesn't exist
}
