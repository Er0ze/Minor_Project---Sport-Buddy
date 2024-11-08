// ConnectionManager.cpp
#include "ConnectionManager.h"

// Constructor: Initialize each user as its own parent (self-loop)
ConnectionManager::ConnectionManager(int n) {
    parent.resize(n);
    rank.resize(n, 0); // Initialize ranks to 0

    for (int i = 0; i < n; ++i) {
        parent[i] = i; // Every user is their own parent initially
    }
}

// Find operation with path compression
int ConnectionManager::findUser(int u) {
    if (parent[u] != u) {
        parent[u] = findUser(parent[u]); // Path compression
    }
    return parent[u];
}

// Union operation with rank optimization
void ConnectionManager::unionUsers(int u, int v) {
    int rootU = findUser(u);
    int rootV = findUser(v);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Check if two users are in the same connected component
bool ConnectionManager::areConnected(int u, int v) {
    return findUser(u) == findUser(v);
}
