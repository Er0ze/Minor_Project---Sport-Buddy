#ifndef GRAPHTRAVERSAL_H
#define GRAPHTRAVERSAL_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

class GraphTraversal {
public:
    GraphTraversal(const std::unordered_map<int, std::vector<int>>& graph);
    
    // DFS and BFS traversal methods
    void DFS(int startNode);
    void BFS(int startNode);

private:
    std::unordered_map<int, std::vector<int>> adjList;
    void DFSUtil(int node, std::unordered_map<int, bool>& visited);
};

#endif // GRAPHTRAVERSAL_H
