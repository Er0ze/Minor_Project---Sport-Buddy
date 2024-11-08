 #include "GraphTraversal.h"
#include <iostream>

// Constructor to initialize the adjacency list
GraphTraversal::GraphTraversal(const std::unordered_map<int, std::vector<int>>& graph) {
    adjList = graph;
}

// Utility function for DFS traversal
void GraphTraversal::DFSUtil(int node, std::unordered_map<int, bool>& visited) {
    visited[node] = true;
    std::cout << node << " ";

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, visited);
        }
    }
}

// DFS traversal starting from a given node
void GraphTraversal::DFS(int startNode) {
    std::unordered_map<int, bool> visited;
    DFSUtil(startNode, visited);
    std::cout << std::endl;
}

// BFS traversal starting from a given node
void GraphTraversal::BFS(int startNode) {
    std::unordered_map<int, bool> visited;
    std::queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        std::cout << currentNode << " ";

        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    std::cout << std::endl;
}
