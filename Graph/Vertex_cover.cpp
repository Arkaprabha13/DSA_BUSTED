//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
int vertexCover(int n, vector<pair<int, int>> &edges) {
                // code here
    unordered_map<int, unordered_set<int>> graph;

    // Build the adjacency list
    for (const auto &edge : edges) {
        int x = edge.first;
        int y = edge.second;
        graph[x].insert(y);
        graph[y].insert(x);
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 1);

    sort(order.begin(), order.end(), [&](int a, int b) {
        return graph[a].size() < graph[b].size();
    });

    int res = INT_MAX;

    for (int i = 0; i < n; ++i) {
        int node = order[i];
        unordered_set<int> cur(graph[node]);

        for (int j = 0; j < n; ++j) {
            int neigh = order[j];
            if (cur.count(neigh) == 0) {
                cur.insert(graph[neigh].begin(), graph[neigh].end());
            }
        }

        res = min(res, static_cast<int>(cur.size()));
    }

    return res;

            }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends
