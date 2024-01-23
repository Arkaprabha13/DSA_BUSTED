//User function Template for C++

class Solution
{
  public:
   vector<int> findOrder(int n, int m, vector<vector<int>>& prerequisites) {
    vector<int> result;  // The final ordering of tasks
    vector<int> inDegree(n, 0);  // Array to store in-degrees of tasks
    vector<vector<int>> adjList(n, vector<int>());  // Adjacency list representation of the graph

    // Build the adjacency list and in-degrees
    for (const auto& preq : prerequisites) {
        int course = preq[0];
        int prerequisite = preq[1];
        adjList[prerequisite].push_back(course);
        inDegree[course]++;
    }

    // Initialize a queue for BFS
    queue<int> q;

    // Add tasks with in-degree 0 to the queue
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Perform BFS
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        // Update in-degrees of neighbors and enqueue if in-degree becomes 0
        for (int neighbor : adjList[current]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Check if all tasks are included in the ordering
    if (result.size() == n) {
        return result;
    } else {
        // If there is a cycle, return an empty array
        return {};
    }
}
};
