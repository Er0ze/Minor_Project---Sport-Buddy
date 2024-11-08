#ifndef GRAPH_MANAGER_H
#define GRAPH_MANAGER_H

#include <string>
#include <unordered_map>
#include <vector>

class GraphManager {
public:
    // Add a connection between two users
    void addConnection(const std::string& user1, const std::string& user2);
    
    // Check if two users are connected
    bool isConnected(const std::string& user1, const std::string& user2) const;

private:
    // Adjacency list to store connections
    std::unordered_map<std::string, std::vector<std::string>> connections; 
};

#endif // GRAPH_MANAGER_H
