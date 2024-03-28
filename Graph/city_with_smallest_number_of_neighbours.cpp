#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// Dijkstra's algorithm to find the number of reachable cities within the distance threshold
int dijkstra(int curr, int n, int distThreshold, const vector<vector<pair<int, int>>>& graph) {
    // Priority queue for Dijkstra's algorithm
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Visited array to track visited nodes
    vector<int> vis(n, 0);
    // Push the current node with distance 0 to the priority queue
    pq.push({0, curr});
    
    // Counter for reachable cities
    int cnt = 0;
    while (!pq.empty()) {
        int dist = pq.top().first; // Current distance
        int node = pq.top().second; // Current node
        pq.pop();
        
        // If the node is already visited, skip it
        if (vis[node]) 
            continue;
        
        // Mark the node as visited
        vis[node] = 1;
        // If the distance exceeds the threshold, skip exploring its neighbors
        if (dist > distThreshold) 
            continue;
        // Increment the counter for reachable cities
        ++cnt;
        
        // Explore neighbors
        for (auto& [nodeDist, nextNode] : graph[node]) {
            if (!vis[nextNode]) 
                pq.push({dist + nodeDist, nextNode}); // Push the neighbor with updated distance to the priority queue
        }
    }
    return cnt; // Return the count of reachable cities
}

// Function to find the city with the minimum number of reachable cities within the distance threshold
int findCity(int n, int m, const vector<vector<int>>& edges, int distThreshold) {
    // Create a graph representation using adjacency list
    vector<vector<pair<int, int>>> graph(n);
    // Populate the graph with edges and distances
    for (const auto& itr : edges) {
        graph[itr[0]].push_back({itr[2], itr[1]});
        graph[itr[1]].push_back({itr[2], itr[0]});
    }
    
    // Variables to track the output city and the minimum number of reachable cities
    int out = -1, nax = INT_MAX;
    // Iterate through each city
    for (int i = 0; i < n; ++i) {
        // Get the count of reachable cities from the current city using Dijkstra's algorithm
        int cnt = dijkstra(i, n, distThreshold, graph);
        // Update the output city and the minimum count of reachable cities if necessary
        if (cnt <= nax) {
            nax = cnt;
            out = i;
        }
    }
    return out; // Return the output city
}
