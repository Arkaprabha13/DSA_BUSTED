//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
   void dfs(vector<int>& visited, unordered_map<int, vector<int>>& adjacency, vector<int>& parent, int node, int& cycleDetected) {
    visited[node] = 1;
    vector<int> neighbors = adjacency[node];

    for (int neighbor : neighbors) {
        if (visited[neighbor] == 0) {
            parent[neighbor] = node;
            dfs(visited, adjacency, parent, neighbor, cycleDetected);
        } else {
            if (neighbor != parent[node]) {
                cycleDetected = 1;
                return;
            }
        }
    }
}

int isTree(int n, int m, vector<vector<int>>& edges) {
    // Check if the number of edges is one less than the number of nodes
    if (n == 1 && m != 0) {
        return 0;
    }

    unordered_map<int, vector<int>> adjacency;
    
    // Build adjacency list from edge list
    for (int i = 0; i < edges.size(); i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }

    vector<int> visited(n + 1, 0);
    vector<int> parent(n + 1, 0);
    visited[0] = 1;
    int cycleDetected = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            return 0;  // Graph is not connected
        }
        if (i == 0) {
            parent[i] = i;
            dfs(visited, adjacency, parent, 0, cycleDetected);
            if (cycleDetected == 1) {
                return 0;  // Cycle detected, not a tree
            }
        }
    }

    return 1;  // // code here
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
